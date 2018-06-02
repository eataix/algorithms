class Solution:
    """
    @param num: a string
    @param k: an integer
    @return: return a string
    """

    def removeKdigits(self, num, k):
        from collections import deque

        q = deque()

        keep = len(num) - k

        for n in num:
            while k > 0 and len(q) > 0 and n < q[-1]:
                q.pop()
                k -= 1
            q.append(n)

        while len(q) > 0 and q[0] == '0':
            q.popleft()

        if len(q) == 0:
            return "0"
        else:
            return "".join(q)[:keep]
