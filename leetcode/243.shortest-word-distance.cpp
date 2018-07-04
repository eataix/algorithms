#include <string>
#include <vector>
using namespace std;
/*
 * [243] Shortest Word Distance
 *
 * https://leetcode.com/problems/shortest-word-distance/description/
 *
 * algorithms
 * Easy (54.04%)
 * Total Accepted:    46.6K
 * Total Submissions: 86.2K
 * Testcase Example:  '["practice", "makes", "perfect", "coding",
 * "makes"]\n"coding"\n"practice"'
 *
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 *
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 *
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 *
 *
 *
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 *
 *
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 *
 */
class Solution {
public:
  int shortestDistance(vector<string> &words, string word1, string word2) {
    int p1 = -1;
    int p2 = -1;
    auto minDist = numeric_limits<long long>::max();

    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == word1) {
        p1 = i;
      }

      if (words[i] == word2) {
        p2 = i;
      }

      if (p1 != -1 && p2 != -1) {
        minDist = min(minDist, abs(static_cast<long long>(p1) - p2));
      }
    }
    return minDist;
  }
};
