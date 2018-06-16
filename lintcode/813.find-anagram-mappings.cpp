#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param A: lists A
   * @param B: lists B
   * @return: the index mapping
   */
  vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
    unordered_map<int, queue<int>> m;

    for (int i = 0; i < B.size(); ++i) {
      int num = B[i];

      m[num].push(i);
    }

    vector<int> res;
    for (int i = 0; i < A.size(); ++i) {
      int num = A[i];

      int idx = m[num].front();
      m[num].pop();

      res.push_back(idx);
    }

    return res;
  }
};
