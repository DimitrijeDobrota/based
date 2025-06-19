#pragma once

#include <cassert>

#define BASED_ASSERT assert

/*
#ifdef NDEBUG
#  define BASED_ASSERT(EX)
#else
#  define BASED_ASSERT(EX)                                                     \
    (void)((EX) || (based::detail::assert(#EX, __FILE__, __LINE__), 0))
#endif

namespace based::detail
{

[[noreturn]] constexpr void assert(const char* msg, const char* file, int line)
{
  throw "assertion failsed";
}

}  // namespace based::detail
*/
