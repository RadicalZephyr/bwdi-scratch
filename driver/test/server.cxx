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

  struct shm_remove
  {
    bool m_debug;
    shm_remove(bool debug):m_debug(debug) {}
    ~shm_remove(){
      if (m_debug)
        printf("Removing the shared memory\n");
      shared_memory_object::remove(SHARED_MEM_NAME);
    }
  } shm_remover(debug);

  // Create named shared_memory
  if (debug)
    printf("Creating the shared memory...\n");

  shared_memory_object shm_obj
    (create_only,                //only create
     SHARED_MEM_NAME,            //name
     read_write);                //read-write mode

  std::size_t mem_size = 1000;
  if (debug)
    printf("Resizing the shared memory to: %ld...\n", mem_size);
  // Set the shared mem size
  shm_obj.truncate(mem_size);

  if (debug)
    printf("Mapping the shared memory\n");

  // Map the shared_memory
  mapped_region region
  (shm_obj,          //Memory-mappable object
   read_write,       //Access mode
   0,                //Offset from the beginning of shm
   mem_size);        //Length of the region
  if (debug)
    printf("Shared memory mapped to: %p\n", region.get_address());

  // Create FIFO
  if (debug)
    printf("Creating the FIFO\n");

  if (0 != mkfifoat(AT_FDCWD, FIFO_NAME, 0666)) {
    perror("Failed to create the FIFO\n");
  }

  struct fifo_remove {
    bool m_debug;
    fifo_remove(bool debug):m_debug(debug) {}
    ~fifo_remove(){
      if (m_debug)
        printf("Removing the FIFO\n");
      unlink(FIFO_NAME);
    }
  } fifo_remover(debug);

  int fifofd;
  // Open FIFO
  if (debug)
    printf("Opening the FIFO\n");
  if (-1 == (fifofd = open(FIFO_NAME, O_RDONLY))) {
    perror("Failed to open the FIFO.");
  }

  struct fifo_close{
    bool m_debug;
    int m_fd;
    fifo_close(int fd, bool debug):m_debug(debug), m_fd(fd) {}
    ~fifo_close() {
      if (m_debug)
        printf("Closing the FIFO\n");
      close(m_fd);
    }
  } fifo_closer(fifofd, debug);

  if (debug)
    printf("Waiting to read from FIFO...\n");
  char c;
  if (1 != read(fifofd, &c, 1))
    perror("Couldn't read at least 1 byte from FIFO\n");
  if (debug)
    printf("Read %c from the FIFO\n", c);

  if (debug)
    printf("Setting shared memory to %c\n", c);
  std::memset(region.get_address(), c, region.get_size());

  // Clean up is handled automatically by the destruction of our
  // temporary structs
}
