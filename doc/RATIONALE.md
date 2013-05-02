Rationale
=========

Testing & Code Reuse
------------------

As specific functionality from BWAPI is implemented, the code will be
copied over and tested/refactored as needed.


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


