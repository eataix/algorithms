#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*
 * [479] Largest Palindrome Product
 *
 * https://leetcode.com/problems/largest-palindrome-product/description/
 *
 * algorithms
 * Easy (25.55%)
 * Total Accepted:    9.6K
 * Total Submissions: 37.5K
 * Testcase Example:  '1'
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 * ⁠Since the result could be very large, you should return the largest
 * palindrome mod 1337.
 *
 * Example:
 * Input: 2
 * Output: 987
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 *
 *
 *
 *
 * Note:
 * The range of n is [1,8].
 *
 *
 */
class Solution
{
    long long palindrome(long long n)
    {
        long long newV = 0;
        while (n > 0)
        {
            newV = newV * 10 + n % 10;
            n /= 10;
        }
        return newV;
    }

  public:
    int largestPalindrome(int n)
    {
        if (n == 1)
        {
            return 9;
        }

        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);

        long long product;
        for (int firstHalf = upper; firstHalf >= lower; --firstHalf)
        {
            long long secondHalf = palindrome(firstHalf);
            product = pow(10, n) * firstHalf + secondHalf;

            for (long i = upper; i * i >= product; --i)
            {
                if (product % i == 0)
                {
                    cout << firstHalf << " " << secondHalf << " " << product << endl;
                    cout << "product: " << product << " i: " << i << " j: " << product / i << endl;
                    return product % 1337;
                }
            }
        }
    }
};

#ifdef DEBUG
int main()
{
    Solution sol;
    cout << sol.largestPalindrome(1) << endl;
    cout << sol.largestPalindrome(2) << endl;
    cout << sol.largestPalindrome(3) << endl;
    cout << sol.largestPalindrome(4) << endl;
    cout << sol.largestPalindrome(5) << endl;
    cout << sol.largestPalindrome(6) << endl;
    cout << sol.largestPalindrome(7) << endl;
    cout << sol.largestPalindrome(8) << endl;
}
#endif