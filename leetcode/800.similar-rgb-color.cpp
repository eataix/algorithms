#include <iostream>
#include <string>
using namespace std;
/*
 * [818] Similar RGB Color
 *
 * https://leetcode.com/problems/similar-rgb-color/description/
 *
 * algorithms
 * Easy (54.43%)
 * Total Accepted:    4.3K
 * Total Submissions: 7.8K
 * Testcase Example:  '"#09f166"'
 *
 * In the following, every capital letter represents some hexadecimal digit
 * from 0 to f.
 *
 * The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.
 * For example, "#15c" is shorthand for the color "#1155cc".
 *
 * Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB -
 * UV)^2 - (CD - WX)^2 - (EF - YZ)^2.
 *
 * Given the color "#ABCDEF", return a 7 character color that is most similar
 * to #ABCDEF, and has a shorthand (that is, it can be represented as some
 * "#XYZ"
 *
 *
 * Example 1:
 * Input: color = "#09f166"
 * Output: "#11ee66"
 * Explanation:
 * The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64
 * -9 -0 = -73.
 * This is the highest among any shorthand color.
 *
 *
 * Note:
 *
 *
 * color is a string of length 7.
 * color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from
 * 0 to f
 * Any answer which has the same (highest) similarity as the best answer will
 * be accepted.
 * All inputs and outputs should use lowercase letters, and the output is 7
 * characters.
 *
 *
 */
class Solution {
  string dec_to_hex = "0123456789abcdef";
  string helper(const string &str) {

    int dec_num = stoi(str, 0, 16);
    int q = dec_num / 17;

    if ((dec_num % 17) > 8) {
      q += 1;
    }

    string res = "";
    res = res + dec_to_hex[q] + dec_to_hex[q];

    return res;
  }

public:
  string similarRGB(string color) {
    return '#' + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) +
           helper(color.substr(5, 2));
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.similarRGB("#09f166") << endl;
}
#endif
