#include <algorithm>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef DEBUG
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    unordered_map<int, vector<int>> m;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      TreeNode *t = q.front().first;
      int i = q.front().second;
      q.pop();
      m[i].push_back(t->val);
      if (t->left) {
        q.push({t->left, i - 1});
      }
      if (t->right) {
        q.push({t->right, i + 1});
      }
    }

    vector<int> levels;

    for (const auto &kv : m) {
      levels.push_back(kv.first);
    }

    sort(levels.begin(), levels.end());

    for (const auto &level : levels) {
      res.push_back(m[level]);
    }
    return res;
  }
};
