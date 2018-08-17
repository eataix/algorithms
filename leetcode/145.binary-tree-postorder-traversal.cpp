#include <stack>
#include <vector>
using namespace std;
/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (43.82%)
 * Total Accepted:    196K
 * Total Submissions: 447.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [3,2,1]
 *
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
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> nodes;
    stack<TreeNode *> st;
    auto curr = root;
    TreeNode *last = nullptr;

    while (curr != nullptr || !st.empty()) {
      if (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      } else {
        auto top = st.top();
        if (top->right != nullptr && last != top->right) {
          curr = top->right;
        } else {
          nodes.push_back(top->val);
          last = top;
          st.pop();
        }
      }
    }
    return nodes;
  }
};
