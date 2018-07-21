#include <cmath>
#include <string>
#include <vector>
using namespace std;
/*
 * [754] Cracking the Safe
 *
 * https://leetcode.com/problems/cracking-the-safe/description/
 *
 * algorithms
 * Hard (41.10%)
 * Total Accepted:    5.5K
 * Total Submissions: 13.4K
 * Testcase Example:  '1\n1'
 *
 *
 * There is a box protected by a password.  The password is n digits, where
 * each letter can be one of the first k digits 0, 1, ..., k-1.
 *
 * You can keep inputting the password, the password will automatically be
 * matched against the last n digits entered.
 *
 * For example, assuming the password is "345", I can open it when I type
 * "012345", but I enter a total of 6 digits.
 *
 * Please return any string of minimum length that is guaranteed to open the
 * box after the entire string is inputted.
 *
 *
 * Example 1:
 *
 * Input: n = 1, k = 2
 * Output: "01"
 * Note: "10" will be accepted too.
 *
 *
 *
 * Example 2:
 *
 * Input: n = 2, k = 2
 * Output: "00110"
 * Note: "01100", "10011", "11001" will be accepted too.
 *
 *
 *
 * Note:
 *
 * n will be in the range [1, 4].
 * k will be in the range [1, 10].
 * k^n will be at most 4096.
 *
 *
 * https://leetcode.com/problems/cracking-the-safe/discuss/110260/De-Bruijn-sequence-C++
 */
class Solution {
public:
  string crackSafe(int n, int k) {
    if (k == 1) {
      return string(n, '0');
    }

    int v = pow(k, n - 1);
    vector<vector<bool>> visited(v, vector<bool>(k, false));
    string sequence;
    dfs(0, n, k, v, sequence, visited);
    return sequence + sequence.substr(0, n - 1);
  }

  void dfs(int u, int n, int k, int v, string &sequence,
           vector<vector<bool>> &visited) {
    for (int i = 0; i < k; ++i) {
      if (!visited[u][i]) {
        visited[u][i] = true;
        dfs((u * k + i) % v, n, k, v, sequence, visited);
        sequence.push_back('0' + i);
      }
    }
  }
};
