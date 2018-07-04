#include <queue>
#include <vector>
using namespace std;
/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (37.52%)
 * Total Accepted:    146K
 * Total Submissions: 389.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);

    bool ltr = true;
    while (!q.empty()) {
      int size = q.size();
      vector<int> row(size);
      for (int i = 0; i < size; ++i) {
        auto node = q.front();
        q.pop();

        int idx = ltr ? i : size - 1 - i;

        row[idx] = node->val;
        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ltr = !ltr;
      res.push_back(row);
    }

    return res;
  }
};
