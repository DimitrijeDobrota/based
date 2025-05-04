#pragma once

// NOLINTBEGIN(*macro-usage*)

#define BASED_NUMARGS(...) (std::array{__VA_ARGS__}.size())

// clang-format off
#define BASED_GET_MACRO(                                                       \
    _0, _1, _2, _3, _4, _5, _6, _7,                                                                        \
    _8, _9, _10, _11, _12, _13, _14, _15,                                                                       \
    NAME, ...                                                                        \
) NAME
// clang-format on

// clang-format off
#define BASED_FE_0(WHAT)
#define BASED_FE_1(WHAT, X)       WHAT(X, 0)
#define BASED_FE_2(WHAT, X, ...)  WHAT(X, 1)  BASED_FE_1(WHAT, __VA_ARGS__)
#define BASED_FE_3(WHAT, X, ...)  WHAT(X, 2)  BASED_FE_2(WHAT, __VA_ARGS__)
#define BASED_FE_4(WHAT, X, ...)  WHAT(X, 3)  BASED_FE_3(WHAT, __VA_ARGS__)
#define BASED_FE_5(WHAT, X, ...)  WHAT(X, 4)  BASED_FE_4(WHAT, __VA_ARGS__)
#define BASED_FE_6(WHAT, X, ...)  WHAT(X, 5)  BASED_FE_5(WHAT, __VA_ARGS__)
#define BASED_FE_7(WHAT, X, ...)  WHAT(X, 6)  BASED_FE_6(WHAT, __VA_ARGS__)
#define BASED_FE_8(WHAT, X, ...)  WHAT(X, 7)  BASED_FE_7(WHAT, __VA_ARGS__)
#define BASED_FE_9(WHAT, X, ...)  WHAT(X, 8)  BASED_FE_8(WHAT, __VA_ARGS__)
#define BASED_FE_10(WHAT, X, ...) WHAT(X, 9)  BASED_FE_9(WHAT, __VA_ARGS__)
#define BASED_FE_11(WHAT, X, ...) WHAT(X, 10) BASED_FE_10(WHAT, __VA_ARGS__)
#define BASED_FE_12(WHAT, X, ...) WHAT(X, 11) BASED_FE_11(WHAT, __VA_ARGS__)
#define BASED_FE_13(WHAT, X, ...) WHAT(X, 12) BASED_FE_12(WHAT, __VA_ARGS__)
#define BASED_FE_14(WHAT, X, ...) WHAT(X, 13) BASED_FE_13(WHAT, __VA_ARGS__)
#define BASED_FE_15(WHAT, X, ...) WHAT(X, 14) BASED_FE_14(WHAT, __VA_ARGS__)
// clang-format on

#define BASED_FOREACH(action, ...)                                                                                                                                                                                                        \
  BASED_GET_MACRO(_0, __VA_ARGS__, BASED_FE_15, BASED_FE_14, BASED_FE_13, BASED_FE_12, BASED_FE_11, BASED_FE_10, BASED_FE_9, BASED_FE_8, BASED_FE_7, BASED_FE_6, BASED_FE_5, BASED_FE_4, BASED_FE_3, BASED_FE_2, BASED_FE_1, BASED_FE_0)( \
      action, __VA_ARGS__                                                                                                                                                                                                                 \
  )

