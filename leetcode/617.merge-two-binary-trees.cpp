/*
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (67.60%)
 * Total Accepted:    90.2K
 * Total Submissions: 133.3K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 *
 * Given two binary trees and imagine that when you put one of them to cover
 * the other, some nodes of the two trees are overlapped while the others are
 * not.
 *
 *
 * You need to merge them into a new binary tree. The merge rule is that if two
 * nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * Tree 1                     Tree 2
 * ⁠         1                         2
 * ⁠        / \                       / \
 * ⁠       3   2                     1   3
 * ⁠      /                           \   \
 * ⁠     5                             4   7
 * Output:
 * Merged tree:
 * 3
 * / \
 * 4   5
 * / \   \
 * 5   4   7
 *
 *
 *
 *
 * Note:
 * The merging process must start from the root nodes of both trees.
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
class Solution {
public:
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {}
};
