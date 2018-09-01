#
# [687] Longest Univalue Path
#
# https://leetcode.com/problems/longest-univalue-path/description/
#
# algorithms
# Easy (32.81%)
# Total Accepted:    28K
# Total Submissions: 85.4K
# Testcase Example:  '[5,4,5,1,1,5]'
#
# Given a binary tree, find the length of the longest path where each node in
# the path has the same value. This path may or may not pass through the root.
#
# Note: The length of path between two nodes is represented by the number of
# edges between them.
#
#
# Example 1:
#
#
#
#
# Input:
#
# ⁠             5
# ⁠            / \
# ⁠           4   5
# ⁠          / \   \
# ⁠         1   1   5
#
#
#
#
# Output:
#
# 2
#
#
#
#
# Example 2:
#
#
#
#
# Input:
#
# ⁠             1
# ⁠            / \
# ⁠           4   5
# ⁠          / \   \
# ⁠         4   4   5
#
#
#
#
# Output:
#
# 2
#
#
#
# Note:
# The given binary tree has not more than 10000 nodes.  The height of the tree
# is not more than 1000.
#
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        res = 0

        def helper(root):
            if root is None:
                return 0
            l = helper(root.left)
            r = helper(root.right)

            lValue = l + 1 if root.left is not None and root.left.val == root.val else 0
            rValue = r + 1 if root.right is not None and root.right.val == root.val else 0
            nonlocal res
            res = max(res, lValue + rValue)
            return max(lValue, rValue)

        helper(root)
        return res
