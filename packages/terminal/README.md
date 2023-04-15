# Terminal control

This directory provides basic terminal control (note. not emulation) for simple common operations. Extended as necessary.

#

Built using CMake. To add to your project, use `add_subdirectory` to add this directory to your project. This will expose the variable `Terminal_include` pointing to the include directory, and the library `Terminal_libs` referencing the libraries to link to the target.

While the project was designed around CMake, it's designed to be simple enough to incorporate into many other projects. If you want to add it to your own project, you only need to build the source files (all files ending in `c`) inside the `src` directory, then add the contents of the `include` directory to your include search paths.

While the files inside the `src/windows` and `src/linux` directories aren't directly compiled, they have kept the `.c` extension, since they do contain source code. This also helps IDEs in identifying the file type for syntax highlighting. The contents of these files are automatically pulled in by the files in the `src` directory, and shouldn't need to be pulled in manually.