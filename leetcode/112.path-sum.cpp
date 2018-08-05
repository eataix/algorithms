/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (35.52%)
 * Total Accepted:    234.4K
 * Total Submissions: 660K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 *
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }

    if (root->left == nullptr && root->right == nullptr) {
      return root->val == sum;
    }

    auto val = sum - root->val;
    return hasPathSum(root->left, val) || hasPathSum(root->right, val);
  }
};
