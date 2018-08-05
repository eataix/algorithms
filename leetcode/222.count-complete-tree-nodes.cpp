#include <cmath>
using namespace std;
/*
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (28.31%)
 * Total Accepted:    84.2K
 * Total Submissions: 297.3K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 *
 * Note:
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2h nodes inclusive at the last level h.
 *
 * Example:
 *
 *
 * Input:
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 *
 * Output: 6
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
  int leftHeight(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + leftHeight(root->left);
  }

  int rightHeight(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + rightHeight(root->right);
  }

public:
  int countNodes(TreeNode *root) {
    auto hLeft = leftHeight(root);
    auto hRight = rightHeight(root);

    if (hLeft == hRight) {
      return pow(2, hLeft) - 1;
    } else {
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
  }
};
