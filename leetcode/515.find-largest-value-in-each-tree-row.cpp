#include<vector>
#include<algorithm>
using namespace std;
/*
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (55.92%)
 * Total Accepted:    43.8K
 * Total Submissions: 78.3K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
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
  void helper(TreeNode *node, int level, vector<int> &res) {
    if (node == nullptr) {
      return;
    }

    if (res.size() < level + 1) {
      res.push_back(node->val);
    } else {
      solution[level] = max(solution[level], node->val);
    }

    helper(node->left, level + 1);
    helper(node->right, level + 1);
  }
public:
    vector<int> largestValues(TreeNode* root) {
      if (root == nullptr) {
        return {};
      }
      vector<int> solution;
      helper(root, 0, solution);
      return solution;
    }
};
