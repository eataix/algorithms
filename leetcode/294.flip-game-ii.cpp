#include <string>
using namespace std;
/*
 * [294] Flip Game II
 *
 * https://leetcode.com/problems/flip-game-ii/description/
 *
 * algorithms
 * Medium (47.16%)
 * Total Accepted:    35.5K
 * Total Submissions: 75.3K
 * Testcase Example:  '"++++"'
 *
 * You are playing the following Flip Game with your friend: Given a string
 * that contains only these two characters: + and -, you and your friend take
 * turns to flip two consecutive "++" into "--". The game ends when a person
 * can no longer make a move and therefore the other person will be the
 * winner.
 *
 * Write a function to determine if the starting player can guarantee a win.
 *
 * Example:
 *
 *
 * Input: s = "++++"
 * Output: true
 * Explanation: The starting player can guarantee a win by flipping the middle
 * "++" to become "+--+".
 *
 *
 * Follow up:
 * Derive your algorithm's runtime complexity.
 *
 */
class Solution {
public:
  bool canWin(string s) {
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '+' && s[i - 1] == '+' &&
          !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
        return true;
      }
    }
    return false;
  }
};
