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
  int res = numeric_limits<int>::max(), pre = -1;

public:
  int minDiffInBST(TreeNode *root) {
    if (root->left != nullptr) {
      minDiffInBST(root->left);
    }
    if (pre >= 0) {
      res = min(res, root->val - pre);
    }
    pre = root->val;
    if (root->right != nullptr) {
      minDiffInBST(root->right);
    }
    return res;
  }
};
