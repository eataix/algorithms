#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (37.67%)
 * Total Accepted:    170.6K
 * Total Submissions: 449.8K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */
class Solution {
public:
  int trap(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int ans = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] >= leftMax) {
          leftMax = height[left];
        } else {
          ans += leftMax - height[left];
        }
        left += 1;
      } else {
        if (height[right] >= rightMax) {
          rightMax = height[right];
        } else {
          ans += rightMax - height[right];
        }
        right -= 1;
      }
    }
    return ans;
  }

  int trap2(vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }
    vector<int> left(height.size(), 0);
    vector<int> right(height.size(), 0);

    left[0] = height[0];
    for (int i = 1; i < height.size(); ++i) {
      left[i] = max(left[i - 1], height[i]);
    }

    right[height.size() - 1] = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; --i) {
      right[i] = max(right[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 1; i < height.size() - 1; ++i) {
      ans += min(left[i], right[i]) - height[i];
    }
    return ans;
  }

  int trap1(vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }

    stack<int> s;

    int ans = 0;
    for (int i = 0; i < height.size(); ++i) {
      while (!s.empty() && height[i] > height[s.top()]) {
        int t = s.top();
        s.pop();
        if (s.empty()) {
          break;
        }
        ans +=
            (min(height[i], height[s.top()]) - height[t]) * (i - s.top() - 1);
      }
      s.push(i);
    }
    return ans;
  }
};
