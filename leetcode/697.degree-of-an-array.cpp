#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (46.60%)
 * Total Accepted:    20.1K
 * Total Submissions: 43.1K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 *
 * Example 1:
 *
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 *
 *
 *
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 */
class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    int res = INT_MAX;
    int degree = 0;
    unordered_map<int, int> m;
    unordered_map<int, int> start;
    unordered_map<int, int> end;

    for (int i = 0; i < nums.size(); ++i) {
      m[nums[i]] += 1;
      if (m[nums[i]] == 1) {
        start[nums[i]] = i;
        end[nums[i]] = i;
      } else {
        end[nums[i]] = i;
      }
      degree = max(degree, m[nums[i]]);
    }

    for (auto a : m) {
      if (a.second == degree) {
        res = min(res, end[a.first] - start[a.first] + 1);
      }
    }
    return res;
  }
};
