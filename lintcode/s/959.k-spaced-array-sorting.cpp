#include <queue>
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
    for (int i = 0; i < k; ++i) {
      q.push({arr[i], i});
    }

    vector<int> res;
    while (!q.empty()) {
      auto p = q.top();
      int elem = p.first;
      int idx = p.second;

      res.push_back(elem);
      q.pop();

      int newIdx = idx + k;
      if (newIdx < arr.size()) {
        q.push({arr[newIdx], newIdx});
      }
    }

    return res;
  }
};
