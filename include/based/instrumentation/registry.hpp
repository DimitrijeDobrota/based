#pragma once

#include "based/types/types.hpp"

namespace based
{

template<typename D>
class registry
{
public:
  static size_t count;
  static D* head;
  D* prev;
  D* next;

  registry(registry&&) = delete;

  registry& operator=(const registry&) = delete;
  registry& operator=(registry&&) = delete;

private:
  registry()
      : prev(nullptr)
      , next(head)
  {
    head = static_cast<D*>(this);
    ++count;
    if (next) {
      next->prev = head;
    }
  }

  registry(const registry& /* reg */)
      : registry()
  {
  }

  ~registry()
  {
    --count;
    if (prev != nullptr) {
      prev->next = next;
    }
    if (next != nullptr) {
      next->prev = prev;
    }
    if (head == this) {
      head = next;
    }
  }

  friend D;
};

template<typename D>
size_t registry<D>::count(0);

template<typename D>
D* registry<D>::head(nullptr);

}  // namespace based
