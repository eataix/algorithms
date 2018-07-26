#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (37.93%)
 * Total Accepted:    17.3K
 * Total Submissions: 45.7K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them.
 *
 * Two trees are duplicate if they have the same structure with same node
 * values.
 *
 * Example 1:
 *
 *
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 *
 *
 * The following are two duplicate subtrees:
 *
 *
 * ⁠     2
 * ⁠    /
 * ⁠   4
 *
 *
 * and
 *
 *
 * ⁠   4
 *
 * Therefore, you need to return above trees' root in the form of a list.
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
  string serialize(TreeNode *node,
                   unordered_map<string, vector<TreeNode *>> &m) {
    if (node == nullptr) {
      return "";
    }

    auto s = "(" + serialize(node->left, m) + to_string(node->val) +
             serialize(node->right, m) + ")";
    m[s].push_back(node);
    return s;
  }

public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string, vector<TreeNode *>> m;
    vector<TreeNode *> dups;
    serialize(root, m);

    for (auto const &kv : m) {
      if (kv.second.size() > 1) {
        dups.push_back(kv.second.front());
      }
    }
    return dups;
  }
};
