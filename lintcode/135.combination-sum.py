class Solution:
    """
    @param candidates: A list of integers
    @param target: An integer
    @return: A list of lists of integers
    """

    def combinationSum(self, candidates, target):
        curr = []
        res = []

        def combinationSumDFS(candidates, target, start):
            if target == 0:
                res.append(list(curr))
                return
            elif target < 0:
                return
            else:
                for i in range(start, len(candidates)):
                    curr.append(candidates[i])
                    combinationSumDFS(candidates, target - candidates[i], i)
                    curr.pop()

        combinationSumDFS(sorted(candidates), target, 0)
        return res


if __name__ == '__main__':
    res = Solution().combinationSum([2, 3, 6, 7], 7)
    print(res)
