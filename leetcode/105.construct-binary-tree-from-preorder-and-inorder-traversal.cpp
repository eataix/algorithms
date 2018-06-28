/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (34.35%)
 * Total Accepted:    139.7K
 * Total Submissions: 406.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1);
  }

  TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight,
                      vector<int> &inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight) {
      return nullptr;
    }

    int i = iLeft;

    for (; i <= iRight; ++i) {
      if (preorder[pLeft] == inorder[i]) {
        break;
      }
    }

    TreeNode *curr = new TreeNode(preorder[pLeft]);

    curr->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder,
                           iLeft, i - 1);
    cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder,
                           i + 1, iRight);
    return cur;
  }
};
