#pragma once

#include <cassert>
#include <vector>

#include "based/concept/is/same.hpp"
#include "based/integral/types.hpp"

namespace based
{

template<typename T, typename N>
// T semiregular
// N integral
class ListPool
{
public:
  using value_type = T;
  using ListType = N;

private:
  struct NodeT
  {
    value_type value {};
    ListType next;
  };

  std::vector<NodeT> m_pool {};
  ListType m_free_list;

  [[nodiscard]] const NodeT& node(ListType x) const
  {
    assert(x != ListType(0));
    return m_pool[(x - ListType(1)).value];
  }

  [[nodiscard]] NodeT& node(ListType x)
  {
    assert(x != ListType(0));
    return m_pool[(x - ListType(1)).value];
  }

  [[nodiscard]] ListType new_node()
  {
    m_pool.push_back(NodeT());
    return ListType {static_cast<ListType::basic_type>(m_pool.size())};
  }

public:
  ListPool()
      : m_free_list(node_empty())
  {
  }

  struct Iterator
  {
    using IteratorCategory = std::forward_iterator_tag;
    using difference_type = ListPool::ListType;
    using value_type = ListPool::value_type;
    using reference = value_type&;
    using pointer = value_type*;

    Iterator() = default;

    explicit Iterator(ListPool& pool)
        : Iterator(pool, pool.node_empty())
    {
    }

    Iterator(ListPool& pool, ListPool::ListType node)
        : m_pool(&pool)
        , m_node(node)
    {
    }

    reference operator*() const { return m_pool->value(m_node); }
    pointer operator->() const { return &**this; }

    Iterator& operator++()
    {
      m_node = m_pool->next(m_node);
      return *this;
    }

    Iterator operator++(int)
    {
      Iterator tmp(*this);
      ++*this;
      return tmp;
    }

    friend bool operator==(const Iterator& x, const Iterator& y)
    {
      assert(x.m_pool == y.m_pool);
      return x.m_node == y.m_node;
    }

    friend bool operator!=(const Iterator& x, const Iterator& y)
    {
      return !(x == y);
    }

  private:
    ListPool* m_pool;
    ListPool::ListType m_node;
  };

  struct ConstIterator
  {
    using IteratorCategory = std::forward_iterator_tag;
    using difference_type = ListPool::ListType;
    using value_type = ListPool::value_type;
    using reference = const value_type&;
    using pointer = const value_type*;

    ConstIterator() = default;

    explicit ConstIterator(const ListPool& pool)
        : ConstIterator(pool, pool.node_empty())
    {
    }

    ConstIterator(const ListPool& pool, ListPool::ListType node)
        : m_pool(&pool)
        , m_node(node)
    {
    }

    reference operator*() const { return m_pool->value(m_node); }
    pointer operator->() const { return &**this; }

    ConstIterator& operator++()
    {
      m_node = m_pool->next(m_node);
      return *this;
    }

    ConstIterator operator++(int)
    {
      ConstIterator tmp(*this);
      ++*this;
      return tmp;
    }

    friend bool operator==(const ConstIterator& x, const ConstIterator& y)
    {
      assert(x.m_pool == y.m_pool);
      return x.m_node == y.m_node;
    }

    friend bool operator!=(const ConstIterator& x, const ConstIterator& y)
    {
      return !(x == y);
    }

  private:
    const ListPool* m_pool;
    ListPool::ListType m_node;
  };

  [[nodiscard]] bool is_empty(ListType x) const { return x == node_empty(); }
  [[nodiscard]] ListType node_empty() const { return ListType(0); }

  [[nodiscard]] const value_type& value(ListType x) const
  {
    return node(x).value;
  }
  [[nodiscard]] value_type& value(ListType x) { return node(x).value; }

  [[nodiscard]] const ListType& next(ListType x) const { return node(x).next; }
  [[nodiscard]] ListType& next(ListType x) { return node(x).next; }

  ListType free(ListType x)
  {
    const ListType ret = next(x);
    next(x) = m_free_list;
    m_free_list = x;
    return ret;
  }

  ListType free(
      ListType front,  // NOLINT(*swappable*)
      ListType back
  )
  {
    if (is_empty(front)) {
      return node_empty();
    }

    const ListType ret = next(back);
    next(back) = m_free_list;
    m_free_list = front;
    return ret;
  }

  [[nodiscard]] ListType allocate(const value_type& val, ListType tail)
  {
    ListType new_list = m_free_list;

    if (is_empty(new_list)) {
      new_list = new_node();
    } else {
      m_free_list = next(m_free_list);
    }

    value(new_list) = val;
    next(new_list) = tail;
    return new_list;
  }

  using QueueT = std::pair<ListType, ListType>;

  [[nodiscard]] bool is_empty(const QueueT& queue) const
  {
    return is_empty(queue.first);
  }
  [[nodiscard]] QueueT queue_empty() { return {node_empty(), node_empty()}; }

  [[nodiscard]] QueueT push_front(const QueueT& queue, const value_type& val)
  {
    auto new_node = allocate(val, queue.first);
    if (is_empty(queue)) {
      return {new_node, new_node};
    }
    return {new_node, queue.second};
  }

  [[nodiscard]] QueueT push_back(const QueueT& queue, const value_type& val)
  {
    auto new_node = allocate(val, node_empty());
    if (is_empty(queue)) {
      return {new_node, new_node};
    }
    next(queue.second) = new_node;
    return {queue.first, new_node};
  }

  [[nodiscard]] QueueT pop_front(const QueueT& queue)
  {
    if (is_empty(queue)) {
      return queue;
    }
    QueueT ret = {next(queue.first), queue.second};
    free(queue.first);
    return ret;
  }

  void free(const QueueT& queue) { free(queue.first, queue.second); }
};

template<typename T, typename N>
void free_list(ListPool<T, N>& pool, typename ListPool<T, N>::ListType x)
{
  while (!pool.is_empty(x)) {
    x = pool.free(x);
  }
}

}  // namespace based
