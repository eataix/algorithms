if __name__ == '__main__':

    class TreeNode:
        def __init__(self, val):
            self.val = val
            self.left, self.right = None, None


class Solution:
    """
    @param root: the given BST
    @param target: the given target
    @return: the value in the BST that is closest to the target
    """

    def closestValue(self, root, target):
        bestV = None
        bestD = None

        while root is not None:
            d = abs(root.val - target)
            if bestD is None or d < bestD:
                bestV = root.val
                bestD = d
            if target < root.val:
                root = root.left
            elif target > root.val:
                root = root.right
            else:
                return target

        return bestV