// clang-format off
#define BASED_FE_0_1(First, WHAT)
#define BASED_FE_1_1(First, WHAT, X)       WHAT(First, X, 0)
#define BASED_FE_2_1(First, WHAT, X, ...)  WHAT(First, X, 1)  BASED_FE_1_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_3_1(First, WHAT, X, ...)  WHAT(First, X, 2)  BASED_FE_2_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_4_1(First, WHAT, X, ...)  WHAT(First, X, 3)  BASED_FE_3_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_5_1(First, WHAT, X, ...)  WHAT(First, X, 4)  BASED_FE_4_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_6_1(First, WHAT, X, ...)  WHAT(First, X, 5)  BASED_FE_5_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_7_1(First, WHAT, X, ...)  WHAT(First, X, 6)  BASED_FE_6_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_8_1(First, WHAT, X, ...)  WHAT(First, X, 7)  BASED_FE_7_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_9_1(First, WHAT, X, ...)  WHAT(First, X, 8)  BASED_FE_8_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_10_1(First, WHAT, X, ...) WHAT(First, X, 9)  BASED_FE_9_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_11_1(First, WHAT, X, ...) WHAT(First, X, 10) BASED_FE_10_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_12_1(First, WHAT, X, ...) WHAT(First, X, 11) BASED_FE_11_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_13_1(First, WHAT, X, ...) WHAT(First, X, 12) BASED_FE_12_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_14_1(First, WHAT, X, ...) WHAT(First, X, 13) BASED_FE_13_1(First, WHAT, __VA_ARGS__)
#define BASED_FE_15_1(First, WHAT, X, ...) WHAT(First, X, 14) BASED_FE_14_1(First, WHAT, __VA_ARGS__)
// clang-format on

#define BASED_FOREACH_1(First, action, ...)                                                                                                                                                                                                                       \
  BASED_GET_MACRO(_0, __VA_ARGS__, BASED_FE_15_1, BASED_FE_14_1, BASED_FE_13_1, BASED_FE_12_1, BASED_FE_11_1, BASED_FE_10_1, BASED_FE_9_1, BASED_FE_8_1, BASED_FE_7_1, BASED_FE_6_1, BASED_FE_5_1, BASED_FE_4_1, BASED_FE_3_1, BASED_FE_2_1, BASED_FE_1_1, BASED_FE_0_1)( \
      First, action, __VA_ARGS__                                                                                                                                                                                                                                  \
  )

// clang-format off
#define BASED_FE_0_2(First, Second, WHAT)
#define BASED_FE_1_2(First, Second, WHAT, X)       WHAT(First, Second, X, 0)
#define BASED_FE_2_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 1)  BASED_FE_1_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_3_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 2)  BASED_FE_2_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_4_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 3)  BASED_FE_3_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_5_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 4)  BASED_FE_4_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_6_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 5)  BASED_FE_5_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_7_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 6)  BASED_FE_6_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_8_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 7)  BASED_FE_7_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_9_2(First, Second, WHAT, X, ...)  WHAT(First, Second, X, 8)  BASED_FE_8_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_10_2(First, Second, WHAT, X, ...) WHAT(First, Second, X, 9)  BASED_FE_9_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_11_2(First, Second, WHAT, X, ...) WHAT(First, Second, X, 10) BASED_FE_10_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_12_2(First, Second, WHAT, X, ...) WHAT(First, Second, X, 11) BASED_FE_11_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_13_2(First, Second, WHAT, X, ...) WHAT(First, Second, X, 12) BASED_FE_12_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_14_2(First, Second, WHAT, X, ...) WHAT(First, Second, X, 13) BASED_FE_13_2(First, Second, WHAT, __VA_ARGS__)
#define BASED_FE_15_2(First, Second, WHAT, X, ...) WHAT(First, Second, X, 14) BASED_FE_14_2(First, Second, WHAT, __VA_ARGS__)
// clang-format on

#define BASED_FOREACH_2(First, Second, action, ...)                                                                                                                                                                                                                       \
  BASED_GET_MACRO(_0, __VA_ARGS__, BASED_FE_15_2, BASED_FE_14_2, BASED_FE_13_2, BASED_FE_12_2, BASED_FE_11_2, BASED_FE_10_2, BASED_FE_9_2, BASED_FE_8_2, BASED_FE_7_2, BASED_FE_6_2, BASED_FE_5_2, BASED_FE_4_2, BASED_FE_3_2, BASED_FE_2_2, BASED_FE_1_2, BASED_FE_0_2)( \
      First, Second, action, __VA_ARGS__                                                                                                                                                                                                                                  \
  )

// NOLINTEND(*macro-usage*)
