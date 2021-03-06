#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  /**
   * @param arr: The K spaced array
   * @param k: The param k
   * @return: Return the sorted array
   */
  vector<int> getSortedArray(vector<int> &arr, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    for (int i = 0; i < arr.size() && i < k; ++i) {
      q.push({arr[i], i});
    }

    vector<int> res;
    while (!q.empty()) {
      auto p = q.top();
      q.pop();
      res.push_back(p.first);
      if (p.second + k < arr.size()) {
        q.push({arr[p.second + k], p.second + k});
      }
    }
    return res;
  }
};
