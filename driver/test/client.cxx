// Copyright 2013 Geoff Shannon
//
// This file is part of BWDIscratch.
//
// BWDIscratch is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// BWDIscratch is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with BWDIscratch.  If not, see <http://www.gnu.org/licenses/>.
#include <stdio.h>

#include <cstdlib>
#include <cstring>

#define BOOST_DATE_TIME_NO_LIB
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

#include <fcntl.h>
#include <sys/stat.h>

#define SHARED_MEM_NAME "bwdidriver_sm_test"
#define FIFO_NAME "bwdidriver_fifo_test"

using namespace boost::interprocess;

int main(int argc, char **argv) {
  bool debug = false;

  if (argc > 1) {
    if (0 == strcmp(argv[1], "-d")) {
      debug = true;
    }
  }

  // Access the shared_memory
  if (debug)
    printf("Accessing the shared memory...\n");

  shared_memory_object shm_obj
    (open_only,                //only open
     SHARED_MEM_NAME,          //name
     read_only);               //read-only mode

  if (debug)
    printf("Mapping the shared memory\n");

  // No need to size it since we're open only
  mapped_region region
    (shm_obj,          //Memory-mappable object
     read_only);
  if (debug)
    printf("Shared memory mapped to: %p\n", region.get_address());

  int fifofd;
  // Open FIFO
  if (debug)
    printf("Opening the FIFO\n");
  if (-1 == (fifofd = open(FIFO_NAME, O_WRONLY))) {
    perror("Failed to open the FIFO.");
  }

  char c = 'c';
  if (debug)
    printf("Writing %c to FIFO\n", c);
  if (1 != write(fifofd, &c, 1))
    perror("Couldn't write at least 1 byte to the FIFO\n");

  if (debug)
    printf("Sleeping to let memory be written\n");
  sleep(1);

  if (debug)
    printf("Checking shared_memory\n");
  // Check shared mem has been set to char
  char *mem = (char *)region.get_address();
  int size = region.get_size();
  for (int i = 0; i < size; ++i) {
    if (*mem != c)
      exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
