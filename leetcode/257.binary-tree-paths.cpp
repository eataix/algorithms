#include <string>
#include <vector>
using namespace std;
/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (42.27%)
 * Total Accepted:    170.3K
 * Total Submissions: 402.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
  void helper(const TreeNode *root, vector<string> &res, string out) {
    if (root == nullptr) {
      return;
    }

    if (root->left == nullptr && root->right == nullptr) {
      res.push_back(out + to_string(root->val));
      return;
    }

    helper(root->left, res, out + to_string(root->val) + "->");
    helper(root->right, res, out + to_string(root->val) + "->");
  }

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    string out;
    helper(root, res, out);
    return res;
  }
};
