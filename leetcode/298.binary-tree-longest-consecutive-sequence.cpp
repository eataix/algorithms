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

class Solution {
  int dfs(TreeNode *node, TreeNode *parent, int len) {
    if (node == nullptr) {
      return len;
    }

    len = (parent != nullptr && node->val == parent->val + 1) ? len + 1 : 1;
    return max(len,
               max(dfs(node->left, node, len), dfs(node->right, node, len)));
  }

public:
  int longestConsecutive(TreeNode *root) { return dfs(root, nullptr, 0); }
};
