"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param root: the root of tree
    @return: the vertical order traversal
    """

    def verticalOrder(self, root):
        if root is None:
            return []
        m = dict()
        minLeft = 0
        maxLeft = 0

        import queue
        q = queue.Queue()

        q.put((root, 0))
        while not q.empty():
            curr_node, level = q.get()
            if level not in m:
                m[level] = []
            m[level].append(curr_node.val)

            minLeft = min(minLeft, level)
            maxLeft = max(maxLeft, level)

            if curr_node.left is not None:
                q.put((curr_node.left, level - 1))
            if curr_node.right is not None:
                q.put((curr_node.right, level + 1))
        res = []
        for i in range(minLeft, maxLeft + 1):
            res.append(m[i])
        return res
