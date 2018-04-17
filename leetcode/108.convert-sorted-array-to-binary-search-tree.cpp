#include <vector>
using namespace std;
/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (44.64%)
 * Total Accepted:    172.2K
 * Total Submissions: 385.8K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 *
 *
 *
 * Example:
 *
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
  TreeNode *sortedArrayToBST(const vector<int> &nums) {
    return sortedArrayToBSTWithIndices(nums, 0, nums.size() - 1);
  }

  TreeNode *sortedArrayToBSTWithIndices(const vector<int> &nums, int start,
                                        int end) {
    if (start > end) {
      return nullptr;
    }
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTWithIndices(nums, start, mid - 1);
    root->right = sortedArrayToBSTWithIndices(nums, mid + 1, end);
    return root;
  }
};
