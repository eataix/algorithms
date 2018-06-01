class Solution:
    """
    @param expression: a string, denote the ternary expression
    @return: a string
    """

    def parseTernary(self, expression):
        stack = []
        for c in expression[::-1]:
            if len(stack) > 0 and stack[-1] == '?':
                stack.pop()  # pop '?'

                op2 = stack[-1]
                stack.pop()  # pop op2
                stack.pop()  # pop ':'
                op3 = stack[-1]
                stack.pop()  # pop op3

                if c == 'T':
                    stack.append(op2)
                else:
                    stack.append(op3)
            else:
                stack.append(c)
        return stack[0]
