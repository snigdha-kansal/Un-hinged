//
//  RadixTree.h
//  CS32_4
//
//  Created by Snigdha Kansal on 3/4/22.
//

#ifndef RadixTree_h
#define RadixTree_h
#include <map>
#include <string>

using namespace std;

template <typename ValueType>
class RadixTree
{
public:
    RadixTree();
    ~RadixTree();
    void insert(string key, const ValueType &value);
    ValueType *search(string key) const;

private:
    map<string, ValueType> m_map;
};

template <typename ValueType>
RadixTree<ValueType>::RadixTree()
{
}

template <typename ValueType>
RadixTree<ValueType>::~RadixTree()
{
}

template <typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType &value)
{
    m_map.insert_or_assign(key, value);
}

template <typename ValueType>
ValueType *RadixTree<ValueType>::search(string key) const
{
    auto it = m_map.find(key);
    if (it == m_map.end())
    {
        return nullptr;
    }

    return const_cast<ValueType *>(&(it->second));
}

#endif /* RadixTree_h */