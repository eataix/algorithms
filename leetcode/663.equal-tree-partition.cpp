#include <vector>
using namespace std;
/*
 * [663] Equal Tree Partition
 *
 * https://leetcode.com/problems/equal-tree-partition/description/
 *
 * algorithms
 * Medium (36.35%)
 * Total Accepted:    8.5K
 * Total Submissions: 23.5K
 * Testcase Example:  '[5,10,10,null,null,2,3]'
 *
 *
 * Given a binary tree with n nodes, your task is to check if it's possible to
 * partition the tree to two trees which have the equal sum of values after
 * removing exactly one edge on the original tree.
 *
 *
 * Example 1:
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 10 10
 * ⁠   /  \
 * ⁠  2   3
 *
 * Output: True
 * Explanation:
 * ⁠   5
 * ⁠  /
 * ⁠ 10
 * ⁠
 * Sum: 15
 *
 * ⁠  10
 * ⁠ /  \
 * ⁠2    3
 *
 * Sum: 15
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ⁠   1
 * ⁠  / \
 * ⁠ 2  10
 * ⁠   /  \
 * ⁠  2   20
 *
 * Output: False
 * Explanation: You can't split the tree into two trees with equal sum after
 * removing exactly one edge on the tree.
 *
 *
 *
 * Note:
 *
 * The range of tree node value is in the range of [-100000, 100000].
 * 1
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
public:
  bool checkEqualTree(TreeNode *root) {
    vector<int> s;

    int total = sum(root, s);
    s.pop_back();
    if (total % 2 == 0) {
      for (int i : s) {
        if (i == total / 2) {
          return true;
        }
      }
    }

    return false;
  }

  int sum(TreeNode *root, vector<int> &s) {
    if (root == nullptr) {
      return 0;
    }

    int total = sum(root->left, s) + sum(root->right, s) + root->val;
    s.push_back(total);
    return total;
  }
};
