#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <stdexcept>

#include <catch2/catch_test_macros.hpp>

#include "based/template.hpp"

// NOLINTBEGIN(*cognitive-complexity*)

struct set
{
  explicit set(int& val)
      : m_val(&val)
  {
  }

  void operator()() const { *m_val = 1; }

private:
  int* m_val;
};

template class based::scopeguard<set>;

TEST_CASE("manual", "[template/scopeguard]")
{
  SECTION("commit")
  {
    int test = 0;
    try {
      based::scopeguard guard = set(test);
      guard.commit();
    } catch (...) {
      REQUIRE(false);
    }
    REQUIRE(test == 1);
  }

  // breaks coverage for some reason
  SECTION("no commit")
  {
    int test = 0;
    try {
      based::scopeguard guard = set(test); // NOLINT(*const*)
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 0);
  }
}

TEST_CASE("on success", "[template/scopeguard]")
{
  SECTION("success")
  {
    int test = 0;
    try {
      const based::scopeguard_success guard = set(test);
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 1);
  }

  // breaks coverage for some reason
  SECTION("failure")
  {
    int test = 0;
    try {
      const based::scopeguard_success guard = set(test);
      throw std::runtime_error {"should not leak"};
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 0);
  }
}

TEST_CASE("on failure", "[template/scopeguard]")
{
  SECTION("success")
  {
    int test = 0;
    try {
      const based::scopeguard_failure guard = set(test);
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 0);
  }

  // breaks coverage for some reason
  SECTION("failure")
  {
    int test = 0;
    try {
      const based::scopeguard_failure guard = set(test);
      throw std::runtime_error {"should not leak"};
    } catch (...) {
      REQUIRE(true);
    }
    REQUIRE(test == 1);
  }
}

TEST_CASE("exit", "[template/scopeguard]")
{
  SECTION("success")
  {
    int test = 0;
    try {
      const based::scopeguard_exit guard = set(test);
    } catch (...) {
      REQUIRE(false);
    }
    REQUIRE(test == 1);
  }

  // breaks coverage for some reason
  SECTION("failure")
  {
    int test = 0;
    try {
      const based::scopeguard_exit guard = set(test);
      throw std::runtime_error {"should not leak"};
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 1);
  }
}

// NOLINTEND(*cognitive-complexity*)
