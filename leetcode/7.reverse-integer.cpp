/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.37%)
 * Total Accepted:    394.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 * Input: 123
 * Output:  321
 *
 *
 *
 * Example 2:
 *
 * Input: -123
 * Output: -321
 *
 *
 *
 * Example 3:
 *
 * Input: 120
 * Output: 21
 *
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only hold integers
 * within the 32-bit signed integer range. For the purpose of this problem,
 * assume that your function returns 0 when the reversed integer overflows.
 *
 */
class Solution
{
  public:
    int reverse(int x)
    {
        bool negative = false;
        if (x < 0)
        {
            negative = true;
            x = -x;
        }
        int prev_rev_num = 0;
        int rev_num = 0;
        while (x != 0)
        {
            int curr_digit = x % 10;
            rev_num = (rev_num * 10) + curr_digit;
            if ((rev_num - curr_digit) / 10 != prev_rev_num)
            {
                return 0;
            }
            prev_rev_num = rev_num;
            x /= 10;
        }

        return negative ? -rev_num : rev_num;
    }
};
