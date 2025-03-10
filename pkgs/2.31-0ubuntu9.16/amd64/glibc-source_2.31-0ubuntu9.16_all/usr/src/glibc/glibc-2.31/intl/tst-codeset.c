/* Test of bind_textdomain_codeset.
   Copyright (C) 2001-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Bruno Haible <haible@clisp.cons.org>, 2001.

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
   <https://www.gnu.org/licenses/>.  */

#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <support/check.h>

static int
do_test (void)
{
  char *s;
  int result = 0;

  unsetenv ("LANGUAGE");
  unsetenv ("OUTPUT_CHARSET");
  setlocale (LC_ALL, "de_DE.ISO-8859-1");
  textdomain ("codeset");
  bindtextdomain ("codeset", OBJPFX "domaindir");

  /* Here we expect output in ISO-8859-1.  */
  s = gettext ("cheese");
  if (strcmp (s, "K\344se"))
    {
      printf ("call 1 returned: %s\n", s);
      result = 1;
    }

  /* Here we expect output in UTF-8.  */
  bind_textdomain_codeset ("codeset", "UTF-8");
  s = gettext ("cheese");
  if (strcmp (s, "K\303\244se"))
    {
      printf ("call 2 returned: %s\n", s);
      result = 1;
    }

  /* `a with umlaut' is transliterated to `ae'.  */
  bind_textdomain_codeset ("codeset", "ASCII//TRANSLIT");
  s = gettext ("cheese");
  if (strcmp (s, "Kaese"))
    {
      printf ("call 3 returned: %s\n", s);
      result = 1;
    }

  /* Transliteration also works by default even if not set.  */
  bind_textdomain_codeset ("codeset", "ASCII");
  s = gettext ("cheese");
  if (strcmp (s, "Kaese"))
    {
      printf ("call 4 returned: %s\n", s);
      result = 1;
    }

  return result;
}

#include <support/test-driver.c>
