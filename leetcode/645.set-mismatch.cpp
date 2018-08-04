#include <vector>
using namespace std;
/*
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (39.70%)
 * Total Accepted:    28.2K
 * Total Submissions: 71.2K
 * Testcase Example:  '[1,2,2,4]'
 *
 *
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number.
 *
 *
 *
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 *
 *
 *
 * Note:
 *
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 *
 *
 */
class Solution {
public:
  vector<int> findErrorNums(vector<int> nums) {
    vector<int> res(2, -1);
    for (int i : nums) {
      if (nums[abs(i) - 1] < 0) {
        res[0] = abs(i);
      } else {
        nums[abs(i) - 1] *= -1;
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        res[1] = i + 1;
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.findErrorNums({3, 2, 3, 4, 6, 5});
}
#endif
