/**
 * Ensure encoded values are
 *      1. Unique mapping.  No two words map to the same encoding
 *      2. If words are length <= 3, return the word?
 *      2. Encoding rule = first letter + numChars between first/last + last
 *         letter
 */

/**
 * Plan
 *     Iterate through list of words
 *     Apply encoding rule to each
 *     Store in map from encoded string to original word
 *     TODO:  Determine what to do on event of collision
 *              If collision detected, take the left most char from encoded
 * portion and extract it to the left.
 */

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class CustomEncoder {
public:
  string encode_word(const string &word, int eCount = 0) {
    if (word.length() <= 2)
      return word;

    int midCount = word.length() - 2 - eCount;
    int frontCount = 1 + eCount;

    return word.substr(0, frontCount) + to_string(midCount) + word.back();
  }

  unordered_map<string, string> encode_words(vector<string> &words) {
    unordered_map<string, vector<string>> encoding_bucket;
    unordered_map<string, string> final_encodings;

    // Apply encoding for each word and place in the bucket
    for (const auto &word : words) {
      auto encoded = encode_word(word);
      encoding_bucket[encoded].push_back(word);
    }

    // Iterate over the bucket and check emplace any 1/1 encoded pairs
    // into the final encodings
    // Then handle conflict resolution for the rest
    for (auto &[encodedWord, wordList] : encoding_bucket) {
      if (wordList.size() == 1) {
        final_encodings[encodedWord] = wordList[0];
        continue;
      }

      // Conflict resolution.  Encoding has multiple words associated with it
      map<string, string> resolved;
      int eCount = 1;

      // Iterate over wordList and resolvedList until all encodings resolved
      while (resolved.size() < wordList.size()) {
        unordered_map<string, string> temp;
        unordered_set<string> conflicts;

        // Encode each word with new eCount value
        for (const auto &word : wordList) {
          string newEnc = encode_word(word, eCount);
          if (temp.count(newEnc)) {
            conflicts.insert(newEnc);
          }
          temp[newEnc] = word;
        }

        // Only keep the non-conflicted encodings
        for (const auto &[enc, word] : temp) {
          if (!conflicts.count(enc)) {
            resolved[enc] = word;
          }
        }

        eCount++;
      }

      // Insert the resolved list of encodings into the final encodings
      final_encodings.insert(resolved.begin(), resolved.end());
    }

    // Return the final encodings
    return final_encodings;
  }
};