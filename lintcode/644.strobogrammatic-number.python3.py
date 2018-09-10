class Solution:
    """
    @param num: a string
    @return: true if a number is strobogrammatic or false
    """

    def isStrobogrammatic(self, num):
        m = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}

        for l, r in zip(num, num[::-1]):
            if l not in m or m[l] != r:
                return False

        return True
