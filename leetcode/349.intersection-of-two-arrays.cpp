#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (48.27%)
 * Total Accepted:    129.5K
 * Total Submissions: 268.2K
 * Testcase Example:  '[]\n[]'
 *
 *
 * Given two arrays, write a function to compute their intersection.
 *
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 *
 * Note:
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 */
class Solution {
  int binary_search(const vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    int mid;

    while (start <= end) {
      mid = (start + end) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return -1;
  }

public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    if (nums1.empty() || nums2.empty()) {
      return res;
    }
    vector<int> *smaller;
    vector<int> *longer;

    if (nums1.size() < nums2.size()) {
      smaller = &nums1;
      longer = &nums2;
    } else {
      smaller = &nums2;
      longer = &nums1;
    }

    unordered_set<int> s;
    sort(smaller->begin(), smaller->end());

    for (int i : *longer) {
      if (binary_search(*smaller, i) != -1) {
        s.insert(i);
      }
    }

    for (auto i : s) {
      res.push_back(i);
      cout << i << " ";
    }
    cout << endl;
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> v1{1, 2, 2, 1};
  vector<int> v2{2, 2};
  sol.intersection(v1, v2);
}
#endif
