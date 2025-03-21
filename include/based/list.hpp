#pragma once

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
      : m_free_list(empty())
  {
  }

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

  bool is_empty(list_type x) const { return x == empty(); }
  list_type empty() const { return list_type(0); }
};

template<typename T, typename N>
void free_list(list_pool<T, N>& pool, typename list_pool<T, N>::list_type x)
{
  while (!pool.is_empty(x)) {
    x = pool.free(x);
  }
}

}  // namespace based
