#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
/*
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (69.52%)
 * Total Accepted:    147.9K
 * Total Submissions: 212.8K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are
 * different.
 *
 *
 */
class Solution {
public:
  int hammingDistance(int x, int y) {
    if ((x ^ y) == 0) {
      return 0;
    } else {
      return (x ^ y) % 2 + hammingDistance(x / 2, y / 2);
    }
  }

  int hammingDistance2(int x, int y) {
    string str = bitset<32>(x ^ y).to_string();
#ifdef DEBUG
    cout << str << endl;
#endif
    return count(str.cbegin(), str.cend(), '1');
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.hammingDistance(1, 4) << endl;
}
#endif
