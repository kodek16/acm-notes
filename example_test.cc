#include <bits/stdc++.h>
using namespace std;

#include "example.cc"

#include "utils/catch.hpp"

TEST_CASE("Example") {
  SECTION("Should return 42") {
    REQUIRE(foo() == 42);
  }
}
