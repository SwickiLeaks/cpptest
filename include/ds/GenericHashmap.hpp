// GenericHashmap.hpp
#pragma once

#include <optional>
#include <unordered_map>

using namespace std;

/**
 * 1. Hashmaps
 *
 * Hashmap implementations come in a few flavors
 * std::unordered_map
 * std::unordered_multimap (allows duplicate keys)
 */
template <typename K, typename V> class GenericHashmap {
private:
  unordered_map<K, V> map;

public:
  // Iterator access
  auto begin() { return map.begin(); }
  auto end() { return map.end(); }

  auto begin() const { return map.begin(); }
  auto end() const { return map.end(); }

  auto cbegin() const { return map.cbegin(); }
  auto cend() const { return map.cend(); }

  /**
   * @brief Insert value with key
   */
  void insert(const K &key, const V &value) { map[key] = value; }

  /**
   * @brief Optional getter for hashmap value using key
   */
  optional<V> get(const K &key) const {
    if (auto it = map.find(key); it != map.end()) {
      return it->second;
    }
    return nullopt;
  }

  /**
   * @brief Checks if key exists in the map
   */
  bool contains(const K &key) const { return map.contains(key); }

  /**
   * @brief Removes entry from map
   */
  void remove(const K &key) { map.erase(key); }
};