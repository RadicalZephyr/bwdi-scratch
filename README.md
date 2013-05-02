[BWDIscratch][3] - BroodWar Data Interface (from scratch)
==============================================

This is a "reimplementation" of the original [BWDI][1] project,
starting from scratch.  The design goals and end product will be the
same (meaning, blatantly stolen ;), but the implementation details and
strategy are wholly different.  [BWDI][1] started life as a fork of
[BWAPI][2] and it shows in a really confusing codebase, that is fairly
completely lacking in tests.  My plan with [BWDIscratch][3] is to start over
from bare bones, and implement the basic structure in vertical slices,
testing the entire time.  In addition, since I'm a Linux user by
choice, the project will be cross-platform.  The intention is NOT to
be able to run StarCraft and [BWDIscratch][3] under Linux, but solely to
enable development of the non-Windows specific portions of the code
base under Linux as well as Windows.


Testing/Code Reuse
------------------

As specific functionality from BWAPI is
implemented, the code will be copied over and tested/refactored as
needed.


Cross-Platform
--------------

This choice seems to run counter to the design philosophy expressed in
[BWDI's][1] documentation of minimal support to improve code quality.
However, I think that there will be several benefits to having the
core logic of the interface be platform agnostic.  First, different
compilers catch different bugs.  In addition, the *nix platform has
support for different tools (such as Valgrind) that can be VERY
helpful when developing a C++ application.

Second, mockist testing will allow us to abstract away the parts of
the hack that cannot be reimplemented on Linux.  This is a GOOD THING,
because that will help to refine the interface, and allow me to more
easily test the rest of the engine.

Third, the use of only mature, cross-platform libraries and
technologies will hopefully again keep the quality high, as well as
limit the possibilities.

Finally, I would never actually do this project if I had to set up a
Windows machine (or even boot into one ;) every time I wanted to work
on it.

License
-------

Copyright 2013 Geoff Shannon.

BWDIscratch is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

[1]: https://code.google.com/p/bwdi/
[2]: https://code.google.com/p/bwapi/
[3]: https://github.com/ezephyr/bwdi-scratch

