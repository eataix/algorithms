#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * [768] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (64.61%)
 * Total Accepted:    15.1K
 * Total Submissions: 23.4K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 *
 * A string S of lowercase letters is given.  We want to partition this string
 * into as many parts as possible so that each letter appears in at most one
 * part, and return a list of integers representing the size of these parts.
 *
 *
 * Example 1:
 *
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 *
 *
 *
 * Note:
 * S will have length in range [1, 500].
 * S will consist of lowercase letters ('a' to 'z') only.
 *
 */
class Solution {
public:
  vector<int> partitionLabels(string S) {
    unordered_map<char, int> m;

    for (int i = 0; i < S.size(); ++i) {
      m[S[i]] = i;
    }

    int start = 0;
    int last = 0;

    vector<int> ans;

    for (int i = 0; i < S.size(); ++i) {
      last = max(last, m[S[i]]);
      if (i == last) {
        ans.push_back(last - start + 1);
        start = i + 1;
      }
    }
    return ans;
  }
};
