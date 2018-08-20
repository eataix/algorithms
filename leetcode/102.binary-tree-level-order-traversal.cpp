#include <queue>
#include <vector>
using namespace std;
/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (42.76%)
 * Total Accepted:    237.8K
 * Total Submissions: 556K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 *
 *
 */
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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
  void dfs(TreeNode *node, vector<vector<int>> &res, int level) {
    if (node == nullptr) {
      return;
    }

    if (level == res.size()) {
      res.push_back({});
    }

    res[level].push_back(node->val);
    dfs(node->left, res, level + 1);
    dfs(node->right, res, level + 1);
  }

public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    dfs(root, res, 0);
    return res;
  }

  vector<vector<int>> levelOrder2(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    vector<vector<int>> res;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      auto node = f.first;
      auto level = f.second;

      if (level == res.size()) {
        res.push_back({});
      }

      res[level].push_back(node->val);
      if (node->left != nullptr) {
        q.push({node->left, level + 1});
      }
      if (node->right != nullptr) {
        q.push({node->right, level + 1});
      }
    }
    return res;
  }
};
