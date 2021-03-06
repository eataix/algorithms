#
# [298] Binary Tree Longest Consecutive Sequence
#
# https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
#
# algorithms
# Medium (42.08%)
# Total Accepted:    47.6K
# Total Submissions: 113K
# Testcase Example:  '[1,null,3,2,4,null,null,null,5]'
#
# Given a binary tree, find the length of the longest consecutive sequence
# path.
#
# The path refers to any sequence of nodes from some starting node to any node
# in the tree along the parent-child connections. The longest consecutive path
# need to be from parent to child (cannot be the reverse).
#
# Example 1:
#
#
# Input:
#
# ⁠  1
# ⁠   \
# ⁠    3
# ⁠   / \
# ⁠  2   4
# ⁠       \
# ⁠        5
#
# Output: 3
#
# Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
#
# Example 2:
#
#
# Input:
#
# ⁠  2
# ⁠   \
# ⁠    3
# ⁠   /
# ⁠  2
# ⁠ /
# ⁠1
#
# Output: 2
#
# Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return
# 2.
#
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def longestConsecutive(self, root):
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

            lValue = 1
            rValue = 1

            if root.left is not None and root.left.val == root.val + 1:
                lValue = l + 1

            if root.right is not None and root.right.val == root.val + 1:
                rValue = r + 1

            nonlocal res
            res = max(res, max(lValue, rValue))
            return max(lValue, rValue)

        helper(root)
        return res
