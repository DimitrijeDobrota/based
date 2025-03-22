#pragma once

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

  const node_t& node(list_type x) const { return m_pool[x - 1]; }
  node_t& node(list_type x) { return m_pool[x - 1]; }

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

  bool is_empty(const queue_t& que) const { return is_empty(que.first); }
  queue_t queue_empty() { return {node_empty(), node_empty()}; }

  queue_t push_front(const queue_t& que, const value_type& val)
  {
    auto new_node = allocate(val, que.first);
    if (is_empty(que)) {
      return {new_node, new_node};
    }
    return {new_node, que.second};
  }

  queue_t push_back(const queue_t& que, const value_type& val)
  {
    auto new_node = allocate(val, node_empty());
    if (is_empty(que)) {
      return {new_node, new_node};
    }
    next(que.second) = new_node;
    return {new_node, new_node};
  }

  queue_t pop_front(const queue_t& que)
  {
    if (is_empty(que)) {
      return que;
    }
    queue_t ret = {next(que.first), que.second};
    free(que.first);
    return ret;
  }

  void free(const queue_t& que) { free(que.first, que.second); }
};

template<typename T, typename N>
void free_list(list_pool<T, N>& pool, typename list_pool<T, N>::list_type x)
{
  while (!pool.is_empty(x)) {
    x = pool.free(x);
  }
}

}  // namespace based
