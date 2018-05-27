#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
/*
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (30.23%)
 * Total Accepted:    56.7K
 * Total Submissions: 187.5K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * Example 1:
 *
 *
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 *
 * Example 2:
 *
 *
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 *
 * Note:
 *
 *
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 *
 *
 */
class Bucket {
public:
  bool used = false;
  int minval = numeric_limits<int>::max();
  int maxval = numeric_limits<int>::min();
};
class Solution {
public:
  int maximumGap(const vector<int> &nums) {
    if (nums.size() <= 1) {
      return 0;
    }

    auto result = std::minmax_element(cbegin(nums), cend(nums));
    int mini{*result.first};
    int maxi{*result.second};

    int bucket_size{
        max(1, (maxi - mini) / (static_cast<int>(nums.size()) - 1))};
    int bucket_num{(maxi - mini) / bucket_size + 1};
    vector<Bucket> buckets(bucket_num);

    for (const auto &num : nums) {
      int bucket_idx = (num - mini) / bucket_size;
      buckets[bucket_idx].used = true;
      buckets[bucket_idx].minval = min(num, buckets[bucket_idx].minval);
      buckets[bucket_idx].maxval = max(num, buckets[bucket_idx].maxval);
    }

    int prev_bucket_max = mini;
    int max_gap = 0;

    for (const auto &bucket : buckets) {
      if (bucket.used) {
        max_gap = max(max_gap, bucket.minval - prev_bucket_max);
        prev_bucket_max = bucket.maxval;
      }
    }
    return max_gap;
  }
};
