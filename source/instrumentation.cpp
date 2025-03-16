#include <algorithm>
#include <iterator>

#include "based/instrumentation.hpp"

namespace based
{

std::array<double, instrumented_base::op_num> instrumented_base::counts = {};

void instrumented_base::initialize(std::size_t size)
{
  std::fill(std::begin(counts), std::end(counts), 0.0);
  counts[op::n] = static_cast<double>(size);
}

}  // namespace based
