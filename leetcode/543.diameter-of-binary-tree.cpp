#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (44.90%)
 * Total Accepted:    56.5K
 * Total Submissions: 125.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
  int depth(TreeNode *root, int &res) {
    if (root == nullptr) {
      return 0;
    }

    auto l = depth(root->left, res);
    auto r = depth(root->right, res);
    res = max(res, l + r + 1);

    return max(l, r) + 1;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int res = 0;
    depth(root, res);
    return res - 1;
  }
};
