
#include <stdio.h>

#include <cstring>

int main(int argc, char **argv) {
  bool debug = false;

  if (argc > 1) {
    if (0 == strcmp(argv[1], "-d")) {
      debug = true;
    }
  }

  // Create named shared_memory and FIFO


}
