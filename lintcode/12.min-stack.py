class MinStack:
    def __init__(self):
        self.data_stack = []
        self.min_stack = []

    """
    @param: number: An integer
    @return: nothing
    """

    def push(self, number):
        if number <= min_stack[-1]:
            self.min_stack.append(number)
        self.data_stack.append(number)

    """
    @return: An integer
    """

    def pop(self):
        t = self.data_stack[-1]
        if t == self.min_stack[-1]:
            self.min_stack.pop()
        self.data_stack.pop()

    """
    @return: An integer
    """

    def min(self):
        return self.min_stack[-1]


if __name__ == '__main__':
    s = MinStack()
    s.push(1)
    s.pop()
    s.push(2)
    s.push(3)
    s.min()
    s.push(1)
    s.min()
