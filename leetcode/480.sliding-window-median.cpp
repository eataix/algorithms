#include <set>
#include <vector>
using namespace std;
/*
 * [480] Sliding Window Median
 *
 * https://leetcode.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (30.77%)
 * Total Accepted:    15.6K
 * Total Submissions: 50.8K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples:
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Your job is to output the median array for each window in the
 * original array.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 *
 * Window position                Median
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7       -1
 * ⁠1  3 [-1  -3  5] 3  6  7       -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 *
 *
 * Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 *
 * Note:
 * You may assume k is always valid, ie: k is always smaller than input array's
 * size for non-empty array.
 */
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    vector<double> res;
    multiset<double> small, large;
    for (int i = 0; i < nums.size(); ++i) {
      if (i >= k) {
        if (small.count(nums[i - k])) {
          small.erase(small.find(nums[i - k]));
        } else if (large.count(nums[i - k])) {
          large.erase(large.find(nums[i - k]));
        }
      }

      if (small.size() <= large.size()) {
        if (large.empty() || nums[i] <= *large.begin()) {
          small.insert(nums[i]);
        } else {
          small.insert(*large.begin());
          large.erase(large.begin());
          large.insert(nums[i]);
        }
      } else {
        if (nums[i] >= *small.rbegin()) {
          large.insert(nums[i]);
        } else {
          large.insert(*small.rbegin());
          small.erase(--small.end());
          small.insert(nums[i]);
        }
      }

      if (i >= (k - 1)) {
        if (k % 2 == 1) {
          res.push_back(*small.rbegin());
        } else {
          res.push_back(static_cast<double>(*small.rbegin() + *large.begin()) /
                        2);
        }
      }
    }
    return res;
  }
};
