#include <limits>
#include <vector>
using namespace std;
/*
 * [333] Largest BST Subtree
 *
 * https://leetcode.com/problems/largest-bst-subtree/description/
 *
 * algorithms
 * Medium (31.50%)
 * Total Accepted:    23.1K
 * Total Submissions: 73.4K
 * Testcase Example:  '[10,5,15,1,8,null,7]'
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree
 * (BST), where largest means subtree with largest number of nodes in it.
 *
 * Note:
 * A subtree must include all of its descendants.
 *
 * Example:
 *
 *
 * Input: [10,5,15,1,8,null,7]
 *
 * ⁠  10
 * ⁠  / \
 * ⁠ 5  15
 * ⁠/ \   \
 * 1   8   7
 *
 * Output: 3
 * Explanation: The Largest BST Subtree in this case is the highlighted one.
 * ⁠            The return value is the subtree's size, which is 3.
 *
 *
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
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
  bool isValidBST(TreeNode *root, int &minVal, int &maxVal, int &res) {
    if (root == nullptr) {
      return true;
    }

    int left_n = 0;
    int right_n = 0;
    int left_min = numeric_limits<int>::min();
    int right_min = numeric_limits<int>::min();
    int left_max = numeric_limits<int>::max();
    int right_max = numeric_limits<int>::max();

    bool left = isValidBST(root->left, left_min, left_max, left_n);
    bool right = isValidBST(root->right, right_min, right_max, right_n);

    if (left && right) {
      if ((root->left == nullptr || root->val > left_max) &&
          (root->right == nullptr || root->val < right_min)) {
        res = left_n + right_n + 1;
        minVal = root->left != nullptr ? left_min : root->val;
        maxVal = root->right != nullptr ? right_max : root->val;
        return true;
      }
    }
    res = max(left_n, right_n);
    return false;
  }

public:
  int largestBSTSubtree(TreeNode *root) {
    int res = 0;
    int minVal = numeric_limits<int>::min();
    int maxVal = numeric_limits<int>::max();
    isValidBST(root, minVal, maxVal, res);
    return res;
  }
};
