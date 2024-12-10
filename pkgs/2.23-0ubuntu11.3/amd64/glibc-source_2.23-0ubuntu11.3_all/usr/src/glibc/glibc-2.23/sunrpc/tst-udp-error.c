/* Check for use-after-free in clntudp_call (bug 21115).
   Copyright (C) 2017 Free Software Foundation, Inc.
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

#include <netinet/in.h>
#include <rpc/clnt.h>
#include <rpc/svc.h>
#include <unistd.h>

static int
do_test (void)
{
  /* Obtain a likely-unused port number.  */
  struct sockaddr_in sin =
    {
      .sin_family = AF_INET,
      .sin_addr.s_addr = htonl (INADDR_LOOPBACK),
    };
  {
    int fd = socket (AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
    if (fd < 0)
    {
      puts ("couldn't get socket");
      return 1;
    }
    if (bind (fd, (struct sockaddr *) &sin, sizeof (sin)) != 0)
    {
      puts ("couldn't bind socket");
      return 1;
    }
    socklen_t sinlen = sizeof (sin);
    if(getsockname (fd, (struct sockaddr *) &sin, &sinlen) != 0)
    {
      puts ("couldn't getsockname");
      return 1;
    }
    /* Close the socket, so that we will receive an error below.  */
    close (fd);
  }

  int sock = RPC_ANYSOCK;
  CLIENT *clnt = clntudp_create
    (&sin, 1, 2, (struct timeval) { 1, 0 }, &sock);
  if (clnt == NULL)
    {
      puts ("clnt was NULL");
      return 1;
    }
  if (clnt_call (clnt, 3,
                 (xdrproc_t) xdr_void, NULL,
                 (xdrproc_t) xdr_void, NULL,
                 ((struct timeval) { 3, 0 }))
               != RPC_CANTRECV)
    {
      puts ("clnt_call didn't return RPC_CANTRECV");
    }
  clnt_destroy (clnt);

  return 0;
}

#define TEST_FUNCTION do_test ()
#include "../test-skeleton.c"
