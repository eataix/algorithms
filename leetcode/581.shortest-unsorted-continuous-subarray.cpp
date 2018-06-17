#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.39%)
 * Total Accepted:    34.3K
 * Total Submissions: 116.5K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 *
 *
 *
 * Note:
 *
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means .
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103066/Ideas-behind-the-O(n)-two-pass-and-one-pass-solutions
 *
 */
class Solution {
public:
  int findUnsortedSubarray(const vector<int> &nums) {
    int start = 0;
    int end = -1;
    int maxV = numeric_limits<int>::min();
    int minV = numeric_limits<int>::max();

    for (int offset = 0; offset < nums.size(); ++offset) {
      int left = offset;
      int right = nums.size() - 1 - offset;

      maxV = max(maxV, nums[left]);
      if (nums[left] != maxV) {
        end = left;
      }

      minV = min(minV, nums[right]);
      if (nums[right] != minV) {
        start = right;
      }
    }
    cout << "start: " << start << endl;
    cout << "end: " << end << endl;

    return end - start + 1;
  }

  int findUnsortedSubarray2(const vector<int> &nums) {
    int l = 0;
    while (l < nums.size() - 1 && nums[l] <= nums[l + 1]) {
      l += 1;
    }
    if (l >= nums.size() - 1) {
      return 0;
    }

    int r = nums.size() - 1;
    while (nums[r] >= nums[r - 1]) {
      r -= 1;
    }

    cout << "l: " << l << endl;
    cout << "r: " << r << endl;

    int maxV = numeric_limits<int>::min();
    int minV = numeric_limits<int>::max();
    for (int k = l; k <= r; ++k) {
      maxV = max(maxV, nums[k]);
      minV = min(minV, nums[k]);
    }

    while (l >= 0 && nums[l] > minV) {
      l -= 1;
    }

    while (r <= nums.size() - 1 && nums[r] < maxV) {
      r += 1;
    }

    cout << "l: " << l << endl;
    cout << "r: " << r << endl;
    return (r - 1) - (l + 1) + 1;
  }

  int findUnsortedSubarray1(const vector<int> &nums) {
    vector<int> sorted_nums{nums.begin(), nums.end()};
    sort(sorted_nums.begin(), sorted_nums.end());

    int start = 0;
    int end = nums.size() - 1;

    while (start <= nums.size() && nums[start] == sorted_nums[start]) {
      start += 1;
    }

    while (end >= 0 && nums[end] == sorted_nums[end]) {
      end -= 1;
    }

    if (start >= end) {
      return 0;
    } else {
      return end - start + 1;
    }
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.findUnsortedSubarray(vector<int>{2, 6, 4, 8, 10, 9, 15}) << endl;
}
#endif
