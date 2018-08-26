#include <string>
using namespace std;
/*
 * [604] Design Compressed String Iterator
 *
 * https://leetcode.com/problems/design-compressed-string-iterator/description/
 *
 * algorithms
 * Easy (33.56%)
 * Total Accepted:    9.4K
 * Total Submissions: 27.9K
 * Testcase Example:
 * '["StringIterator","next","next","next","next","next","next","hasNext","next","hasNext"]\n[["L1e2t1C1o1d1e1"],[],[],[],[],[],[],[],[],[]]'
 *
 *
 * Design and implement a data structure for a compressed string iterator. It
 * should support the following operations: next and hasNext.
 *
 *
 *
 * The given compressed string will be in the form of each letter followed by a
 * positive integer representing the number of this letter existing in the
 * original uncompressed string.
 *
 *
 *
 * next() - if the original string still has uncompressed characters, return
 * the next letter; Otherwise return a white space.
 * hasNext() - Judge whether there is any letter needs to be uncompressed.
 *
 *
 *
 * Note:
 * Please remember to RESET your class variables declared in StringIterator, as
 * static/class variables are persisted across multiple test cases. Please see
 * here for more details.
 *
 *
 *
 * Example:
 *
 * StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");
 *
 * iterator.next(); // return 'L'
 * iterator.next(); // return 'e'
 * iterator.next(); // return 'e'
 * iterator.next(); // return 't'
 * iterator.next(); // return 'C'
 * iterator.next(); // return 'o'
 * iterator.next(); // return 'd'
 * iterator.hasNext(); // return true
 * iterator.next(); // return 'e'
 * iterator.hasNext(); // return false
 * iterator.next(); // return ' '
 *
 *
 */
class StringIterator {
  int idx = 0;
  int repeat = 0;
  string str;
  char ch;

public:
  StringIterator(string compressedString) : str(compressedString) {
    if (!str.empty()) {
      ch = str[0];
    }
  }

  char next() {
    if (!hasNext()) {
      return ' ';
    }

    if (repeat == 0) {
      ch = str[idx++];
      int num = 0;
      while (idx < str.size() && isdigit(str[idx])) {
        num = num * 10 + str[idx] - '0';
        idx += 1;
      }
      repeat = num;
    }
    repeat -= 1;
    return ch;
  }

  bool hasNext() { return repeat != 0 || idx < str.size(); }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
