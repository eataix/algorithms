#include <algorithm>
#include <stack>
#include <string>
using namespace std;
/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (34.04%)
 * Total Accepted:    197K
 * Total Submissions: 578.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 */
class Solution
{
  public:
    string addBinary(string a, string b)
    {
        stack<char> res;
        int carry = 0;
        int i;
        int j;
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i -= 1, j -= 1)
        {
            int x = a[i] - '0';
            int y = b[j] - '0';
            int sum = x + y + carry;
            char ch;
            if (sum >= 2)
            {
                ch = sum % 2 + '0';
                carry = 1;
            }
            else
            {
                ch = sum + '0';
                carry = 0;
            }
            res.push(ch);
        }
        while (i >= 0)
        {
            int x = a[i] - '0';
            int sum = x + carry;
            char ch;
            if (sum == 2)
            {
                ch = '0';
                carry = 1;
            }
            else
            {
                ch = sum + '0';
                carry = 0;
            }
            res.push(ch);
            i -= 1;
        }
        while (j >= 0)
        {
            int y = b[j] - '0';
            int sum = y + carry;
            char ch;
            if (sum == 2)
            {
                ch = '0';
                carry = 1;
            }
            else
            {
                ch = sum + '0';
                carry = 0;
            }
            res.push(ch);
            j -= 1;
        }

        if (carry == 1)
        {
            res.push('1');
        }

        string result;
        while (!res.empty())
        {
            result += res.top();
            res.pop();
        }
        return result;
    }
};

#ifdef DEBUG
#include <iostream>
int main()
{
    Solution sol;
    cout << sol.addBinary("1", "111") << endl;
}
#endif