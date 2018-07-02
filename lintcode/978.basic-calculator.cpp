#include <stack>
using namespace std;
class Solution {
public:
  /**
   * @param s: the given expression
   * @return: the result of expression
   */
  int calculate(string &s) {
    stack<int> st;
    int res = 0;
    int sign = 1;
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];

      if (isdigit(ch)) {
        int num = ch - '0';
        while (i + 1 < s.size() && isdigit(s[i + 1])) {
          num *= 10;
          num += s[i + 1] - '0';
          i += 1;
        }
        res += num * sign;
      } else if (ch == '+') {
        sign = 1;
      } else if (ch == '-') {
        sign = -1;
      } else if (ch == '(') {
        st.push(res);
        st.push(sign);
        res = 0;
        sign = 1;
      } else if (ch == ')') {
        res *= st.top();
        st.pop();
        res += st.top();
        st.pop();
      }
    }
    return res;
  }
};
