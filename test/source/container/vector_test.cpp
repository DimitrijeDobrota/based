#include "based/container/vector.hpp"

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"
#include "based/utility/move.hpp"

using namespace based::literals;  // NOLINT(*namespace*)

using based::U16;
using based::U8;
using based::Vector;

template class based::Vector<U16, U8>;

struct Dummy
{
  int x;
  Dummy(int x = 0)
      : x(x)
  {
  }
  bool operator==(const Dummy& other) const { return x == other.x; }
};

// NOLINTBEGIN(*magic-number*, *complexity*)

TEST_CASE("Vector: default and allocator constructors", "[container/Vector]")
{
  const Vector<U16, U8> vec1;
  REQUIRE(vec1.size() == 0_u8);
  REQUIRE(vec1.capacity() >= 0_u8);
  REQUIRE(vec1.empty());

  const Vector<U16, U8> vec2({});
  REQUIRE(vec2.size() == 0_u8);
  REQUIRE(vec2.capacity() >= 0_u8);
}

TEST_CASE("Vector: size/capacity/value constructors", "[container/Vector]")
{
  Vector<U16, U8> vec1(5_u8);
  REQUIRE(vec1.size() == 5_u8);
  for (U8 i = 0_u8; i < vec1.size(); ++i) {
    REQUIRE(vec1[i] == 0_u16);
  }

  Vector<U16, U8> vec2(4_u8, 42_u16);
  REQUIRE(vec2.size() == 4_u8);
  for (U8 i = 0_u8; i < vec2.size(); ++i) {
    REQUIRE(vec2[i] == 42_u16);
  }
}

TEST_CASE("Vector: iterator constructor", "[container/Vector]")
{
  const Vector<U16, U8> arr = {1_u16, 2_u16, 3_u16, 4_u16};

  Vector<U16, U8> vec(arr.begin(), arr.end());
  REQUIRE(vec.size() == 4_u8);
  for (U8 i = 0_u8; i < vec.size(); ++i) {
    REQUIRE(vec[i] == arr[i]);
  }
}

TEST_CASE("Vector: initializer_list constructor", "[container/Vector]")
{
  Vector<U16, U8> vec {1_u16, 2_u16, 3_u16};
  REQUIRE(vec.size() == 3_u8);
  REQUIRE(vec[0_u8] == 1_u16);
  REQUIRE(vec[1_u8] == 2_u16);
  REQUIRE(vec[2_u8] == 3_u16);
}

TEST_CASE("Vector: copy/move constructors and assignment", "[container/Vector]")
{
  Vector<U16, U8> vec1 {1_u16, 2_u16, 3_u16};
  Vector<U16, U8> vec2(vec1);
  REQUIRE(vec2 == vec1);

  const Vector<U16, U8> vec3(based::move(vec1));
  REQUIRE(vec3.size() == 3_u8);

  Vector<U16, U8> vec4;
  vec4 = vec2;
  REQUIRE(vec4 == vec2);

  Vector<U16, U8> vec5;
  vec5 = based::move(vec2);
  REQUIRE(vec5.size() == 3_u8);

  Vector<U16, U8> vec6;
  vec6 = {7_u16, 8_u16};
  REQUIRE(vec6.size() == 2_u8);
  REQUIRE(vec6[0_u8] == 7_u16);
  REQUIRE(vec6[1_u8] == 8_u16);
}

TEST_CASE("Vector: element access", "[container/Vector]")
{
  Vector<U16, U8> vec {10_u16, 20_u16, 30_u16};
  REQUIRE(vec[0_u8] == 10_u16);
  REQUIRE(vec[1_u8] == 20_u16);
  REQUIRE(vec[2_u8] == 30_u16);

  vec[1_u8] = 99_u16;
  REQUIRE(vec[1_u8] == 99_u16);

  REQUIRE(vec.front() == 10_u16);
  REQUIRE(vec.back() == 30_u16);

  vec.front() = 111_u16;
  vec.back() = 222_u16;
  REQUIRE(vec[0_u8] == 111_u16);
  REQUIRE(vec[2_u8] == 222_u16);

  REQUIRE(vec.data() == &vec[0_u8]);
  const auto& cvec = vec;
  REQUIRE(cvec.data() == &cvec[0_u8]);
}

TEST_CASE("Vector: iterators", "[container/Vector]")
{
  Vector<U16, U8> vec {1_u16, 2_u16, 3_u16};
  REQUIRE(*vec.begin() == 1_u16);
  REQUIRE(*(vec.end() - 1) == 3_u16);

  auto* it = vec.begin();
  REQUIRE(*(it++) == 1_u16);
  REQUIRE(*it == 2_u16);

  auto* cit = vec.cbegin();
  REQUIRE(*cit == 1_u16);

  auto rit = vec.rbegin();
  REQUIRE(*rit == 3_u16);
  ++rit;
  REQUIRE(*rit == 2_u16);

  auto crit = vec.crbegin();
  REQUIRE(*crit == 3_u16);
}

