#include<stack>
#include<string>
using namespace std;
/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.45%)
 * Total Accepted:    133.1K
 * Total Submissions: 567.6K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
      int left = 0;
      int right = 0;
      int maxLen = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
          left += 1;
        } else {
          right += 1;
        }

        if (left == right) {
          maxLen = max(maxLen, 2 * right);
        } else if (right > left) {
          left = right = 0;
        }
      }
      left = right = 0;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '(') {
          left += 1;
        } else {
          right += 1;
        }

        if (left == right) {
          maxLen = max(maxLen, 2 * left);
        } else if (left > right) {
          left = right = 0;
        }
      }
      return maxLen;
    }



    int longestValidParentheses2(string s) {
      int res = 0;
      stack<int> st;

      st.push(-1);

      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
          st.push(i);
        } else {
          st.pop();
          if (st.empty()) {
            st.push(i);
          } else {
            res = max(res, i - st.top());
          }
        }
      }
      return res;
    }
};
