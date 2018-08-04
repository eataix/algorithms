#include <algorithm>
#include <vector>
using namespace std;
/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (31.77%)
 * Total Accepted:    93.8K
 * Total Submissions: 295.3K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Example 1:
 *
 *
 * Input: [1,3,null,null,2]
 *
 * 1
 * /
 * 3
 * \
 * 2
 *
 * Output: [3,1,null,null,2]
 *
 * 3
 * /
 * 1
 * \
 * 2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,1,4,null,null,2]
 *
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 *
 * Output: [2,1,4,null,null,3]
 *
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 *
 *
 * Follow up:
 *
 *
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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
  void inorder(TreeNode *root, vector<TreeNode *> &list, vector<int> &vals) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left, list, vals);
    list.push_back(root);
    vals.push_back(root->val);
    inorder(root->right, list, vals);
  }

public:
  void recoverTree(TreeNode *root) {
    vector<TreeNode *> list;
    vector<int> vals;
    inorder(root, list, vals);
    sort(vals.begin(), vals.end());
    for (int i = 0; i < list.size(); ++i) {
      list[i]->val = vals[i];
    }
  }
};
