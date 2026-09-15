Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.16.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(MyLibraryTest "src/test.cpp")

target_link_libraries(MyLibraryTest
    PRIVATE
        Catch2::Catch2WithMain
        MyLibrary
)
set_target_properties(MyLibraryTest
    PROPERTIES
    OUTPUT_NAME "MyLibrary_tests"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
include(CTest)
include(Catch)
catch_discover_tests(
  MyLibraryTest
  TEST_PREFIX "unittests."
  REPORTER junit
  OUTPUT_DIR ${CMAKE_BINARY_DIR}
  OUTPUT_PREFIX "unittests."
  OUTPUT_SUFFIX .xml
)