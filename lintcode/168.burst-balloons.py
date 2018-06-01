class Solution:
    """
    @param nums: A list of integer
    @return: An integer, maximum coins
    """

    def maxCoins(self, nums):
        oldN = len(nums)
        nums = [1] + nums + [1]

        dp = [[0] * len(nums) for _ in range(len(nums))]

        for length in range(1, oldN + 1):
            for start in range(1, oldN + 1):
                end = start + length - 1
                if end > oldN:
                    break
                for k in range(start, end + 1):
                    dp[start][end] = max(
                        dp[start][end], dp[start][k - 1] + dp[k + 1][end] +
                        nums[start - 1] * nums[end + 1] * nums[k])

        return dp[1][oldN]
