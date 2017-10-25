#include <bits/stdc++.h>
using namespace std;

#include "geometry_3d.cc"

#include "utils/catch.hpp"

TEST_CASE("Vector3D::Dot") {
  SECTION("Returns 0 for perpendicular vectors") {
    Vector3 a {1.0, 1.0, 0.0};
    Vector3 b {-1.0, 1.0, 0.0};
    REQUIRE(a.Dot(b) == Approx(0.0));
  }
}

TEST_CASE("Plane") {
  Plane plane = Plane::FromPoints(
      {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 2.0});

  SECTION("Contains points it was constructed from") {
    REQUIRE(plane.Contains({0.0, 0.0, 0.0}));
    REQUIRE(plane.Contains({0.0, 1.0, 0.0}));
    REQUIRE(plane.Contains({0.0, 0.0, 2.0}));
  }

  SECTION("Contains points between the points it was constructed from") {
    REQUIRE(plane.Contains({0.0, 0.542, 0.893}));
  }
}
