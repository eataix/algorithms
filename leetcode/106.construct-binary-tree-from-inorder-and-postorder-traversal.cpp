#include <vector>
using namespace std;
/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (34.47%)
 * Total Accepted:    113.1K
 * Total Submissions: 327.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
  TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight,
                      vector<int> &postorder, int pLeft, int pRight) {
    if (iLeft > iRight || pLeft > pRight)
      return NULL;
    TreeNode *cur = new TreeNode(postorder[pRight]);
    int i = 0;
    for (i = iLeft; i < inorder.size(); ++i) {
      if (inorder[i] == cur->val)
        break;
    }
    cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft,
                          pLeft + i - iLeft - 1);
    cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft,
                           pRight - 1);
    return cur;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1);
  }
};
