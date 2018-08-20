#include <vector>
using namespace std;
/*
 * [925] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (44.13%)
 * Total Accepted:    970
 * Total Submissions: 2.2K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 *
 * Values in the traversals pre and post are distinct positive integers.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    if (pre.empty()) {
      return nullptr;
    }
    vector<TreeNode *> s;
    s.push_back(new TreeNode(pre[0]));
    for (int i = 1, j = 0; i < pre.size(); ++i) {
      auto node = new TreeNode(pre[i]);
      while (s.back()->val == post[j]) {
        s.pop_back();
        j += 1;
      }
      if (s.back()->left == nullptr) {
        s.back()->left = node;
      } else {
        s.back()->right = node;
      }
      s.push_back(node);
    }
    return s[0];
  }
};
