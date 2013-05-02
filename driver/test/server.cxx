
#include <stdio.h>

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
  shared_memory_object shm_obj
  (create_only,                //only create
   SHARED_MEM_NAME,       //name
   read_write);                //read-write mode

  std::size_t mem_size = 1000;
  // Set the shared mem size
  shm_obj.truncate(mem_size);

  // Map the shared_memory
  mapped_region region
  (shm_obj,          //Memory-mappable object
   read_write,       //Access mode
   0,                //Offset from the beginning of shm
   mem_size);        //Length of the region

  // Create FIFO

  // Go into a busy loop doing something

  // Clean up
  shared_memory_object::remove(SHARED_MEM_NAME);
}
