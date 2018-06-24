#include <queue>
#include <vector>
using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
  /**
   * @param root: the root of tree
   * @return: the vertical order traversal
   */
  vector<vector<int>> verticalOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    unordered_map<int, vector<int>> m;
    int minLevel = 0;
    int maxLevel = 0;
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      minLevel = min(minLevel, top.second);
      maxLevel = max(maxLevel, top.second);

      m[top.second].push_back(top.first->val);

      if (top.first->left != nullptr) {
        q.push({top.first->left, top.second - 1});
      }

      if (top.first->right != nullptr) {
        q.push({top.first->right, top.second + 1});
      }
    }
    vector<vector<int>> res;
    for (int l = minLevel; l <= maxLevel; ++l) {
      res.push_back(m[l]);
    }
    return res;
  }
};