TEST_CASE("Vector: capacity and empty", "[container/Vector]")
{
  Vector<U16, U8> vec;
  REQUIRE(vec.empty());
  REQUIRE(vec.size() == 0_u8);

  vec.push_back(1_u16);
  REQUIRE(!vec.empty());
  REQUIRE(vec.size() == 1_u8);

  REQUIRE(vec.capacity() >= vec.size());
  REQUIRE(vec.max_size() >= vec.capacity());
}

TEST_CASE("Vector: push_back, pop_back, emplace_back", "[container/Vector]")
{
  Vector<Dummy, U8> vec;
  vec.push_back(Dummy(1));
  vec.push_back(Dummy(2));
  vec.push_back(Dummy(3));
  REQUIRE(vec.size() == 3_u8);
  REQUIRE(vec[2_u8].x == 3);

  vec.pop_back();
  REQUIRE(vec.size() == 2_u8);
  REQUIRE(vec.back().x == 2);

  vec.emplace_back(42);
  REQUIRE(vec.back().x == 42);
}

TEST_CASE("Vector: insert and erase", "[container/Vector]")
{
  Vector<U16, U8> vec {1_u16, 2_u16, 4_u16};
  vec.insert(vec.begin() + 2, 3_u16);
  REQUIRE(vec[2_u8] == 3_u16);

  vec.erase(vec.begin() + 2);
  REQUIRE(vec[2_u8] == 4_u16);

  vec.insert(vec.begin(), 2_u8, 7_u16);
  REQUIRE(vec[0_u8] == 7_u16);
  REQUIRE(vec[1_u8] == 7_u16);

  U16 arr[] = {8_u16, 9_u16};
  vec.insert(vec.end(), arr, arr + 2);
  REQUIRE(vec[vec.size() - 2_u8] == 8_u16);
  REQUIRE(vec[vec.size() - 1_u8] == 9_u16);

  vec.insert(vec.begin(), {5_u16, 6_u16});
  REQUIRE(vec[0_u8] == 5_u16);
  REQUIRE(vec[1_u8] == 6_u16);

  vec.erase(vec.begin(), vec.begin() + 2);
  REQUIRE(vec[0_u8] == 7_u16);
}

TEST_CASE("Vector: clear, swap", "[container/Vector]")
{
  Vector<U16, U8> vec;
  vec.push_back(42_u16);
  vec.push_back(42_u16);
  vec.push_back(42_u16);
  REQUIRE(vec.size() == 3_u8);
  for (U8 i = 0_u8; i < vec.size(); ++i) {
    REQUIRE(vec[i] == 42_u16);
  }

  vec.clear();
  REQUIRE(vec.size() == 0_u8);

  Vector<U16, U8> vec2 {1_u16, 2_u16};
  vec.swap(vec2);
  REQUIRE(vec.size() == 2_u8);
  REQUIRE(vec2.size() == 0_u8);
  REQUIRE(vec[0_u8] == 1_u16);
}

TEST_CASE("Vector: reserve, resize, shrink_to_fit", "[container/Vector]")
{
  Vector<U16, U8> vec;
  vec.reserve(10_u8);
  REQUIRE(vec.capacity() >= 10_u8);

  vec.resize(5_u8, 123_u16);
  REQUIRE(vec.size() == 5_u8);
  for (U8 i = 0_u8; i < vec.size(); ++i) {
    REQUIRE(vec[i] == 123_u16);
  }

  vec.resize(2_u8);
  REQUIRE(vec.size() == 2_u8);
}

TEST_CASE("Vector: comparison and three-way operators", "[container/Vector]")
{
  const Vector<U16, U8> vec1 {1_u16, 2_u16};
  const Vector<U16, U8> vec2 {1_u16, 2_u16};
  const Vector<U16, U8> vec3 {2_u16, 3_u16};

  REQUIRE(vec1 == vec2);
  REQUIRE_FALSE(vec1 != vec2);
  REQUIRE((vec1 < vec3));
  REQUIRE((vec3 > vec2));
  REQUIRE((vec1 <= vec2));
  REQUIRE((vec3 >= vec2));
}

TEST_CASE("Vector: move/copy elements and memory", "[container/Vector]")
{
  Vector<U16, U8> vec1 {1_u16, 2_u16, 3_u16};
  Vector<U16, U8> vec2;
  vec2 = vec1;
  REQUIRE(vec2 == vec1);

  Vector<U16, U8> vec3;
  vec3 = based::move(vec1);
  REQUIRE(vec3.size() == 3_u8);
}

TEST_CASE("Vector: edge cases and full coverage", "[container/Vector]")
{
  Vector<U16, U8> vec;
  vec.pop_back();
  REQUIRE(vec.size() == 0_u8);

  vec.insert(vec.end(), 1_u16);
  REQUIRE(vec.size() == 1_u8);
  REQUIRE(vec[0_u8] == 1_u16);

  vec.erase(vec.end());
  vec.erase(vec.end(), vec.end());

  vec.swap(vec);
  REQUIRE(vec.size() == 1_u8);

  vec.clear();
  vec.push_back(99_u16);
  REQUIRE(vec.size() == 1_u8);
  REQUIRE(vec[0_u8] == 99_u16);
}

