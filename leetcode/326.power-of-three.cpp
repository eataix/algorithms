#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (40.75%)
 * Total Accepted:    124.8K
 * Total Submissions: 306.3K
 * Testcase Example:  '27'
 *
 * 
 * ⁠   Given an integer, write a function to determine if it is a power of
 * three.
 * 
 * 
 * ⁠   Follow up:
 * ⁠   Could you do it without using any loop / recursion?
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        int maxV;

        int prev = 1;
        for (;;) {
            int v = prev * 3;
            if (prev != v / 3) {
                maxV = prev;
                break;
            }
            prev = v;
        }
        cout << maxV <<endl;

        return maxV % n == 0;
    }
};

#ifdef DEBUG
int main () {
    Solution sol;
    sol.isPowerOfThree(3);
}
#endif
