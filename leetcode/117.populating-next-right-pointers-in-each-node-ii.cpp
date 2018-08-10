/*
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (33.67%)
 * Total Accepted:    142.4K
 * Total Submissions: 422.9K
 * Testcase Example:  '{}'
 *
 * Given a binary tree
 *
 *
 * struct TreeLinkNode {
 * ⁠ TreeLinkNode *left;
 * ⁠ TreeLinkNode *right;
 * ⁠ TreeLinkNode *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 *
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 *
 *
 * Example:
 *
 * Given the following binary tree,
 *
 *
 * ⁠    1
 * ⁠  /  \
 * ⁠ 2    3
 * ⁠/ \    \
 * 4   5    7
 *
 *
 * After calling your function, the tree should look like:
 *
 *
 * ⁠    1 -> NULL
 * ⁠  /  \
 * ⁠ 2 -> 3 -> NULL
 * ⁠/ \    \
 * 4-> 5 -> 7 -> NULL
 *
 *
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#ifdef DEBUG
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
#endif

class Solution {
public:
  void connect(TreeLinkNode *root) {
    auto dummy = new TreeLinkNode(-1);
    auto t = dummy;
    while (root != nullptr) {
      if (root->left != nullptr) {
        t->next = root->left;
        t = t->next;
      }

      if (root->right != nullptr) {
        t->next = root->right;
        t = t->next;
      }

      root = root->next;
      if (root == nullptr) {
        t = dummy;
        root = dummy->next;
        dummy->next = nullptr;
      }
    }
  }
};
