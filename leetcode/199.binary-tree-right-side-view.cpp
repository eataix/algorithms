#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;
/*
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (43.08%)
 * Total Accepted:    112.7K
 * Total Submissions: 261.7K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    recursive(root, 0, res);
    return res;
  }

  void recursive(TreeNode *root, int level, vector<int> &res) {
    if (root == nullptr) {
      return;
    }

    if (level == res.size()) {
      res.push_back(root->val);
    }

    recursive(root->right, level + 1, res);
    recursive(root->left, level + 1, res);
  }
};
