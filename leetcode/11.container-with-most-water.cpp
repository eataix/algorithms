#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.11%)
 * Total Accepted:    194.6K
 * Total Submissions: 524.3K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxAreaSeen = -1;
        while (i < j) {
            int currArea = min(height[i], height[j]) * (j - i);
            maxAreaSeen = max(currArea, maxAreaSeen);
            if (height[i] < height[j]) {
                i += 1;
            } else {
                j-=1;
            }
        }
        return maxAreaSeen;
    }
};
