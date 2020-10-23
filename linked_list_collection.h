//----------------------------------------------------------------------
// FILE: linked_list.h
// NAME: Matthew Moore
// DATE: September, 2020
// DESC: Implements a linked list version of the list class. Elements
//       are added by default to the end of the list via a tail pointer.
//       Implemented sorting algorithms that sort lists in ascending order.
//----------------------------------------------------------------------


#ifndef LINKED_LIST_COLLECTION_H
#define LINKED_LIST_COLLECTION_H

#include "array_list.h"
#include "linked_list.h"
#include "collection.h"

template<typename K, typename V>
class LinkedListCollection : public Collection<K,V>
{
public:

  
  // add a new key-value pair into the collection 
  void add(const K& a_key, const V& a_val);

  // remove a key-value pair from the collection
  void remove(const K& a_key);

  // find and return the value associated with the key
  // if key isn't found, returns false, otherwise true
  bool find(const K& search_key, V& the_val) const;

  // find and return each key >= k1 and <= k2 
  void find(const K& k1, const K& k2, ArrayList<K>& keys) const;
  
  // return all of the keys in the collection 
  void keys(ArrayList<K>& all_keys) const;

  // return all of the keys in ascending (sorted) order
  void sort(ArrayList<K>& all_keys_sorted) const;

  // return the number of key-value pairs in the collection
  size_t size() const;
  
private:
	LinkedList<std::pair<K,V>> kv_list;

};

template<typename K, typename V>
void LinkedListCollection<K,V>::add(const K& a_key, const V& a_val) 
{
  pair<K,V> p;
  p.first = a_key;
  p.second = a_val;
  kv_list.add(p);
}

template<typename K, typename V>
void LinkedListCollection<K,V>::remove(const K& a_key) 
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
bool LinkedListCollection<K,V>::find(const K& search_key, V& the_val) const
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
void LinkedListCollection<K,V>::find(const K& k1, const K& k2, ArrayList<K>& keys) const
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
void LinkedListCollection<K,V>::keys(ArrayList<K>& all_keys) const
{
   pair<K,V> p;
   for (int i = 0; i < kv_list.size(); ++i) {
     kv_list.get(i,p);
     all_keys.add(p.first);
  }
}

template<typename K, typename V>
void LinkedListCollection<K,V>::sort(ArrayList<K>& all_keys_sorted) const
{
  keys(all_keys_sorted);
  all_keys_sorted.quick_sort();
}

template<typename K, typename V>
size_t LinkedListCollection<K,V>::size() const
{
  size_t linked_size = 0;
  linked_size = kv_list.size();
  return linked_size;
}

#endif