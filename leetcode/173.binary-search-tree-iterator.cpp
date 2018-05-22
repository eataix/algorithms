#include <stack>
using namespace std;
/*
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (43.66%)
 * Total Accepted:    129.4K
 * Total Submissions: 296.4K
 * Testcase Example:  '[]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
/**
 * Definition for binary tree
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
class BSTIterator {
  stack<TreeNode *> parents;

public:
  BSTIterator(TreeNode *root) {
    while (root != nullptr) {
      parents.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !parents.empty(); }

  /** @return the next smallest number */
  int next() {
    TreeNode *curr = parents.top();
    parents.pop();
    int res = curr->val;
    if (curr->right != nullptr) {
      curr = curr->right;
      while (curr != nullptr) {
        parents.push(curr);
        curr = curr->left;
      }
    }
    return res;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
