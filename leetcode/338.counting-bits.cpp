#include <vector>
using namespace std;
/*
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (62.26%)
 * Total Accepted:    110.1K
 * Total Submissions: 176.9K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 *
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 *
 * Follow up:
 *
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount  in c++ or in any other language.
 *
 *
 *
 * Credits:Special thanks to @ syedee  for adding this problem and creating all
 * test cases.
 *
 *
 * https://webcache.googleusercontent.com/search?q=cache:expofuVjkvEJ:www.cnblogs.com/grandyang/p/5294255.html+&cd=7&hl=en&ct=clnk&gl=au
 */
class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> res(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
      res[i] = res[i >> 1] + (res & 1);
    }
    return res;
  }
};
