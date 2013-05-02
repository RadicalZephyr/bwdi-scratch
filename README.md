BroodWar Data Interface (from scratch)
==============================================

This is a "reimplementation" of the original [BWDI][1] project,
starting from scratch.  The design goals and end product will be the
same (meaning, blatantly stolen ;), but the implementation details and
strategy are wholly different.  [BWDI][1] started life as a fork of
[BWAPI][2] and it shows in a really confusing codebase, that is fairly
completely lacking in tests.  My plan with [BWDIscratch][3] is to
start over from bare bones, and implement the basic structure in
vertical slices, testing the entire time.  In addition, since I'm a
Linux user by choice, the project will be cross-platform.  The
intention is NOT to be able to run StarCraft and [BWDIscratch][3]
under Linux, but solely to enable development of the non-Windows
specific portions of the code base under Linux as well as Windows.


Installation
------------

Currently there is nothing to install.  Simply build and run.


Building
--------

BWAPIscratch has a couple of external dependencies.

- [Boost 1.53](http://www.boost.org/)
- [Protocol Buffers](https://code.google.com/p/protobuf/)

BWAPIscratch is built using CMake 2.6+ (<http://www.cmake.org>) on all
platforms.

On most systems you can build the library using the following commands

    $ mkdir build && cd build
    $ cmake ..
    $ cmake --build .

Alternatively you can point the CMake GUI tool to the CMakeLists.txt
file and generate platform specific build project or IDE workspace.


Basic Usage
-----------

Right now only testing programs exist...  Coming soon!


Documentation
-------------

TODO!


License
-------

Copyright 2013 Geoff Shannon.

BWDIscratch is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

BWDIscratch is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

[1]: https://code.google.com/p/bwdi/
[2]: https://code.google.com/p/bwapi/
[3]: https://github.com/ezephyr/bwdi-scratch

