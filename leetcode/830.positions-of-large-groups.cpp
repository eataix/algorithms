#include <string>
#include <vector>
using namespace std;
/*
 * [857] Positions of Large Groups
 *
 * https://leetcode.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (46.55%)
 * Total Accepted:    10.8K
 * Total Submissions: 23.2K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * In a string S of lowercase letters, these letters form consecutive groups of
 * the same character.
 *
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb",
 * "xxxx", "z" and "yy".
 *
 * Call a group large if it has 3 or more characters.  We would like the
 * starting and ending positions of every large group.
 *
 * The final answer should be in lexicographic order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending
 * positions 6.
 *
 *
 * Example 2:
 *
 *
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 *
 *
 * Example 3:
 *
 *
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 *
 *
 *
 * Note:  1 <= S.length <= 1000
 */
class Solution {
public:
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> res;
    int i = 0;
    while (i < S.size()) {
      int j = i;
      while (j < S.size() && S[i] == S[j]) {
        j += 1;
      }

      if (j - i >= 3) {
        res.push_back(vector<int>{i, j - 1});
      }
      i = j;
    }
    return res;
  }
};
