//----------------------------------------------------------------------
// FILE: linked_list.h
// NAME: Matthew Moore
// DATE: September, 2020
// DESC: Implements a linked list version of the list class. Elements
//       are added by default to the end of the list via a tail pointer.
//       Implemented sorting algorithms that sort lists in ascending order.
//----------------------------------------------------------------------


#ifndef ARRAY_LIST_COLLECTION_H
#define ARRAY_LIST_COLLECTION_H

#include "array_list.h"
#include "linked_list.h"
#include "collection.h"

template<typename K, typename V>
class ArrayListCollection : public Collection<K,V>
{
public:
  void add(const K& a_key, const V& a_val);
  void remove(const K& a_key);
  bool find(const K& search_key, V& the_val) const;
  void find(const K& k1, const K& k2, ArrayList<K>& keys) const;
  void keys(ArrayList<K>& all_keys) const;
  void sort(ArrayList<K>& all_keys_sorted) const;
  size_t size() const;
  
private:
	ArrayList<std::pair<K,V>> kv_list;

};

template<typename K, typename V>
void ArrayListCollection<K,V>::add(const K& a_key, const V& a_val) 
{
  pair<K,V> p;
  p.first = a_key;
  p.second = a_val;
  kv_list.add(p);
}

template<typename K, typename V>
void ArrayListCollection<K,V>::remove(const K& a_key) 
{
  pair<K,V> p;
  for (size_t i = 0; i < kv_list.size(); ++i) {
	// Checking each K value in the list to see if it equals the a_key
    kv_list.get(i,p);
	if (p.first == a_key) {
	  // If true then remove the value
	  kv_list.remove(i);
	  return;
	}
  }
}

template<typename K, typename V>
bool ArrayListCollection<K,V>::find(const K& search_key, V& the_val) const
{
  pair<K,V> p;
  for (size_t i = 0; i < kv_list.size(); ++i) {
	// Traversal of the key value list
    kv_list.get(i,p);
    if (p.first == search_key) {
	  // If true then the key pair is found
	  the_val = p.second;
	  return true;
	}
  }
  // Returns false if not found
  return false;
}
template<typename K, typename V>
void ArrayListCollection<K,V>::find(const K& k1, const K& k2, ArrayList<K>& keys) const
{
  pair<K,V> p;	
	
  for (size_t i = 0; i < kv_list.size(); ++i) {
	// Traversal of the key value list
    kv_list.get(i,p);
    if (p.first >= k1 && p.first <= k2) {
	  // If true then the key pair is found
	  keys.add(p.first);
	}
  }
}
template<typename K, typename V>
void ArrayListCollection<K,V>::keys(ArrayList<K>& all_keys) const
{
  pair<K,V> p;
  for (int i = 0; i < kv_list.size(); ++i) {
    kv_list.get(i,p);
	all_keys.add(p.first);
  }
}

template<typename K, typename V>
void ArrayListCollection<K,V>::sort(ArrayList<K>& all_keys_sorted) const
{
  keys(all_keys_sorted);
  all_keys_sorted.quick_sort();
}

template<typename K, typename V>
size_t ArrayListCollection<K,V>::size() const
{
  size_t array_size = 0;
  array_size = kv_list.size();
  return array_size;
}

#endif
	