class Solution {
public:
  /**
   * @param a: a number
   * @param b: a number
   * @return: the result
   */
  string addBinary(string &a, string &b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
      int op1 = i >= 0 ? a[i] - '0' : 0;
      int op2 = j >= 0 ? b[j] - '0' : 0;

      int sum = op1 + op2 + carry;
      carry = sum >= 2;
      res += '0' + (sum & 1);

      i -= 1;
      j -= 1;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
