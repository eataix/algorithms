#include <vector>
#include <algorithm>
using namespace std;
/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.73%)
 * Total Accepted:    235.3K
 * Total Submissions: 592.3K
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        vector<int> result;
        for (auto it = digits.crbegin(); it != digits.crend(); ++it)
        {
            int newDigit = (*it) + carry;
            if (newDigit >= 10)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            result.push_back(newDigit % 10);
        }
        if (carry == 1)
        {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
