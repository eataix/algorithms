#include <string>
#include <vector>
using namespace std;
/*
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (46.27%)
 * Total Accepted:    66.1K
 * Total Submissions: 142.8K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 *
 * Example 1:
 *
 *
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 * Example 2:
 *
 *
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 * Example 3:
 *
 *
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 */
class Solution {
public:
  int maxProduct(vector<string> &words) {
    vector<int> mask(words.size(), 0);

    int res = 0;
    for (int i = 0; i < words.size(); ++i) {
      for (char ch : words[i]) {
        mask[i] |= 1 << (ch - 'a');
      }

      for (int j = 0; j < i; ++j) {
        if (!(mask[i] & mask[j])) {
          res = max(res, static_cast<int>(words[i].size() * words[i].size()));
        }
      }
    }
    return res;
  }
};
