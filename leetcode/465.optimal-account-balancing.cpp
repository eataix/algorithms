#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [465] Optimal Account Balancing
 *
 * https://leetcode.com/problems/optimal-account-balancing/description/
 *
 * algorithms
 * Hard (39.62%)
 * Total Accepted:    8.8K
 * Total Submissions: 22.2K
 * Testcase Example:  '[[0,1,10],[2,0,5]]'
 *
 * A group of friends went on holiday and sometimes lent each other money. For
 * example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5
 * for a taxi ride. We can model each transaction as a tuple (x, y, z) which
 * means person x gave person y $z. Assuming Alice, Bill, and Chris are person
 * 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can
 * be represented as [[0, 1, 10], [2, 0, 5]].
 *
 * Given a list of transactions between a group of people, return the minimum
 * number of transactions required to settle the debt.
 *
 * Note:
 *
 * A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
 * Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we
 * could also have the persons 0, 2, 6.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * [[0,1,10], [2,0,5]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * Person #0 gave person #1 $10.
 * Person #2 gave person #0 $5.
 *
 * Two transactions are needed. One way to settle the debt is person #1 pays
 * person #0 and #2 $5 each.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
 *
 * Output:
 * 1
 *
 * Explanation:
 * Person #0 gave person #1 $10.
 * Person #1 gave person #0 $1.
 * Person #1 gave person #2 $5.
 * Person #2 gave person #0 $5.
 *
 * Therefore, person #1 only need to give person #0 $4, and all debt is
 * settled.
 *
 *
 */

#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [465] Optimal Account Balancing
 *
 * https://leetcode.com/problems/optimal-account-balancing/description/
 *
 * algorithms
 * Hard (39.62%)
 * Total Accepted:    8.8K
 * Total Submissions: 22.2K
 * Testcase Example:  '[[0,1,10],[2,0,5]]'
 *
 * A group of friends went on holiday and sometimes lent each other money. For
 * example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5
 * for a taxi ride. We can model each transaction as a tuple (x, y, z) which
 * means person x gave person y $z. Assuming Alice, Bill, and Chris are person
 * 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can
 * be represented as [[0, 1, 10], [2, 0, 5]].
 *
 * Given a list of transactions between a group of people, return the minimum
 * number of transactions required to settle the debt.
 *
 * Note:
 *
 * A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
 * Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we
 * could also have the persons 0, 2, 6.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * [[0,1,10], [2,0,5]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * Person #0 gave person #1 $10.
 * Person #2 gave person #0 $5.
 *
 * Two transactions are needed. One way to settle the debt is person #1 pays
 * person #0 and #2 $5 each.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
 *
 * Output:
 * 1
 *
 * Explanation:
 * Person #0 gave person #1 $10.
 * Person #1 gave person #0 $1.
 * Person #1 gave person #2 $5.
 * Person #2 gave person #0 $5.
 *
 * Therefore, person #1 only need to give person #0 $4, and all debt is
 * settled.
 *
 *
 */
class Solution {
  void helper(vector<int> &account, int start, int &num, int out) {
    while (start < account.size() && account[start] == 0) {
      start += 1;
    }

    if (start == account.size()) {
      num = min(num, out);
      return;
    }

    for (int i = start + 1; i < account.size(); ++i) {
      if (account[i] != 0) {
        if ((account[i] > 0) ^ (account[start] > 0)) {
          account[i] += account[start];
          helper(account, start + 1, num, out + 1);
          account[i] -= account[start];
        }
      }
    }
  }

public:
  int minTransfers(vector<vector<int>> &transactions) {
    unordered_map<int, long> balance;

    for (auto const &transaction : transactions) {
      auto from = transaction[0];
      auto to = transaction[1];
      auto amount = transaction[2];

      balance[from] -= amount;
      balance[to] += amount;
    }
    vector<int> debt;
    for (auto const &kv : balance) {
      if (kv.second != 0) {
        debt.push_back(kv.second);
      }
    }
    int res = numeric_limits<int>::max();
    helper(debt, 0, res, 0);
    return res;
  }
};
