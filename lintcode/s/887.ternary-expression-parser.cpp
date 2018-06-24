#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  /**
   * @param expression: a string, denote the ternary expression
   * @return: a string
   */
  string parseTernary(const string &expression) {
    stack<char> s;

    for (auto it = expression.crbegin(); it != expression.crend(); ++it) {
      if (!s.empty() && s.top() == '?') {
        char op1 = *it;

        s.pop(); // pop question mark
        char op2 = s.top();
        s.pop();
        s.pop();
        char op3 = s.top();
        s.pop();

        if (op1 == 'T') {
          s.push(op2);
        } else {
          s.push(op3);
        }
      } else {
        s.push(*it);
      }
      cout << "last: " << *it << "->" << s.top() << endl;
      ;
    }

    cout << "Final top: " << s.top() << endl;
    return string(1, s.top());
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.parseTernary("F?1:T?3:1") << endl;
}
#endif
