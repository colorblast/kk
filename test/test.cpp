#include <catch2/catch.hpp>
#include "../src/add1.cpp"
#include "../src/gh-filter.cpp"
#include <vector>
#include <utility>

SCENARIO("basic math", "[basics]") {
  GIVEN("addition works") {
    WHEN("1 + 1 = 2") {
      REQUIRE(1 + 1 == 2);
    }
  }
}

SCENARIO("add1", "[add1]") {
  GIVEN("add1 works") {
    WHEN("val = 0") {
      REQUIRE(add1(0) == 1);
    }
  }
}

SCENARIO("gh_filter", "[gh_filter]") {
  GIVEN("gh_filter works") {
    WHEN("sz weights = 5") {

      gh_filter gh = gh_filter({100, 120, 140, 160, 172});

      auto [estimates, prediction] = gh.predict_using_gain_guess(100, 5);

      REQUIRE(estimates.size() == 6);
      REQUIRE(prediction.size() == 5);
    }
  }
}
