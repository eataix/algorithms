#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (49.65%)
 * Total Accepted:    103.6K
 * Total Submissions: 208.7K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 *
 * Note:
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 *
 */
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;

    for (const int &num : nums) {
      m[num] += 1;
    }

    vector<vector<int>> bucket(nums.size() + 1);
    vector<int> res;
    for (auto kv : m) {
      bucket[kv.second].push_back(kv.first);
    }
    for (int i = nums.size(); i >= 0; --i) {
      for (const auto &v : bucket[i]) {
        res.push_back(v);
        if (res.size() == k) {
          return res;
        }
      }
    }
    return res;
  }
};
