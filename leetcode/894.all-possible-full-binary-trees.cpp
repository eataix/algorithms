#include <vector>
using namespace std;
/*
 * [930] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (58.35%)
 * Total Accepted:    1.2K
 * Total Submissions: 2K
 * Testcase Example:  '7'
 *
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 *
 * Return a list of all possible full binary trees with N nodes.  Each element
 * of the answer is the root node of one possible tree.
 *
 * Each node of each tree in the answer must have node.val = 0.
 *
 * You may return the final list of trees in any order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * Explanation:
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 20
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
  vector<TreeNode *> allPossibleFBT(int N) {
    if (N % 2 == 0) {
      return {};
    }
    if (N == 1) {
      return {new TreeNode(0)};
    }

    vector<TreeNode *> res;
    for (int leftTreeSize = 1; leftTreeSize < N; leftTreeSize += 2) {
      for (auto const &leftTree : allPossibleFBT(leftTreeSize)) {
        for (auto const &rightTree : allPossibleFBT(N - leftTreeSize - 1)) {
          res.push_back(new TreeNode(0));
          res.back()->left = leftTree;
          res.back()->right = rightTree;
        }
      }
    }

    return res;
  }
};
