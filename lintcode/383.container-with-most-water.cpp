class Solution {
public:
  /**
   * @param heights: a vector of integers
   * @return: an integer
   */
  int maxArea(vector<int> &heights) {
    int left = 0;
    int right = heights.size() - 1;
    int maxA = 0;
    while (left < right) {
      int area = min(heights[left], heights[right]) * (right - left);
      maxA = max(maxA, area);

      if (heights[left] < heights[right]) {
        left += 1;
      } else {
        right -= 1;
      }
    }
    return maxA;
  }
};
