#include <vector>
using namespace std;
/*
 * [770] Couples Holding Hands
 *
 * https://leetcode.com/problems/couples-holding-hands/description/
 *
 * algorithms
 * Hard (48.64%)
 * Total Accepted:    6.5K
 * Total Submissions: 13.4K
 * Testcase Example:  '[0,2,1,3]'
 *
 *
 * N couples sit in 2N seats arranged in a row and want to hold hands.  We want
 * to know the minimum number of swaps so that every couple is sitting side by
 * side.  A swap consists of choosing any two people, then they stand up and
 * switch seats.
 *
 * The people and seats are represented by an integer from 0 to 2N-1, the
 * couples are numbered in order, the first couple being (0, 1), the second
 * couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).
 *
 * The couples' initial seating is given by row[i] being the value of the
 * person who is initially sitting in the i-th seat.
 *
 * Example 1:
 * Input: row = [0, 2, 1, 3]
 * Output: 1
 * Explanation: We only need to swap the second (row[1]) and third (row[2])
 * person.
 *
 *
 * Example 2:
 * Input: row = [3, 2, 0, 1]
 * Output: 0
 * Explanation: All couples are already seated side by side.
 *
 *
 *
 * Note:
 * ⁠
 * ⁠len(row) is even and in the range of [4, 60].
 * ⁠row is guaranteed to be a permutation of 0...len(row)-1.
 *
 *
 * https://leetcode.com/problems/couples-holding-hands/discuss/113362/JavaC++-O(N)-solution-using-cyclic-swapping
 */
class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int res = 0;
    int N = row.size();

    vector<int> ptn(N, 0);
    vector<int> pos(N, 0);

    for (int i = 0; i < N; ++i) {
      ptn[i] = (i % 2 == 0 ? i + 1 : i - 1);
      pos[row[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
      for (int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]) {
        swap(row[i], row[j]);
        swap(pos[row[i]], pos[row[j]]);
        res += 1;
      }
    }
    return res;
  }
};
