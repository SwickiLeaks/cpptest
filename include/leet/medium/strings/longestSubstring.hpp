/**
 * Longest substring without repeating characters
 *
 * 1. Sliding window and hashmap approach
 * 2. Need to match last seen index with a char in a map
 * 3. If we see a repeating character, move the start of the window past it
 *
 * Data structures needed
 * map<char, int> to store the last seen index of each char
 * two pointers "start" and "i" = start of window and i of window
 *
 * As we scan
 *      if s[i] was seen and it's index is >= start, update start
 *      update last seen index of s[i]
 *      track the max window length
 */

#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class LongestSubstring {

public:
  int lengthOfShortestSubstring(string s) {
    // Map to store char -> int mappings
    unordered_map<char, int> charMap;

    // Keep track of window size and pointers
    int maxWindowSize = 0;
    int start = 0;

    for (int i = 0; i < s.length(); ++i) {
      char c = s[i];

      if (charMap.contains(c) && charMap[c] >= start) {
        start = charMap[c] + 1;
      }

      charMap[c] = i;
      maxWindowSize = max(maxWindowSize, i - start + 1);
    }

    return maxWindowSize;
  }
};
