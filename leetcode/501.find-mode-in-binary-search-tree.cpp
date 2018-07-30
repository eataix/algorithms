#include <vector>
using namespace std;
/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (37.82%)
 * Total Accepted:    39K
 * Total Submissions: 103K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * For example:
 * Given BST [1,null,2,2],
 *
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 *
 *
 *
 *
 * return [2].
 *
 * Note: If a tree has more than one mode, you can return them in any order.
 *
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
  void helper(TreeNode *node, TreeNode *&pre, int &cnt, int &maxV,
              vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    helper(node->left, pre, cnt, maxV, res);
    if (pre != nullptr) {
      cnt = (node->val == pre->val) ? cnt + 1 : 1;
    }

    if (cnt >= maxV) {
      if (cnt > maxV) {
        res.clear();
      }
      res.push_back(node->val);
      maxV = cnt;
    }
    pre = node;
    helper(node->right, pre, cnt, maxV, res);
  }

public:
  vector<int> findMode(TreeNode *root) {
    vector<int> res;
    int maxV = 0;
    int cnt = 1;
    TreeNode *pre = nullptr;
    helper(root, pre, cnt, maxV, res);
    return res;
  }
};
