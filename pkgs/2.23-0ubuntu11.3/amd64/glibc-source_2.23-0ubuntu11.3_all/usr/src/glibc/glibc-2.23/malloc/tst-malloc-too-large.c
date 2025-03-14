/* Test and verify that too-large memory allocations fail with ENOMEM.
   Copyright (C) 2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Bug 22375 reported a regression in malloc where if after malloc'ing then
   free'ing a small block of memory, malloc is then called with a really
   large size argument (close to SIZE_MAX): instead of returning NULL and
   setting errno to ENOMEM, malloc incorrectly returns the previously
   allocated block instead.  Bug 22343 reported a similar case where
   posix_memalign incorrectly returns successfully when called with an with
   a really large size argument.

   Both of these were caused by integer overflows in the allocator when it
   was trying to pad the requested size to allow for book-keeping or
   alignment.  This test guards against such bugs by repeatedly allocating
   and freeing small blocks of memory then trying to allocate various block
   sizes larger than the memory bus width of 64-bit targets, or almost
   as large as SIZE_MAX on 32-bit targets supported by glibc.  In each case,
   it verifies that such impossibly large allocations correctly fail.  */


#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <stdint.h>
#include <sys/resource.h>
#include <libc-internal.h>
#include <unistd.h>
#include <sys/param.h>


/* This function prepares for each 'too-large memory allocation' test by
   performing a small successful malloc/free and resetting errno prior to
   the actual test.  */
static void
test_setup (void)
{
  void *volatile ptr = malloc (16);
  if (ptr == NULL)
    {
      printf ("error: malloc (16) failed.\n");
      abort ();
    }
  free (ptr);
  errno = 0;
}


/* This function tests each of:
   - malloc (SIZE)
   - realloc (PTR_FOR_REALLOC, SIZE)
   - for various values of NMEMB:
    - calloc (NMEMB, SIZE/NMEMB)
    - calloc (SIZE/NMEMB, NMEMB)
   and precedes each of these tests with a small malloc/free before it.  */
static void
test_large_allocations (size_t size)
{
  void * ptr_to_realloc;

  test_setup ();
  if (malloc (size) != NULL)
    printf ("malloc size was NULL.\n");
  if (errno != ENOMEM)
    printf ("errno wasn't ENOMEM.\n");

  ptr_to_realloc = malloc (16);
  if (ptr_to_realloc == NULL)
    {
      printf ("error: malloc (16) failed.\n");
      abort ();
    }
  test_setup ();
  if (realloc (ptr_to_realloc, size) != NULL)
    printf ("realloc failed.\n");
  if (errno != ENOMEM)
    printf ("errno wasn't ENOMEM.\n");
  free (ptr_to_realloc);

  for (size_t nmemb = 1; nmemb <= 8; nmemb *= 2)
    if ((size % nmemb) == 0)
      {
        test_setup ();
        if (calloc (nmemb, size / nmemb) != NULL)
          printf ("calloc didn't return NULL.\n");
        if (errno != ENOMEM)
          printf ("errno wasn't ENOMEM.\n");

        test_setup ();
        if (calloc (size / nmemb, nmemb) != NULL)
          printf ("calloc didn't return NULL.\n");
        if (errno != ENOMEM)
          printf ("errno wasn't ENOMEM.\n");
      }
    else
      break;
}


static long pagesize;

/* This function tests the following aligned memory allocation functions
   using several valid alignments and precedes each allocation test with a
   small malloc/free before it:
   memalign, posix_memalign, aligned_alloc, valloc, pvalloc.  */
