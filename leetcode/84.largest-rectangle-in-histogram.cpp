#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (27.66%)
 * Total Accepted:    120K
 * Total Submissions: 431.5K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 *
 *
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 *
 *
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 *
 *
 *
 * Example:
 *
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 *
 *
 */
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int res = 0;
    stack<int> st;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        int curr = st.top();
        st.pop();
        res = max(res, heights[curr] * (st.empty() ? i : (i - st.top() - 1)));
      }
      st.push(i);
    }
    return res;
  }

  int largestRectangleArea2(vector<int> &heights) {
    stack<int> s;
    s.push(-1);
    int n = heights.size();

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
      while (s.top() != -1 && heights[s.top()] >= heights[i]) {
        int t = s.top();
        s.pop();
        maxArea = max(maxArea, heights[t] * (i - s.top() - 1));
      }
      s.push(i);
    }
    while (s.top() != -1) {
      int st = s.top();
      s.pop();
      maxArea = max(maxArea, heights[st] * (n - s.top() - 1));
    }
    return maxArea;
  }
};
