#include <catch2/catch_all.hpp>
#include <jmandevel/lib.hpp>

TEST_CASE("add()") {
    CHECK(jmandevel::add(1, 2) == 3);
    CHECK(jmandevel::add(3, 4) == 7);
}