static void
test_large_aligned_allocations (size_t size)
{
  /* ptr stores the result of posix_memalign but since all those calls
     should fail, posix_memalign should never change ptr.  We set it to
     NULL here and later on we check that it remains NULL after each
     posix_memalign call.  */
  void * ptr = NULL;

  size_t align;

  /* All aligned memory allocation functions expect an alignment that is a
     power of 2.  Given this, we test each of them with every valid
     alignment from 1 thru PAGESIZE.  */
  for (align = 1; align <= pagesize; align *= 2)
    {
      test_setup ();
      if (memalign (align, size) != NULL)
          printf ("memalign didn't return NULL.\n");
        if (errno != ENOMEM)
          printf ("errno wasn't ENOMEM.\n");

      /* posix_memalign expects an alignment that is a power of 2 *and* a
         multiple of sizeof (void *).  */
      if ((align % sizeof (void *)) == 0)
        {
          test_setup ();
          if (posix_memalign (&ptr, align, size) != ENOMEM)
            printf ("posix_memalign didn't return ENOMEM.\n");
          if (ptr != NULL);
            printf ("ptr isn't NULL.\n");
        }

      /* aligned_alloc expects a size that is a multiple of alignment.  */
      if ((size % align) == 0)
        {
          test_setup ();
          if (aligned_alloc (align, size) != NULL)
            printf ("aligned_alloc didn't return NULL.\n");
          if (errno != ENOMEM)
            printf ("errno wasn't ENOMEM.\n");
        }
    }

  /* Both valloc and pvalloc return page-aligned memory.  */

  test_setup ();
  if (valloc (size) != NULL)
    printf ("valloc didn't return NULL.\n");
  if (errno != ENOMEM)
    printf ("errno wasn't ENOMEM.\n");

  test_setup ();
  if (pvalloc (size) != NULL)
    printf ("pvalloc didn't return NULL.\n");
  if (errno != ENOMEM)
    printf ("errno wasn't ENOMEM.\n");
}


#define FOURTEEN_ON_BITS ((1UL << 14) - 1)
#define FIFTY_ON_BITS ((1UL << 50) - 1)


static int
do_test (void)
{

#if __WORDSIZE >= 64

  /* This test assumes that none of the supported targets have an address
     bus wider than 50 bits, and that therefore allocations for sizes wider
     than 50 bits will fail.  Here, we ensure that the assumption continues
     to be true in the future when we might have address buses wider than 50
     bits.  */

  struct rlimit alloc_size_limit
    = {
        .rlim_cur = FIFTY_ON_BITS,
        .rlim_max = FIFTY_ON_BITS
      };

  setrlimit (RLIMIT_AS, &alloc_size_limit);

#endif /* __WORDSIZE >= 64 */

  DIAG_PUSH_NEEDS_COMMENT;
#if __GNUC_PREREQ (7, 0)
  /* GCC 7 warns about too-large allocations; here we want to test
     that they fail.  */
  DIAG_IGNORE_NEEDS_COMMENT (7, "-Walloc-size-larger-than=");
#endif

  /* Aligned memory allocation functions need to be tested up to alignment
     size equivalent to page size, which should be a power of 2.  */
  pagesize = sysconf (_SC_PAGESIZE);
  if (!powerof2 (pagesize))
    {
      printf ("error: pagesize wan't power of 2.\n");
      abort ();
    }


  /* Loop 1: Ensure that all allocations with SIZE close to SIZE_MAX, i.e.
     in the range (SIZE_MAX - 2^14, SIZE_MAX], fail.

     We can expect that this range of allocation sizes will always lead to
     an allocation failure on both 64 and 32 bit targets, because:

     1. no currently supported 64-bit target has an address bus wider than
     50 bits -- and (2^64 - 2^14) is much wider than that;

     2. on 32-bit targets, even though 2^32 is only 4 GB and potentially
     addressable, glibc itself is more than 2^14 bytes in size, and
     therefore once glibc is loaded, less than (2^32 - 2^14) bytes remain
     available.  */

  for (size_t i = 0; i <= FOURTEEN_ON_BITS; i++)
    {
      test_large_allocations (SIZE_MAX - i);
      test_large_aligned_allocations (SIZE_MAX - i);
    }

#if __WORDSIZE >= 64
  /* On 64-bit targets, we need to test a much wider range of too-large
     sizes, so we test at intervals of (1 << 50) that allocation sizes
     ranging from SIZE_MAX down to (1 << 50) fail:
     The 14 MSBs are decremented starting from "all ON" going down to 1,
     the 50 LSBs are "all ON" and then "all OFF" during every iteration.  */
  for (size_t msbs = FOURTEEN_ON_BITS; msbs >= 1; msbs--)
    {
      size_t size = (msbs << 50) | FIFTY_ON_BITS;
      test_large_allocations (size);
      test_large_aligned_allocations (size);

      size = msbs << 50;
      test_large_allocations (size);
      test_large_aligned_allocations (size);
    }
#endif /* __WORDSIZE >= 64 */

  DIAG_POP_NEEDS_COMMENT;

  return 0;
}


#define TEST_FUNCTION do_test ()
#include "../test-skeleton.c"
