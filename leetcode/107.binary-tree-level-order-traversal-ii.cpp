#include <vector>
using namespace std;
/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (43.22%)
 * Total Accepted:    176.4K
 * Total Submissions: 408.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    dfs(root, res, 0);
    return vector<vector<int>>{res.crbegin(), res.crend()};
  }
};
