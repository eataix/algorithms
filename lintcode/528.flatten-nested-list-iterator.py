from collections import deque


class NestedIterator(object):
    def __init__(self, nestedList):
        self.q = deque()
        for l in nestedList:
            self.q.append(l)

    # @return {int} the next element in the iteration
    def next(self):
        return self.q.popleft().getInteger()

    # @return {boolean} true if the iteration has more element or false
    def hasNext(self):
        while len(self.q) > 0:
            ni = self.q[0]

            if ni.isInteger():
                return True
            self.q.popleft()
            l = ni.getList()
            for i in reversed(l):
                self.q.appendleft(i)
        return False
