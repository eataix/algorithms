class Solution {
public:
  /**
   * @param heights: a list of integers
   * @return: a integer
   */
  int trapRainWater(vector<int> &heights) {
    int left = 0;
    int right = heights.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int cnt = 0;
    while (left < right) {
      if (heights[left] < heights[right]) {
        if (heights[left] < leftMax) {
          cnt += leftMax - heights[left];
        } else {
          leftMax = heights[left];
        }
        left += 1;
      } else {
        if (heights[right] < rightMax) {
          cnt += rightMax - heights[right];
        } else {
          rightMax = heights[right];
        }
        right -= 1;
      }
    }
    return cnt;
  }
  int trapRainWater2(vector<int> &heights) {
    if (heights.size() <= 2) {
      return 0;
    }

    vector<int> left(heights.size(), 0);
    vector<int> right(heights.size(), 0);

    left[0] = heights[0];
    for (int i = 1; i < heights.size(); ++i) {
      left[i] = max(left[i - 1], heights[i]);
    }

    right[heights.size() - 1] = heights.back();
    for (int i = heights.size() - 2; i >= 0; --i) {
      right[i] = max(right[i + 1], heights[i]);
    }

    int res{0};
    for (int i = 1; i < heights.size() - 1; ++i) {
      res += min(left[i], right[i]) - heights[i];
    }
    return res;
  }
};
