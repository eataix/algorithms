#include <string>
#include <vector>
using namespace std;
/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (29.06%)
 * Total Accepted:    110.1K
 * Total Submissions: 378.8K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * Example:
 *
 *
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 *
 *
 */
class Solution {
  void dfs(const string &s, int n, string out, vector<string> &res) {
    if (n == 4) {
      if (s.empty()) {
        res.push_back(out);
      }
    } else {
      for (int len = 1; len <= 3; ++len) {
        if (s.size() < len) {
          break;
        }

        int val = stoi(s.substr(0, len));
        if (val > 255 || to_string(val).size() != len) {
          continue;
        }
        dfs(s.substr(len), n + 1, out + s.substr(0, len) + (n == 3 ? "" : "."),
            res);
      }
    }
  }

public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    dfs(s, 0, "", res);
    return res;
  }
};
