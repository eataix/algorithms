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
   * @param root: the root of binary tree
   * @return: the new root
   */
  TreeNode *convertBST(TreeNode *root) {
    int runningTotal = 0;
    return recursive(root, runningTotal);
  }

  TreeNode *recursive(TreeNode *root, int &runningTotal) {
    if (root == nullptr) {
      return nullptr;
    }

    TreeNode *newRight = recursive(root->right, runningTotal);
    runningTotal += root->val;
    TreeNode *newRoot = new TreeNode{runningTotal};
    TreeNode *newLeft = recursive(root->left, runningTotal);
    newRoot->left = newLeft;
    newRoot->right = newRight;
    return newRoot;
  }
};
