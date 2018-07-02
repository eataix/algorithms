class Solution {
public:
  /**
   * @param s: the given expression
   * @return: the result of expression
   */
  int calculate(string &s) {
    istringstream in{'+' + s + '+'};
    int res = 0;
    int term = 0;
    char op;
    while (in >> op) {
      if (op == '+' || op == '-') {
        res += term;
        in >> term;
        if (op == '-') {
          term *= -1;
        }
      } else {
        int n;
        in >> n;

        if (op == '*') {
          term *= n;
        } else {
          term /= n;
        }
      }
    }
    return res;
  }
};
