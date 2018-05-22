#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#ifdef DEBUG
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    map<int, vector<int>> m;
    queue<pair<int, TreeNode *>> q;

    q.push({0, root});

    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      m[p.first].push_back(p.second->val);

      if (p.second->left != nullptr) {
        q.push({p.first - 1, p.second->left});
      }
      if (p.second->right != nullptr) {
        q.push({p.first + 1, p.second->right});
      }
    }

    for (auto p : m) {
      res.push_back(p.second);
    }
    return res;
  }
};
