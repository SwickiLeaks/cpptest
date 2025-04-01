#include <bits/stdc++.h>

using namespace std;

class InMemoryKVStore {
  // Store will be a map of string -> string
  unordered_map<string, string> store;

  // Keep track of transactions using stack of maps(string -> string)
  stack<unordered_map<string, optional<string>>> transactions;

public:
  /**
   * If in a transaction, we look at the top transaction layer.
   * If that key hasn’t been modified in this layer before, store its old
   * value so we can revert later. Always update the store with the new value.
   */
  void set(const string &key, const string &value) {
    if (!transactions.empty()) {
      auto &current = transactions.top();
      if (!current.contains(key)) {
        // store previous value for rollback
        current[key] = store.contains(key) ? optional(store[key]) : nullopt;
      }
    }
    store[key] = value;
  }

  /**
   * Simple key lookup in the store.
   * No transaction logic needed here since store always reflects the latest
   * state.
   */
  void get(const string &key) const {
    auto it = store.find(key);
    if (it != store.end()) {
      cout << it->second << endl;
    } else {
      cout << "NULL" << endl;
    }
  }

  /**
   * Adds a new empty map to the top of the transaction stack.
   * Each transaction layer tracks only keys modified in that layer and their
   * original values.
   */
  void begin() { transactions.emplace(); }

  /**
   * If no transaction is active → output NO TRANSACTION.
   * Otherwise, we discard all rollback state. Since store is always updated
   * during SET, everything is already committed.
   */
  void commit() {
    if (transactions.empty()) {
      cout << "NO TRANSACTION" << endl;
      return;
    }

    transactions = {}; // apply everything, changes already in store
  }

  /**
   * If no transaction is active → output NO TRANSACTION.
   * Otherwise, pop the latest transaction layer.
   * For each modified key:
   * If the original value existed, restore it.
   * If the key didn’t exist before (nullopt), erase it.
   * This "undoes" the changes from that layer only.
   */
  void rollback() {
    if (transactions.empty()) {
      cout << "NO TRANSACTION" << endl;
      return;
    }

    auto changes = transactions.top();
    transactions.pop();

    for (const auto &[key, oldValue] : changes) {
      if (oldValue.has_value()) {
        store[key] = oldValue.value();
      } else {
        store.erase(key);
      }
    }
  }
};