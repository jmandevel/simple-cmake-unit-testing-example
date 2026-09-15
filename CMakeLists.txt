cmake_minimum_required(VERSION 3.31.6)

project(
    MyProject
    DESCRIPTION "An example of an app with unit tests generated using CMake."
    VERSION 1.0.0.0
    LANGUAGES CXX
)

option(JMANDEVEL_GENERATE_TESTS "Do you want to generate tests for this target?" ON)

add_library(MyLibrary STATIC "src/lib.cpp")
set_target_properties(MyLibrary
    PROPERTIES
    OUTPUT_NAME "MyLibrary"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_include_directories(MyLibrary PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if (JMANDEVEL_GENERATE_TESTS)
    add_subdirectory(test)
endif()

add_executable(MyApp "src/main.cpp")
set_target_properties(MyLibrary
    PROPERTIES
    OUTPUT_NAME "MyApp"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
target_link_libraries(MyApp PRIVATE MyLibrary)