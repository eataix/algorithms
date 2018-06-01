class Solution:
    """
    @param num: Given the candidate numbers
    @param target: Given the target number
    @return: All the combinations that sum to target
    """

    def combinationSum2(self, num, target):
        output = []
        res = []

        def combinationSum2DFS(num, target, start):
            if target == 0:
                res.append(list(output))
                return
            elif target < 0:
                return
            else:
                for i in range(start, len(num)):
                    if i > start and num[i] == num[i - 1]:
                        continue
                    output.append(num[i])
                    combinationSum2DFS(num, target - num[i], i + 1)
                    output.pop()

        num.sort()
        combinationSum2DFS(num, target, 0)
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.combinationSum2([7, 1, 2, 5, 1, 6, 10], 8))
