#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (18.74%)
 * Total Accepted:    68.8K
 * Total Submissions: 367.4K
 * Testcase Example:  '[1,2,3,1]\n4\n0'
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,1], k = 4, t = 0
 * Output: true
 *
 * Example 2:
 *
 *
 * Input: [1,0,1,1], k = 1, t = 0
 * Output: true
 *
 * Example 3:
 *
 *
 * Input: [4,2], k = 2, t = 1
 * Output: false
 *
 */
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    if (k < 1 || t < 0) {
      return false;
    }
    unordered_map<long, long> m;
    long min_val = *min_element(cbegin(nums), cend(nums));
    long bucket_size{t + 1};

    for (int i = 0; i < nums.size(); ++i) {
      long bucket_id{(nums[i] - min_val) / bucket_size};

      if (m.size() > k) {
        long lastBucket{(nums[i - k - 1] - min_val) / bucket_size};
        m.erase(lastBucket);
      }

      bool e1 = m.find(bucket_id) != cend(m);
      bool e2 = m.find(bucket_id - 1) != cend(m) &&
                abs(nums[i] - m[bucket_id - 1]) <= t;
      bool e3 = m.find(bucket_id + 1) != cend(m) &&
                abs(m[bucket_id + 1] - nums[i]) <= t;

      if (e1 || e2 || e3) {
        return true;
      }
      m[bucket_id] = nums[i];
    }
    return false;
  }
};
