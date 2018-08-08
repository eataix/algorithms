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
    stack<pair<int, int>> st;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i) {
      while (!st.empty() && st.top().second >= heights[i]) {
        auto h = st.top().second;
        auto idx = st.top().first;
        st.pop();
        res = max(res, h * (st.empty() ? i : (i - st.top().first - 1)));
      }
      st.push({i, heights[i]});
    }
    return res;
  }
};
