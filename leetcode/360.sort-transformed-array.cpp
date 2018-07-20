#include <vector>
using namespace std;
/*
 * [360] Sort Transformed Array
 *
 * https://leetcode.com/problems/sort-transformed-array/description/
 *
 * algorithms
 * Medium (45.16%)
 * Total Accepted:    19K
 * Total Submissions: 42.2K
 * Testcase Example:  '[-4,-2,2,4]\n1\n3\n5'
 *
 *
 * Given a sorted array of integers nums and integer values a, b and c.  Apply
 * a quadratic function of the form f(x) = ax2 + bx + c to each element x in
 * the array.
 *
 * The returned array must be in sorted order.
 *
 * Expected time complexity: O(n)
 *
 * Example:
 *
 * nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
 *
 * Result: [3, 9, 15, 33]
 *
 * nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
 *
 * Result: [-23, -5, 1, 7]
 *
 *
 *
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
  int quad(int x, int a, int b, int c) { return a * x * x + b * x + c; }

public:
  vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
    auto N = nums.size();
    vector<int> res(N);

    auto start{0};
    auto end{N - 1};
    auto i = a >= 0 ? N - 1 : 0;

    while (start <= end) {
      auto startNum = quad(nums[start], a, b, c);
      auto endNum = quad(nums[end], a, b, c);

      if (a >= 0) {
        if (startNum >= endNum) {
          res[i] = startNum;
          start += 1;
        } else {
          res[i] = endNum;
          end -= 1;
        }
        i -= 1;
      } else {
        if (startNum <= endNum) {
          res[i] = startNum;
          start += 1;
        } else {
          res[i] = endNum;
          end -= 1;
        }
        i += 1;
      }
    }

    return res;
  }
};
