#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (52.00%)
 * Total Accepted:    55K
 * Total Submissions: 105.8K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 *
 *
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 *
 */
class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> m;

    for (char ch : s) {
      m[ch] += 1;
    }

    auto cmp = [&m](char i, char j) { return m[i] < m[j]; };
    priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
    for (auto const &kv : m) {
      pq.push(kv.first);
    }
    string res;
    while (!pq.empty()) {
      auto ch = pq.top();
      pq.pop();
      res += string(m[ch], ch);
    }
    return res;
  }
};
