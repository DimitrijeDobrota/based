#pragma once

#include <cassert>
#include <functional>
#include <utility>
#include <vector>

namespace based
{

template<typename T, typename N>
// T semiregular
// N integral
class list_pool
{
public:
  using value_type = T;
  using list_type = N;

private:
  struct node_t
  {
    value_type value;
    list_type next = list_type(0);
  };

  std::vector<node_t> m_pool;
  list_type m_free_list;

  const node_t& node(list_type x) const
  {
    assert(x != 0);
    return m_pool[x - 1];
  }

  node_t& node(list_type x)
  {
    assert(x != 0);
    return m_pool[x - 1];
  }

  list_type new_node()
  {
    m_pool.push_back(node_t());
    return list_type(m_pool.size());
  }

public:
  list_pool()
      : m_free_list(node_empty())
  {
  }

  struct iterator
  {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = list_pool::list_type;
    using value_type = list_pool::value_type;
    using reference = value_type&;
    using pointer = value_type*;

    iterator() = default;

    explicit iterator(list_pool& pool)
        : iterator(pool, pool.node_empty())
    {
    }

    iterator(list_pool& pool, list_pool::list_type node)
        : m_pool(pool)
        , m_node(node)
    {
    }

    reference operator*() const { return m_pool.get().value(m_node); }
    pointer operator->() const { return &**this; }

    iterator& operator++()
    {
      m_node = m_pool.get().next(m_node);
      return *this;
    }

    iterator operator++(int)
    {
      iterator tmp(*this);
      ++*this;
      return tmp;
    }

    friend bool operator==(const iterator& x, const iterator& y)
    {
      // assert(x.m_pool == y.m_pool);
      return x.m_node == y.m_node;
    }

    friend bool operator!=(const iterator& x, const iterator& y)
    {
      return !(x == y);
    }

  private:
    std::reference_wrapper<list_pool> m_pool;
    list_pool::list_type m_node;
  };

  bool is_empty(list_type x) const { return x == node_empty(); }
  list_type node_empty() const { return list_type(0); }

  const value_type& value(list_type x) const { return node(x).value; }
  value_type& value(list_type x) { return node(x).value; }

  const list_type& next(list_type x) const { return node(x).next; }
  list_type& next(list_type x) { return node(x).next; }

  list_type free(list_type x)
  {
    const list_type ret = next(x);
    next(x) = m_free_list;
    m_free_list = x;
    return ret;
  }

  list_type free(
      list_type front,  // NOLINT bugprone-easily-swappable-parameters
      list_type back)
  {
    if (is_empty(front)) {
      return node_empty();
    }

    const list_type ret = next(back);
    next(back) = m_free_list;
    m_free_list = front;
    return ret;
  }

  list_type allocate(const value_type& val, list_type tail)
  {
    list_type new_list = m_free_list;

    if (is_empty(new_list)) {
      new_list = new_node();
    } else {
      m_free_list = next(m_free_list);
    }

    value(new_list) = val;
    next(new_list) = tail;
    return new_list;
  }

  using queue_t = std::pair<list_type, list_type>;

  bool is_empty(const queue_t& queue) const { return is_empty(queue.first); }
  queue_t queue_empty() { return {node_empty(), node_empty()}; }

  queue_t push_front(const queue_t& queue, const value_type& val)
  {
    auto new_node = allocate(val, queue.first);
    if (is_empty(queue)) {
      return {new_node, new_node};
    }
    return {new_node, queue.second};
  }

  queue_t push_back(const queue_t& queue, const value_type& val)
  {
    auto new_node = allocate(val, node_empty());
    if (is_empty(queue)) {
      return {new_node, new_node};
    }
    next(queue.second) = new_node;
    return {queue.first, new_node};
  }

  queue_t pop_front(const queue_t& queue)
  {
    if (is_empty(queue)) {
      return queue;
    }
    queue_t ret = {next(queue.first), queue.second};
    free(queue.first);
    return ret;
  }

  void free(const queue_t& queue) { free(queue.first, queue.second); }
};

template<typename T, typename N>
void free_list(list_pool<T, N>& pool, typename list_pool<T, N>::list_type x)
{
  while (!pool.is_empty(x)) {
    x = pool.free(x);
  }
}

}  // namespace based
