#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
/*
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (44.76%)
 * Total Accepted:    49.2K
 * Total Submissions: 110K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 *
 * For example, the above binary watch reads "3:25".
 *
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 *
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 *
 *
 * Note:
 *
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 *
 *
 */
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for (int i = 0; i < 720; ++i) {
      int hours = i / 60;
      int minutes = i % 60;

      int h = bitset<4>(hours).count();
      int m = bitset<6>(minutes).count();

      if (h + m == num) {
        string str;
        str += to_string(hours);

        str += ':';
        if (minutes < 10) {
          str += '0';
        }
        str += to_string(minutes);
        res.push_back(str);
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  auto res = sol.readBinaryWatch(1);
  for (auto r : res) {
    cout << r << " ";
  }
  cout << endl;
}
#endif
