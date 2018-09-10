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
  void dfs(TreeNode *root, int &res) {
    if (root == nullptr) {
      return;
    }
    if (root->left == nullptr && root->right == nullptr) {
      res += root->val;
      return;
    }

    dfs(root->left, res);
    dfs(root->right, res);
  }

public:
  /**
   * @param root:
   * @return: the sum of leafnode
   */
  int sumLeafNode(TreeNode *root) {
    int res = 0;
    dfs(root, res);
    return res;
  }
};
