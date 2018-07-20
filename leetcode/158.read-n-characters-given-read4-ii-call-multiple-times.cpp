/*
 * [158] Read N Characters Given Read4 II - Call multiple times
 *
 * https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/description/
 *
 * algorithms
 * Hard (24.50%)
 * Total Accepted:    44.4K
 * Total Submissions: 181.2K
 * Testcase Example:  '""\n[read(0)]'
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 *
 * The return value is the actual number of characters read. For example, it
 * returns 3 if there is only 3 characters left in the file.
 *
 * By using the read4 API, implement the function int read(char *buf, int n)
 * that reads n characters from the file.
 *
 * Note:
 * The read function may be called multiple times.
 *
 * Example 1: 
 *
 *
 * Given buf = "abc"
 * read("abc", 1) // returns "a"
 * read("abc", 2); // returns "bc"
 * read("abc", 1); // returns ""
 *
 *
 * Example 2: 
 *
 *
 * Given buf = "abc"
 * read("abc", 4) // returns "abc"
 * read("abc", 1); // returns ""
 *
 *
 */
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  int readPos = 0;
  int writePos = 0;
  char buff[4];

public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    for (int i = 0; i < n; ++i) {
      if (readPos == writePos) {
        writePos = read4(buff);
        readPos = 0;
        if (writePos == 0) {
          return i;
        }
      }
      buf[i] = buff[readPos++];
    }
    return n;
  }
};
