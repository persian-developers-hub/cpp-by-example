# Hello World! (v1)
This is our initial introduction to C++! A simple Hello World web service.

## Building
This is a very simple project, so you can build it simply with passing
the source file to the compiler. But you need to add third party libraries
to the compilers include path too.

For example, you can build this with GCC as below:

```
$ g++ -Ithird_party/boostjson -Ithird_party/cpp-httplib src/hello-world.cpp -o hello-world
```

However, it also supports `cmake` build system. So, instead of manually
compiling the project with a compiler, you can use cmake to build this project.
CMake supports building with GNU Make, or Ninja. It also supports creating
Visual Studio solutions so that you can open and build the project using
Visual Studio.

It is also preferred to use a separate build directory.

An example of building the project using command line is given below:
```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

You might also use CMake GUI instead of using command line.
