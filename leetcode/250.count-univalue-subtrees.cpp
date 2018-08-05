/*
 * [250] Count Univalue Subtrees
 *
 * https://leetcode.com/problems/count-univalue-subtrees/description/
 *
 * algorithms
 * Medium (44.96%)
 * Total Accepted:    25.2K
 * Total Submissions: 56K
 * Testcase Example:  '[5,1,5,5,5,null,5]'
 *
 * Given a binary tree, count the number of uni-value subtrees.
 *
 * A Uni-value subtree means all nodes of the subtree have the same value.
 *
 * Example :
 *
 *
 * Input:  root = [5,1,5,5,5,null,5]
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           1   5
 * ⁠          / \   \
 * ⁠         5   5   5
 *
 * Output: 4
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
  bool helper(TreeNode *root, int &res) {
    if (root == nullptr) {
      return true;
    }

    auto leftVal = helper(root->left, res);
    auto rightVal = helper(root->right, res);

    if (leftVal && rightVal &&
        (root->left == nullptr || root->left->val == root->val) &&
        (root->right == nullptr || root->right->val == root->val)) {
      res += 1;
      return true;
    }

    return false;
  }

public:
  int countUnivalSubtrees(TreeNode *root) {
    int res = 0;
    helper(root, res);
    return res;
  }
};
