#include <vector>
using namespace std;
/*
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (44.76%)
 * Total Accepted:    64.4K
 * Total Submissions: 143.9K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 *
 *
 *
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 *
 *
 * Example 1:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \
 * ⁠    3   1
 *
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 *
 * Example 2:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \
 * ⁠1   3   1
 *
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
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
  int rob(TreeNode *root) {
    auto res = helper(root);
    return max(res[0], res[1]);
  }

  vector<int> helper(TreeNode *node) {
    if (node == nullptr) {
      return {0, 0};
    }

    auto left = helper(node->left);
    auto right = helper(node->right);

    vector<int> res(2);

    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = node->val + left[0] + right[0];

    return res;
  }
};
