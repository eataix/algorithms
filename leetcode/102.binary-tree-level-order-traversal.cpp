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
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    vector<TreeNode *> curr;
    if (root != nullptr) {
      curr.push_back(root);
    }
    while (curr.size() > 0) {
      vector<int> values;
      for (auto const &t : curr) {
        values.push_back(t->val);
      }
      res.push_back(values);

      auto parent = curr;
      curr.clear();
      for (auto const &t : parent) {
        if (t->left != nullptr) {
          curr.push_back(t->left);
        }
        if (t->right != nullptr) {
          curr.push_back(t->right);
        }
      }
    }
    return res;
  }
};
