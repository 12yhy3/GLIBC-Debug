/* Optimized strncpy/stpncpy implementation for PowerPC64/POWER8.
   Copyright (C) 2015-2018 Free Software Foundation, Inc.
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

#include <sysdep.h>

#ifdef USE_AS_STPNCPY
# ifndef STPNCPY
#   define FUNC_NAME __stpncpy
# else
#   define FUNC_NAME STPNCPY
# endif
#else
# ifndef STRNCPY
#  define FUNC_NAME strncpy
# else
#  define FUNC_NAME STRNCPY
# endif
#endif  /* !USE_AS_STPNCPY  */

#ifndef MEMSET
/* For builds without IFUNC support, local calls should be made to internal
   GLIBC symbol (created by libc_hidden_builtin_def).  */
# ifdef SHARED
#  define MEMSET_is_local
#  define MEMSET   __GI_memset
# else
#  define MEMSET   memset
# endif
#endif

#define FRAMESIZE (FRAME_MIN_SIZE+48)

/* Implements the function

   char * [r3] strncpy (char *dest [r3], const char *src [r4], size_t n [r5])

   o