/*
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (48.68%)
 * Total Accepted:    40.4K
 * Total Submissions: 83K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 *
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 *
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
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
  TreeNode *convertBST(TreeNode *root, int *sum) {
    if (root == nullptr) {
      return nullptr;
    }

    TreeNode *newRight = convertBST(root->right, sum);
    *sum += root->val;
    TreeNode *newRoot = new TreeNode(*sum);
    TreeNode *newLeft = convertBST(root->left, sum);
    newRoot->left = newLeft;
    newRoot->right = newRight;

    return newRoot;
  }

public:
  TreeNode *convertBST(TreeNode *root) {
    int sum = 0;
    return convertBST(root, &sum);
  }
};
