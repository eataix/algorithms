#include <algorithm>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#ifdef DEBUG
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};
#endif

class Solution {
public:
  /**
   * @param root: the root of tree
   * @return: the vertical order traversal
   */
  vector<vector<int>> verticalOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    int minK = 0;
    int maxK = 0;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    unordered_map<int, vector<int>> m;
    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      m[p.second].push_back(p.first->val);
      minK = min(minK, p.second);
      maxK = max(maxK, p.second);

      if (p.first->left != nullptr) {
        q.push({p.first->left, p.second - 1});
      }

      if (p.first->right != nullptr) {
        q.push({p.first->right, p.second + 1});
      }
    }

    for (int k = minK; k <= maxK; ++k) {
      res.push_back(m[k]);
    }
    return res;
  }
};
