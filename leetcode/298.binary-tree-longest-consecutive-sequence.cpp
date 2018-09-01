#include <algorithm>
using namespace std;
/*
 * [298] Binary Tree Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (42.08%)
 * Total Accepted:    47.6K
 * Total Submissions: 113K
 * Testcase Example:  '[1,null,3,2,4,null,null,null,5]'
 *
 * Given a binary tree, find the length of the longest consecutive sequence
 * path.
 *
 * The path refers to any sequence of nodes from some starting node to any node
 * in the tree along the parent-child connections. The longest consecutive path
 * need to be from parent to child (cannot be the reverse).
 *
 * Example 1:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   / \
 * ⁠  2   4
 * ⁠       \
 * ⁠        5
 *
 * Output: 3
 *
 * Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
 *
 * Example 2:
 *
 *
 * Input:
 *
 * ⁠  2
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * ⁠ /
 * ⁠1
 *
 * Output: 2
 *
 * Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return
 * 2.
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  int helper(TreeNode *root, int &res) {
    if (root == nullptr) {
      return 0;
    }
    auto l = helper(root->left, res);
    auto r = helper(root->right, res);

    int lValue = 1;
    int rValue = 1;
    if (root->left != nullptr && root->left->val == root->val + 1) {
      lValue = l + 1;
    }
    if (root->right != nullptr && root->right->val == root->val + 1) {
      rValue = r + 1;
    }
    res = max(res, lValue);
    res = max(res, rValue);

    return max(lValue, rValue);
  }

public:
  int longestConsecutive(TreeNode *root) {
    int res = 0;
    helper(root, res);
    return res;
  }
};
