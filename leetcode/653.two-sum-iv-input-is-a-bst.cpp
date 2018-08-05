#include <vector>
using namespace std;
/*
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (50.38%)
 * Total Accepted:    50.3K
 * Total Submissions: 99.8K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 *
 * Example 1:
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 9
 *
 * Output: True
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 28
 *
 * Output: False
 *
 *
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
  void inorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }

public:
  bool findTarget(TreeNode *root, int k) {
    vector<int> res;
    inorder(root, res);

    int left = 0;
    int right = res.size() - 1;

    while (left < right) {
      int currSum = res[left] + res[right];

      if (currSum == k) {
        return true;
      }

      if (currSum < k) {
        left += 1;
      }

      if (currSum > k) {
        right -= 1;
      }
    }

    return false;
  }
};
