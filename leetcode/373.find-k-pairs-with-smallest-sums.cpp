#include <queue>
#include <utility>
#include <vector>
using namespace std;
/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (31.65%)
 * Total Accepted:    45.3K
 * Total Submissions: 143K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 *
 *
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 *
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 *
 *
 * Example 1:
 *
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 *
 * Return: [1,2],[1,4],[1,6]
 *
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 *
 *
 *
 * Example 2:
 *
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 *
 * Return: [1,1],[1,1]
 *
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 *
 *
 * Example 3:
 *
 * Given nums1 = [1,2], nums2 = [3],  k = 3
 *
 * Return: [1,3],[2,3]
 *
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 *
 *
 *
 * Credits:Special thanks to @elmirap and @StefanPochmann for adding this
 * problem and creating all test cases.
 */
class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                        int k) {
    auto cmp = [&nums1, &nums2](const pair<int, int> &pa,
                                const pair<int, int> &pb) {
      return nums1[pa.first] + nums2[pa.second] >
             nums1[pb.first] + nums2[pb.second];
    };

    vector<pair<int, int>> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    if (nums1.empty() || nums2.empty() || k == 0) {
      return res;
    }

    q.push({0, 0});

    while (k-- > 0 && !q.empty()) {
      auto idx = q.top();
      q.pop();

      res.push_back({nums1[idx.first], nums2[idx.second]});
      if (idx.first + 1 < nums1.size()) {
        q.push({idx.first + 1, idx.second});
      }

      if (idx.first == 0 && idx.second + 1 < nums2.size()) {
        q.push({idx.first, idx.second + 1});
      }
    }
    return res;
  }
};
