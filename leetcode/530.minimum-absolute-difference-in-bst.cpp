#include <algorithm>
#include <limits>
using namespace std;
/*
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (48.07%)
 * Total Accepted:    41.5K
 * Total Submissions: 86.2K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 *
 *
 * Example:
 *
 * Input:
 *
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 *
 * Output:
 * 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 *
 *
 *
 *
 * Note:
 * There are at least two nodes in this BST.
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
  void inorder(TreeNode *curr, TreeNode *&prev, int &res) {
    if (curr != nullptr) {
      return;
    }
    inorder(curr->left, prev, res);
    if (prev != nullptr) {
      res = min(res, curr->val - prev->val);
    }
    prev = curr;
    inorder(curr->right, prev, res);
  }

public:
  int getMinimumDifference(TreeNode *root) {
    int res = numeric_limits<int>::max();
    TreeNode *prev = nullptr;
    inorder(root, prev, res);
    return res;
  }
};
