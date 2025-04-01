/**
 * Longest palindromic substring in a given string "s"
 *
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class LongestPalindrome {

public:
  bool isPalindrome(string &s1) {
    string temp = s1;
    reverse(temp.begin(), temp.end());
    return strcmp(temp.c_str(), s1.c_str()) == 0;
  };

  string longestPalindromicSubstring(string s) {
    string result = "";

    if (s.size() <= 1)
      return s;

    for (int i = 0; i <= s.size(); i++) {
      for (int j = 0; j <= s.size(); j++) {
        string sub = s.substr(i, j);
        cout << "Substring: " << sub << endl;
        if (isPalindrome(sub) && sub.size() >= result.size()) {
          cout << "Palindrome Substring: " << sub << endl;
          result = sub;
        }
      }
    }

    return result;
  }
};
