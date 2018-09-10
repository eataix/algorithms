#include <vector>
using namespace std;
/*
 * [904] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (61.31%)
 * Total Accepted:    13.8K
 * Total Submissions: 22.7K
 * Testcase Example:
 * '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree.  From left to right order, the
 * values of those leaves form a leaf value sequence.
 *
 *
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 *
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 *
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 *
 *
 *
 * Note:
 *
 *
 * Both of the given trees will have between 1 and 100 nodes.
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
  void dfs(TreeNode *node, vector<int> &v) {
    if (node == nullptr) {
      return;
    }

    if (node->left == nullptr && node->right == nullptr) {
      v.push_back(node->val);
      return;
    }

    dfs(node->left, v);
    dfs(node->right, v);
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> v1;
    vector<int> v2;
    dfs(root1, v1);
    dfs(root2, v2);
    return v1 == v2;
  }
};
