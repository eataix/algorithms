#include <stack>
#include <string>
#ifdef DEBUG
#include <iostream>
#endif
using namespace std;

class Solution {
public:
  /**
   * @param expression: a string, denote the ternary expression
   * @return: a string
   */
  string parseTernary(const string &expression) {
    stack<char> st;

    for (auto it = expression.crbegin(); it != expression.crend(); ++it) {
      if (!st.empty() && st.top() == '?') {
        st.pop(); // pop '?'
        char op2 = st.top();
        st.pop(); // pop op2
        st.pop(); // pop ':'
        char op3 = st.top();
        st.pop(); // pop op3

        st.push(*it == 'T' ? op2 : op3);
      } else {
        st.push(*it);
      }
    }

    return st.empty() ? "" : string(1, st.top());
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.parseTernary("T?2:3") << endl;
  cout << sol.parseTernary("F?1:T?4:5") << endl;
  cout << sol.parseTernary("T?T?F:5:3") << endl;
}
#endif
