class Solution {
  double myPower(double x, long long p) {
    if (p == 0) {
      return 1;
    }
    if (p < 0) {
      return 1.0 / myPower(x, -p);
    }

    double residual = 1.0;

    while (p > 1) {
      if (p % 2 == 1) {
        residual *= x;
      }

      x *= x;
      p /= 2;
    }

    return residual * x;
  }

public:
  /**
   * @param x: the base number
   * @param n: the power number
   * @return: the result
   */
  double myPow(double x, int n) { return myPower(x, n); }
};
