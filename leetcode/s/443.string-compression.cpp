#include <iostream>
#include <vector>
using namespace std;
/*
 * [443] String Compression
 *
 * https://leetcode.com/problems/string-compression/description/
 *
 * algorithms
 * Easy (36.01%)
 * Total Accepted:    18.6K
 * Total Submissions: 51.7K
 * Testcase Example:  '['a','a','b','b','c','c','c']'
 *
 * Given an array of characters, compress it in-place.
 *
 * The length after compression must always be smaller than or equal to the
 * original array.
 *
 * Every element of the array should be a character (not int) of length 1.
 * ⁠
 * After you are done modifying the input array in-place, return the new length
 * of the array.
 *
 *
 *
 * Follow up:
 * Could you solve it using only O(1) extra space?
 *
 *
 *
 *
 * Example 1:
 *
 * Input:
 * ['a','a','b','b','c','c','c']
 *
 * Output:
 * Return 6, and the first 6 characters of the input array should be:
 * ['a','2','b','2','c','3']
 *
 * Explanation:
 * 'aa' is replaced by 'a2'. 'bb' is replaced by 'b2'. 'ccc' is replaced by
 * 'c3'.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ['a']
 *
 * Output:
 * Return 1, and the first 1 characters of the input array should be: ['a']
 *
 * Explanation:
 * Nothing is replaced.
 *
 *
 *
 * Example 3:
 *
 * Input:
 * ['a','b','b','b','b','b','b','b','b','b','b','b','b']
 *
 * Output:
 * Return 4, and the first 4 characters of the input array should be:
 * ['a','b','1','2'].
 *
 * Explanation:
 * Since the character 'a' does not repeat, it is not compressed.
 * 'bbbbbbbbbbbb' is replaced by 'b12'.
 * Notice each digit has it's own entry in the array.
 *
 *
 *
 * Note:
 *
 * All characters have an ASCII value in [35, 126].
 * 1 .
 *
 *
 */
class Solution {
public:
  int compress(vector<char> &chars) {
    if (chars.size() <= 1) {
      return chars.size();
    }

    char prevChar = chars[0];
    int count = 1;
    int lastWrite = 1;
    for (int i = 1; i < chars.size(); ++i) {
      char currChar = chars[i];
      if (currChar != prevChar) {
        if (count > 1) {
          string s = to_string(count);
          for (const char &c : s) {
            chars[lastWrite++] = c;
          }
        }
        chars[lastWrite++] = currChar;
        prevChar = currChar;
        count = 1;
      } else {
        count += 1;
      }
    }
    if (count > 1) {
      string s = to_string(count);
      for (const char &c : s) {
        chars[lastWrite++] = c;
      }
    }

    return lastWrite;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<char> s1{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  int a = sol.compress(s1);
  for (int i = 0; i < a; ++i) {
    cout << s1[i] << ' ';
  }
  cout << endl;
  vector<char> s2{'a'};
  int b = sol.compress(s2);
  for (int i = 0; i < b; ++i) {
    cout << s2[i] << ' ';
  }
  cout << endl;

  vector<char> s3{'a', 'b', 'b', 'b', 'b', 'b', 'b',
                  'b', 'b', 'b', 'b', 'b', 'b'};
  int c = sol.compress(s3);
  for (int i = 0; i < c; ++i) {
    cout << s3[i] << ' ';
  }
  cout << endl;
}

#endif
