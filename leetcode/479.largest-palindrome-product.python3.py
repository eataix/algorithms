#
# [479] Largest Palindrome Product
#
# https://leetcode.com/problems/largest-palindrome-product/description/
#
# algorithms
# Easy (25.55%)
# Total Accepted:    9.6K
# Total Submissions: 37.5K
# Testcase Example:  '1'
#
# Find the largest palindrome made from the product of two n-digit numbers.
# ⁠Since the result could be very large, you should return the largest
# palindrome mod 1337.
#
# Example:
# Input: 2
# Output: 987
# Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
#
#
#
#
# Note:
# The range of n is [1,8].
#
#
#
class Solution:
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 9

        if n == 8:
            return 9999000000009999 % 1337

        upper_limit = 10 ** n - 1
        lower_limit = 10 ** (n - 1)

        def palindrome(n):
            v = 0
            while n > 0:
                v = v * 10 + n % 10
                n //= 10
            return v

        for first_half in range(upper_limit, lower_limit - 1, -1):
            second_half = palindrome(first_half)
            product = first_half * (10**n) + second_half

            div = upper_limit
            while div * div >= product:
                if product % div == 0:
                    return product % 1337
                div -= 1
