#include <algorithm>
#include <iterator>

#include "based/instrumentation.hpp"

namespace based
{

std::array<double, instrumented_base::number_ops> instrumented_base::counts =
    {};

void instrumented_base::initialize(std::size_t size)
{
  std::fill(std::begin(counts), std::end(counts), 0.0);
  counts[n] = static_cast<double>(size);
}

}  // namespace based
