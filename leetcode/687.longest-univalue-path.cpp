#include <algorithm>

using namespace std;
/*
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (32.81%)
 * Total Accepted:    28K
 * Total Submissions: 85.4K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 *
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input:
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 *
 *
 *
 *
 * Output:
 *
 * 2
 *
 *
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input:
 *
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 *
 *
 *
 *
 * Output:
 *
 * 2
 *
 *
 *
 * Note:
 * The given binary tree has not more than 10000 nodes.  The height of the tree
 * is not more than 1000.
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
public:
  int longestUnivaluePath(TreeNode *root) {
    int ans = 0;
    helper(root, ans);
    return ans;
  }

private:
  int helper(TreeNode *node, int &ans) {
    if (node == nullptr) {
      return 0;
    }

    int left = helper(node->left, ans);
    int right = helper(node->right, ans);

    int leftVal = 0;
    int rightVal = 0;

    if (node->left != nullptr && node->left->val == node->val) {
      leftVal = left + 1;
    }
    if (node->right != nullptr && node->right->val == node->val) {
      rightVal = right + 1;
    }

    ans = max(ans, leftVal + rightVal);

    return max(leftVal, rightVal);
  }
};
