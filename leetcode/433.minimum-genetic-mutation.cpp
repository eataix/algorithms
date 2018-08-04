#include <queue>
#include <string>
#include <unordered_set>
using namespace std;
/*
 * [433] Minimum Genetic Mutation
 *
 * https://leetcode.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (35.50%)
 * Total Accepted:    14.6K
 * Total Submissions: 41.2K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * A gene string can be represented by an 8-character long string, with choices
 * from "A", "C", "G", "T".
 *
 * Suppose we need to investigate about a mutation (mutation from "start" to
 * "end"), where ONE mutation is defined as ONE single character changed in the
 * gene string.
 *
 * For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
 *
 * Also, there is a given gene "bank", which records all the valid gene
 * mutations. A gene must be in the bank to make it a valid gene string.
 *
 * Now, given 3 things - start, end, bank, your task is to determine what is
 * the minimum number of mutations needed to mutate from "start" to "end". If
 * there is no such a mutation, return -1.
 *
 * Note:
 *
 *
 * Starting point is assumed to be valid, so it might not be included in the
 * bank.
 * If multiple mutations are needed, all mutations during in the sequence must
 * be valid.
 * You may assume start and end string is not the same.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * start: "AACCGGTT"
 * end:   "AACCGGTA"
 * bank: ["AACCGGTA"]
 *
 * return: 1
 *
 *
 *
 *
 * Example 2:
 *
 *
 * start: "AACCGGTT"
 * end:   "AAACGGTA"
 * bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
 *
 * return: 2
 *
 *
 *
 *
 * Example 3:
 *
 *
 * start: "AAAAACCC"
 * end:   "AACCCCCC"
 * bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
 *
 * return: 3
 *
 *
 *
 *
 */

using namespace std;
class Solution {
  vector<char> ranges{'A', 'C', 'G', 'T'};

public:
  int minMutation(string start, string end, vector<string> &bank) {
    unordered_set<string> dict{bank.cbegin(), bank.cend()};

    queue<pair<string, int>> q;
    q.push({start, 0});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      auto s = p.first;
      auto depth = p.second;

      if (s == end) {
        return depth;
      }

      for (int i = 0; i < s.size(); ++i) {
        auto newStr = s;
        for (char ch : ranges) {
          if (newStr[i] == ch) {
            continue;
          }
          newStr[i] = ch;
          if (dict.count(newStr)) {
            q.push({newStr, depth + 1});
            dict.erase(newStr);
          }
        }
      }
    }
    return -1;
  }
};
