#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (35.19%)
 * Total Accepted:    51.2K
 * Total Submissions: 145.5K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 * Example:
 *
 *
 * Input: [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 *
 */
static inline int lowbit(int i) { return i & -i; }
class BIT {
public:
  vector<int> sums;
  BIT(int n) : sums(n + 1, 0) {}

  void add(int i, int val) {
    i += 1;
    while (i < sums.size()) {
      sums[i] += val;
      i += lowbit(i);
    }
  }

  int get(int i) {
    i += 1;
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }
};

class Solution {
public:
  vector<int> countSmaller(const vector<int> &nums) {
    set<int> sorted{nums.cbegin(), nums.cend()};
    unordered_map<int, int> ranks;

    int rank = 0;
    for (const int num : sorted) {
      ranks[num] = rank;
      rank += 1;
    }

    vector<int> res;
    BIT tree(ranks.size());
    for (auto it = nums.crbegin(); it != nums.crend(); ++it) {
      res.push_back(tree.get(ranks[*it] - 1));
      tree.add(ranks[*it], 1);
    }
    reverse(res.begin(), res.end());
    return res;
  }

  vector<int> countSmaller2(vector<int> &nums) {
    vector<int> tmp;
    vector<int> res(nums.size());

    for (int i = nums.size() - 1; i >= 0; --i) {
      int left = 0;
      int right = tmp.size();

      while (left < right) {
        int mid = left + (right - left) / 2;

        if (tmp[mid] >= nums[i]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      res[i] = right;
      tmp.insert(tmp.begin() + right, nums[i]);
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.countSmaller({5, 2, 6, 1});
}
#endif
