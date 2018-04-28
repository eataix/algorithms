#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (44.30%)
 * Total Accepted:    106.9K
 * Total Submissions: 241.3K
 * Testcase Example:  '[]\n[]'
 *
 *
 * Given two arrays, write a function to compute their intersection.
 *
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 *
 * Note:
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 *
 * Follow up:
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> m;
    vector<int> res;
    for (auto &n : nums1) {
      m[n] += 1;
    }
    for (auto &n : nums2) {
      if (m[n] > 0) {
        res.push_back(n);
      }
      m[n] -= 1;
    }
    return res;
  }

  vector<int> intersect2(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    int i = 0;
    int j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        res.push_back(nums1[i]);
        i += 1;
        j += 1;
      } else if (nums1[i] > nums2[j]) {
        j += 1;
      } else {
        i += 1;
      }
    }
    return res;
  }
};
