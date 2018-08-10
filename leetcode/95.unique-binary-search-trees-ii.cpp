/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (32.87%)
 * Total Accepted:    109K
 * Total Submissions: 330.9K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
  vector<TreeNode *> helper(int start, int end) {
    if (start > end) {
      return {nullptr};
    }
    if (start == end) {
      return {new TreeNode{start}};
    }
    vector<TreeNode *> res;
    for (int i = start; i <= end; ++i) {
      auto subList1 = helper(start, i - 1);
      auto subList2 = helper(i + 1, end);
      for (auto const &t1 : subList1) {
        for (auto const &t2 : subList2) {
          auto newNode = new TreeNode(i);
          newNode->left = t1;
          newNode->right = t2;
          res.push_back(newNode);
        }
      }
    }
    return res;
  }

public:
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0) {
      return {};
    }
    return helper(1, n);
  }
};
