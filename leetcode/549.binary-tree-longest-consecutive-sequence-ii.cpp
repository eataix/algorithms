#include <algorithm>
#include <utility>
using namespace std;
/*
 * [549] Binary Tree Longest Consecutive Sequence II
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/
 *
 * algorithms
 * Medium (42.73%)
 * Total Accepted:    9.6K
 * Total Submissions: 22.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a binary tree, you need to find the length of Longest Consecutive Path
 * in Binary Tree.
 *
 * Especially, this path can be either increasing or decreasing. For example,
 * [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is
 * not valid. On the other hand, the path can be in the child-Parent-child
 * order, where not necessarily be parent-child order.
 *
 * Example 1:
 *
 * Input:
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * Output: 2
 * Explanation: The longest consecutive path is [1, 2] or [2, 1].
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ⁠       2
 * ⁠      / \
 * ⁠     1   3
 * Output: 3
 * Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 *
 *
 *
 * Note:
 * All the values of tree nodes are in the range of [-1e7, 1e7].
 * ⁠
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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
  pair<int, int> dfs(TreeNode *root, int &longest) {
    if (root == nullptr) {
      return {0, 0};
    }
    int inc = 1;
    int dcr = 1;
    if (root->left) {
      auto l = dfs(root->left, longest);
      if (root->val == root->left->val + 1) {
        dcr = l.second + 1;
      } else if (root->val == root->left->val - 1) {
        inc = l.first + 1;
      }
    }
    if (root->right) {
      auto r = dfs(root->right, longest);
      if (root->val == root->right->val + 1) {
        dcr = max(dcr, r.second + 1);
      } else if (root->val == root->right->val - 1) {
        inc = max(inc, r.first + 1);
      }
    }

    longest = max(longest, dcr + inc - 1);
    return {inc, dcr};
  }

public:
  int longestConsecutive(TreeNode *root) {
    int longest = 0;
    dfs(root, longest);
    return longest;
  }
};
