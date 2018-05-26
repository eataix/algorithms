#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int trap(const vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int left_max = 0;
    int right_max = 0;
    int ans = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] >= left_max) {
          left_max = height[left];
        } else {
          ans += left_max - height[left];
        }
        left += 1;
      } else {
        if (height[right] >= right_max) {
          right_max = height[right];
        } else {
          ans += right_max - height[right];
        }
        right -= 1;
      }
    }
    return ans;
  }

  int trap1(const vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }

    int ans = 0;
    int n = height.size();

    vector<int> left_max(n, 0);
    vector<int> right_max(n, 0);

    left_max[0] = height[0];
    for (int i = 1; i < n; ++i) {
      left_max[i] = max(height[i], left_max[i - 1]);
    }

    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      right_max[i] = max(height[i], right_max[i + 1]);
    }

    for (int i = 1; i < n - 1; ++i) {
      ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
  }

  int trap3(const vector<int> &height) {
    int ans = 0;
    stack<int> st;

    for (int i = 0; i < height.size(); ++i) {
      while (!st.empty() && height[i] > height[st.top()]) {
        int t = st.top();
        st.pop();
        if (st.empty()) {
          continue;
        }
        ans +=
            (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
      }
      st.push(i);
    }
    return ans;
  }
};
