
#include <vector>
#include <string>
#include <stdio.h>

#include "Poco/Process.h"

using Poco::Process;
using Poco::ProcessHandle;

int main(int argc, char **argv) {
  std::vector<std::string> args;

  // Start with the second arg (don't pass on the name of this
  // program)
  for (int i = 1; i < argc; ++i) {
    args.push_back(argv[i]);
  }

  ProcessHandle server = Process::launch("./test_server", args);
  ProcessHandle client = Process::launch("./test_client", args);

  int serverexit = server.wait();
  int clientexit = client.wait();

  if (0 == serverexit &&
      0 == clientexit) {
    return 0;
  } else {
    return serverexit + clientexit;
  }
}
