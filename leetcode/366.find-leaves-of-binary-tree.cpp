#include <vector>
using namespace std;
/*
 * [366] Find Leaves of Binary Tree
 *
 * https://leetcode.com/problems/find-leaves-of-binary-tree/description/
 *
 * algorithms
 * Medium (61.56%)
 * Total Accepted:    28.5K
 * Total Submissions: 46.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a binary tree, collect a tree's nodes as if you were doing this:
 * Collect and remove all leaves, repeat until the tree is empty.
 *
 *
 *
 * Example:
 * Given binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Returns [4, 5, 3], [2], [1].
 *
 *
 *
 * Explanation:
 *
 * 1. Removing the leaves [4, 5, 3] would result in this tree:
 *
 * ⁠         1
 * ⁠        /
 * ⁠       2
 *
 *
 *
 * 2. Now removing the leaf [2] would result in this tree:
 *
 * ⁠         1
 *
 *
 *
 * 3. Now removing the leaf [1] would result in the empty tree:
 *
 * ⁠         []
 *
 *
 *
 *
 * Returns [4, 5, 3], [2], [1].
 *
 *
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
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
  vector<vector<int>> findLeaves(TreeNode *root) {
    vector<vector<int>> res;
    helper(root, res);
    return res;
  }

  int helper(TreeNode *node, vector<vector<int>> &res) {
    if (node == nullptr) {
      return -1;
    }

    int depth = 1 + max(helper(node->left, res), helper(node->right, res));

    if (depth >= res.size()) {
      res.resize(depth + 1);
    }

    res[depth].push_back(node->val);
    return depth;
  }
};
