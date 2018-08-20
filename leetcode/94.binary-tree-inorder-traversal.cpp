#include <stack>
#include <vector>
using namespace std;
/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (51.62%)
 * Total Accepted:    318.9K
 * Total Submissions: 617.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
  void helper(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }

    helper(root->left, res);
    res.push_back(root->val);
    helper(root->right, res);
  }

public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> st;

    auto curr = root;
    while (curr != nullptr || !st.empty()) {
      while (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      }

      curr = st.top();
      st.pop();
      res.push_back(curr->val);
      curr = curr->right;
    }

    return res;
  }

  vector<int> inorderTraversal1(TreeNode *root) {
    vector<int> res;
    helper(root, res);
    return res;
  }
};
