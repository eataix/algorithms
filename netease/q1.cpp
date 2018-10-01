#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void helper(const vector<long long> &nums, long long currNum, long long &res) {
  if (nums.empty()) {
    res = max(res, currNum);
    return;
  }

  for (int i = 0; i < nums.size(); ++i) {
    vector<long long> nextNums;
    for (int j = 0; j < nums.size(); ++j) {
      if (i != j) {
        nextNums.push_back(nums[j]);
      }
    }

    if (nums.size() < 3) {
      helper(nextNums, currNum + nums[i], res);
      helper(nextNums, currNum * nums[i], res);
    } else {
      helper(nextNums, nums[i], res);
    }
  }
}

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long res = 0LL;

  helper({a, b, c}, 0LL, res);
  cout << res << endl;
  return 0;
}