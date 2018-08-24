#include <algorithm>
using namespace std;
/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (33.88%)
 * Total Accepted:    229.8K
 * Total Submissions: 678.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * return its minimum depth = 2.
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
      return 1;
    } else if (root->left == nullptr) {
      return minDepth(root->right) + 1;
    } else if (root->right == nullptr) {
      return minDepth(root->left) + 1;
    } else {
      return 1 + min(minDepth(root->left), minDepth(root->right));
    }
  }
};
