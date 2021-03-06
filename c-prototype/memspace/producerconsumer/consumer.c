/******************************************************************************
 *    memspaces - tuple spaces in shared memory                               *
 *    Copyright (C) 2017  Andreas Grapentin                                   *
 *                                                                            *
 *    This program is free software: you can redistribute it and/or modify    *
 *    it under the terms of the GNU General Public License as published by    *
 *    the Free Software Foundation, either version 3 of the License, or       *
 *    (at your option) any later version.                                     *
 *                                                                            *
 *    This program is distributed in the hope that it will be useful,         *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *    GNU General Public License for more details.                            *
 *                                                                            *
 *    You should have received a copy of the GNU General Public License       *
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ******************************************************************************/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <libmemspace/libmemspace.h>


int
main (void)
{
  SPACE *space = memspace_open("/ProducerConsumerExample");
  if (space == NULL)
    {
      perror("memspace_open");
      exit(-1);
    }

  unsigned int i = 0;

  int res;
  while (1)
    {
      unsigned int data;
      res = memspace_read(space, "%u%?u", i++, &data);
      if (res)
        {
          perror("memspace_read");
          exit(res);
        }

      printf("%u: %u\n", i, data);
    }

  return 0;
}
