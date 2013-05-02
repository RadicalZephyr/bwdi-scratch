
#include <stdio.h>

#include <cstring>

#define BOOST_DATE_TIME_NO_LIB
#include <boost/interprocess/shared_memory_object.hpp>

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
   "bwdidriver_sm_test",       //name
   read_write);                //read-write mode

  // Create FIFO

  // Go into a busy loop doing something

  // Clean up
  shared_memory_object::remove("bwdidriver_sm_test");
}
