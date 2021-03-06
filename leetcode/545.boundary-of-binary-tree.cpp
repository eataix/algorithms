#include <vector>
using namespace std;
/*
 * [545] Boundary of Binary Tree
 *
 * https://leetcode.com/problems/boundary-of-binary-tree/description/
 *
 * algorithms
 * Medium (32.64%)
 * Total Accepted:    10.6K
 * Total Submissions: 32.4K
 * Testcase Example:  '[1,null,2,3,4]'
 *
 * Given a binary tree, return the values of its boundary in anti-clockwise
 * direction starting from root.
 * Boundary includes left boundary, leaves, and right boundary in order without
 * duplicate nodes.
 *
 * Left boundary is defined as the path from root to the left-most node. Right
 * boundary is defined as the path from root to the right-most node. If the
 * root doesn't have left subtree or right subtree, then the root itself is
 * left boundary or right boundary. Note this definition only applies to the
 * input binary tree, and not applies to any subtrees.
 *
 * The left-most node is defined as a leaf node you could reach when you always
 * firstly travel to the left subtree if exists. If not, travel to the right
 * subtree. Repeat until you reach a leaf node.
 *
 * The right-most node is also defined by the same way with left and right
 * exchanged.
 *
 *
 * Example 1
 *
 * Input:
 * ⁠ 1
 * ⁠  \
 * ⁠   2
 * ⁠  / \
 * ⁠ 3   4
 *
 * Ouput:
 * [1, 3, 4, 2]
 *
 * Explanation:
 * The root doesn't have left subtree, so the root itself is left boundary.
 * The leaves are node 3 and 4.
 * The right boundary are node 1,2,4. Note the anti-clockwise direction means
 * you should output reversed right boundary.
 * So order them in anti-clockwise without duplicates and we have
 * [1,3,4,2].
 *
 *
 *
 *
 * Example 2
 *
 * Input:
 * ⁠   ____1_____
 * ⁠  /          \
 * ⁠ 2            3
 * ⁠/ \          /
 * 4   5        6
 * ⁠  / \      / \
 * ⁠ 7   8    9  10
 * ⁠
 * Ouput:
 * [1,2,4,7,8,9,10,6,3]
 *
 * Explanation:
 * The left boundary are node 1,2,4. (4 is the left-most node according to
 * definition)
 * The leaves are node 4,7,8,9,10.
 * The right boundary are node 1,3,6,10. (10 is the right-most node).
 * So order them in anti-clockwise without duplicate nodes we have
 * [1,2,4,7,8,9,10,6,3].
 *
 *
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
  vector<int> boundaryOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> res{root->val};

    helper(root->left, true, false, res);
    helper(root->right, false, true, res);
    return res;
  }

  void helper(TreeNode *node, bool left, bool right, vector<int> &res) {
    if (node == nullptr) {
      return;
    }

    if (node->left == nullptr && node->right == nullptr) {
      res.push_back(node->val);
      return;
    }

    if (left) {
      res.push_back(node->val);
    }

    helper(node->left, left && node->left != nullptr,
           right && node->right == nullptr, res);
    helper(node->right, left && node->left == nullptr,
           right && node->right != nullptr, res);

    if (right) {
      res.push_back(node->val);
    }
  }
};
