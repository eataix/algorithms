#include<string>
#include<algorithm>
using namespace std;
/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (60.70%)
 * Total Accepted:    261.2K
 * Total Submissions: 430.2K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * 
 * Example:
 * Given s = "hello", return "olleh".
 * 
 */
class Solution {
public:
    string reverseString(string s) {
	    int left = 0;
	    int right = s.size() -1;
	    while (left < right) {
		    swap(s[left], s[right]);

		    left += 1;
		    right -= 1;
	    }
	    return s;
    }
};
