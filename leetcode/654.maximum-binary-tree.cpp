#include <algorithm>
#include <vector>
using namespace std;
/*
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (70.76%)
 * Total Accepted:    41.8K
 * Total Submissions: 59K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 *
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 *
 * The root is the maximum number in the array.
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number.
 *
 *
 *
 *
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 *
 *
 * Example 1:
 *
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 *
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    /
 * ⁠    2  0
 * ⁠      \
 * ⁠       1
 *
 *
 *
 * Note:
 *
 * The size of the given array will be in the range [1,1000].
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
  TreeNode *construct(const vector<int> &nums,
                      const vector<int>::const_iterator &begin,
                      const vector<int>::const_iterator &end) {
    if (begin == end) {
      return nullptr;
    }

    auto max_it = max_element(begin, end);

    auto root = new TreeNode(*max_it);
    root->left = construct(nums, begin, max_it);
    root->right = construct(nums, max_it + 1, end);
    return root;
  }

public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return construct(nums, nums.cbegin(), nums.cend());
  }
};
