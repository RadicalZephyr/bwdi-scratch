
#include <stdio.h>

#include <cstdlib>
#include <cstring>

#define BOOST_DATE_TIME_NO_LIB
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

#define SHARED_MEM_NAME "bwdidriver_sm_test"
using namespace boost::interprocess;

int main(int argc, char **argv) {
  bool debug = false;

  if (argc > 1) {
    if (0 == strcmp(argv[1], "-d")) {
      debug = true;
    }
  }

  // Create named shared_memory
  if (debug)
    printf ("Creating the shared memory...\n");

  shared_memory_object shm_obj
  (create_only,                //only create
   SHARED_MEM_NAME,       //name
   read_write);                //read-write mode

  std::size_t mem_size = 1000;
  if (debug)
    printf ("Resizing the shared memory to: %ld...\n", mem_size);
  // Set the shared mem size
  shm_obj.truncate(mem_size);

  if (debug)
    printf ("Mapping the shared memory\n");

  // Map the shared_memory
  mapped_region region
  (shm_obj,          //Memory-mappable object
   read_write,       //Access mode
   0,                //Offset from the beginning of shm
   mem_size);        //Length of the region
  if (debug)
    printf ("Shared memory mapped to: %p\n", region.get_address());

  // Create FIFO

  if (debug)
    printf ("Setting shared memory to all 1's\n");
  // Go into a busy loop doing something
  std::memset(region.get_address(), 1, region.get_size());

  // Clean up
  if (debug)
    printf ("Removing the shared memory\n");
  shared_memory_object::remove(SHARED_MEM_NAME);
}
