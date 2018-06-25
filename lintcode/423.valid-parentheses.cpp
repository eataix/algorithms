#include <stack>
using namespace std;

class Solution {
public:
  /**
   * @param s: A string
   * @return: whether the string is a valid parentheses
   */
  bool isValidParentheses(string &s) {
    stack<char> st;

    for (char ch : s) {
      switch (ch) {
      case '(':
        st.push(')');
        break;
      case '[':
        st.push(']');
        break;
      case '{':
        st.push('}');
        break;
      default:
        if (st.empty() || st.top() != ch) {
          return false;
        } else {
          st.pop();
        }
      }
    }
    return st.empty();
  }
};
