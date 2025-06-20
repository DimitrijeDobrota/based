#pragma once

#include "based/integral/types.hpp"

namespace based
{

template<typename D>
class Registry
{
public:
  static SizeT count;
  static D* head;
  D* prev;
  D* next;

  Registry(Registry&&) = delete;

  Registry& operator=(const Registry&) = delete;
  Registry& operator=(Registry&&) = delete;

private:
  Registry()
      : prev(nullptr)
      , next(head)
  {
    head = static_cast<D*>(this);
    ++count;
    if (next) {
      next->prev = head;
    }
  }

  Registry(const Registry& /* reg */)
      : Registry()
  {
  }

  ~Registry()
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
SizeT Registry<D>::count(0);

template<typename D>
D* Registry<D>::head(nullptr);

}  // namespace based
