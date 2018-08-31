#
# [199] Binary Tree Right Side View
#
# https://leetcode.com/problems/binary-tree-right-side-view/description/
#
# algorithms
# Medium (43.08%)
# Total Accepted:    112.7K
# Total Submissions: 261.7K
# Testcase Example:  '[1,2,3,null,5,null,4]'
#
# Given a binary tree, imagine yourself standing on the right side of it,
# return the values of the nodes you can see ordered from top to bottom.
#
# Example:
#
#
# Input: [1,2,3,null,5,null,4]
# Output: [1, 3, 4]
# Explanation:
#
# ⁠  1            <---
# ⁠/   \
# 2     3         <---
# ⁠\     \
# ⁠ 5     4       <---
#
#
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        def dfs(node, nodes, level):
            if node is None:
                return
            if len(nodes) == level:
                nodes.append(node.val)
            dfs(node.right, nodes, level + 1)
            dfs(node.left, nodes, level + 1)

        nodes = []
        dfs(root, nodes, 0)
        return nodes