TEST_CASE("Vector: equality and inequality", "[container/Vector]")
{
  Vector<U16, U8> vec1 {1_u16, 2_u16, 3_u16};
  Vector<U16, U8> vec2 {1_u16, 2_u16, 3_u16};
  Vector<U16, U8> vec3 {1_u16, 2_u16};
  Vector<U16, U8> vec4 {1_u16, 2_u16, 4_u16};
  Vector<U16, U8> vec_empty1;
  Vector<U16, U8> vec_empty2;

  REQUIRE(vec1 == vec2);
  REQUIRE_FALSE(vec1 != vec2);
  REQUIRE(vec1 != vec3);
  REQUIRE(vec1 != vec4);
  REQUIRE(vec_empty1 == vec_empty2);
  REQUIRE(vec1 != vec_empty1);
}

TEST_CASE("Vector: self-assignment (copy and move)", "[container/Vector]")
{
  Vector<U16, U8>  vec {1_u16, 2_u16, 3_u16};
  Vector<U16, U8>& ref = vec;
  vec = ref;
  REQUIRE(vec.size() == 3_u8);
  REQUIRE(vec[0_u8] == 1_u16);
  REQUIRE(vec[1_u8] == 2_u16);
  REQUIRE(vec[2_u8] == 3_u16);

  vec = based::move(ref);
  REQUIRE(vec.size() == 3_u8);
  REQUIRE(vec[0_u8] == 1_u16);
  REQUIRE(vec[1_u8] == 2_u16);
  REQUIRE(vec[2_u8] == 3_u16);
}

TEST_CASE("Vector: assign empty initializer_list", "[container/Vector]")
{
  Vector<U16, U8> vec {1_u16, 2_u16, 3_u16};
  vec = {};
  REQUIRE(vec.size() == 0_u8);
  REQUIRE(vec.empty());
}

TEST_CASE("Vector: reverse and const iterators", "[container/Vector]")
{
  Vector<U16, U8> vec {1_u16, 2_u16, 3_u16, 4_u16};

  U16 sum = 0_u16;
  // NOLINTNEXTLINE(*modern*)
  for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    sum += *it;
  }
  REQUIRE(sum == 10_u16);

  const Vector<U16, U8>& cvec = vec;

  U16 csum = 0_u16;
  // NOLINTNEXTLINE(*modern*)
  for (auto it = cvec.crbegin(); it != cvec.crend(); ++it) {
    csum += *it;
  }
  REQUIRE(csum == 10_u16);

  REQUIRE(*vec.rbegin() == 4_u16);
  REQUIRE(*(vec.rend() - 1) == 1_u16);
  REQUIRE(*cvec.crbegin() == 4_u16);
  REQUIRE(*(cvec.crend() - 1) == 1_u16);
}

TEST_CASE("Vector: front and back validity", "[container/Vector]")
{
  Vector<U16, U8> vec {10_u16, 20_u16, 30_u16};
  REQUIRE(vec.front() == 10_u16);
  REQUIRE(vec.back() == 30_u16);

  vec.front() = 111_u16;
  vec.back() = 222_u16;
  REQUIRE(vec[0_u8] == 111_u16);
  REQUIRE(vec[2_u8] == 222_u16);

  const Vector<U16, U8>& cvec = vec;
  REQUIRE(cvec.front() == 111_u16);
  REQUIRE(cvec.back() == 222_u16);
}

TEST_CASE("Vector: insert triggers reallocation", "[container/Vector]")
{
  Vector<U16, U8> vec;

  const U8 initial_capacity = vec.capacity();
  for (U8 i = 0_u8; i < initial_capacity; ++i) {
    vec.push_back(U16::cast(i));
  }

  vec.insert(vec.end(), 100_u16);
  REQUIRE(vec.size() == initial_capacity + 1_u8);
  REQUIRE(vec.back() == 100_u16);

  vec.insert(vec.end(), 5_u8, 200_u16);
  REQUIRE(vec.size() == initial_capacity + 6_u8);
  for (U8 i = vec.size() - 5_u8; i < vec.size(); ++i) {
    REQUIRE(vec[i] == 200_u16);
  }
}

TEST_CASE("Vector: insert at position", "[container/Vector]")
{
  Vector<U16, U8> vec {1_u16, 2_u16, 4_u16};

  auto* itr = vec.insert(vec.begin() + 2, 3_u16);
  REQUIRE(*itr == 3_u16);
  REQUIRE(vec[2_u8] == 3_u16);
  REQUIRE(vec[3_u8] == 4_u16);

  vec.insert(vec.begin(), 0_u16);
  REQUIRE(vec[0_u8] == 0_u16);
}

TEST_CASE("Vector: push_back", "[container/Vector]")
{
  Vector<U16, U8> vec;
  vec.push_back(42_u16);
  REQUIRE(vec.size() == 1_u8);
  REQUIRE(vec[0_u8] == 42_u16);

  vec.push_back(99_u16);
  REQUIRE(vec.size() == 2_u8);
  REQUIRE(vec[1_u8] == 99_u16);
}

// NOLINTEND(*magic-number*, *complexity*)