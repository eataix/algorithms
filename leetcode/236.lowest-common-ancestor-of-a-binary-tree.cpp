/*
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (29.92%)
 * Total Accepted:    162.7K
 * Total Submissions: 543.7K
 * Testcase Example:  '[1,2]\nnode with value 1\nnode with value 2'
 *
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 *
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 *
 * ⁠       _______3______
 * ⁠      /              \
 * ⁠   ___5__          ___1__
 * ⁠  /      \        /      \
 * ⁠  6      _2       0       8
 * ⁠        /  \
 * ⁠        7   4
 *
 *
 *
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another
 * example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of
 * itself according to the LCA definition.
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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || p == root || q == root) {
      return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    if (left != nullptr && left != p && left != q) {
      return left;
    }

    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (right != nullptr && right != p && right != q) {
      return right;
    }

    if (left != nullptr && right != nullptr) {
      return root;
    }
    return left != nullptr ? left : right;
  }
};