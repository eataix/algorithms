/*
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (44.80%)
 * Total Accepted:    36.7K
 * Total Submissions: 81.9K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 *
 *
 *
 * 'A' : Absent.
 * 'L' : Late.
 * ⁠'P' : Present.
 *
 *
 *
 *
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 *
 * Example 1:
 *
 * Input: "PPALLP"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "PPALLL"
 * Output: False
 *
 *
 *
 *
 *
 */

class Solution {
public:
  bool checkRecord(string s) {
    int cA = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'A' && ++cA > 1) {
        return false;
      }
      if (s[i] == 'L' && i + 2 < s.size() && s[i + 1] == 'L' &&
          s[i + 2] == 'L') {
        return false;
      }
    }
    return true;
  }
};
