#include <algorithm>
#include <limits>
using namespace std;
/*
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (42.00%)
 * Total Accepted:    27.3K
 * Total Submissions: 65.1K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 *
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes.
 *
 *
 *
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree.
 *
 *
 *
 * If no such second minimum value exists, output -1 instead.
 *
 *
 * Example 1:
 *
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 *
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 *
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
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

public:
  int findSecondMinimumValue(TreeNode *root) {
    if (root == nullptr) {
      return -1;
    }
    return dfs(root, root->val);
  }

  int dfs(TreeNode *node, int smallest) {
    if (node == nullptr)
      return -1;
    if (node->val != smallest) {
      return node->val;
    }
    int left = dfs(node->left, smallest);
    int right = dfs(node->right, smallest);

    if (left == -1) {
      return right;
    }
    if (right == -1) {
      return left;
    }
    return min(left, right);
  }
};
