#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (66.72%)
 * Total Accepted:    30.7K
 * Total Submissions: 46K
 * Testcase Example:  '1\n22'
 *
 *
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 *
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 *
 * Also, a self-dividing number is not allowed to contain the digit zero.
 *
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 *
 * Example 1:
 *
 * Input:
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 *
 *
 *
 * Note:
 * The boundaries of each input argument are 1 .
 *
 */
class Solution {
  bool isSelfDividing(int i) {
    string str = to_string(i);
    for (char ch : str) {
      int v = ch - '0';
      if (v == 0 || i % v != 0) {
        return false;
      }
    }
    return true;
  }

public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for (int i = left; i <= right; ++i) {
      if (isSelfDividing(i)) {
        res.push_back(i);
      }
    }
#ifdef DEBUG
    for (auto r : res) {
      cout << r << " ";
    }
    cout << endl;
#endif

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.selfDividingNumbers(1, 22);
}
#endif
