# Simple CMake App Example

* To configure: `cmake -S . -B ./build/`
    * optional: add `-G` option with build system you want to use.
        * https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html
    * optional: to not generate unit tests add `-D` option with `JMANDEVEL_GENERATE_TESTS=OFF`
* To build: `cmake --build ./build/`
* To format lint a code file: `clang-format -i src/main.cpp`