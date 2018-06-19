#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [293] Flip Game
 *
 * https://leetcode.com/problems/flip-game/description/
 *
 * algorithms
 * Easy (57.43%)
 * Total Accepted:    33.7K
 * Total Submissions: 58.6K
 * Testcase Example:  '"++++"'
 *
 * You are playing the following Flip Game with your friend: Given a string
 * that contains only these two characters: + and -, you and your friend take
 * turns to flip two consecutive "++" into "--". The game ends when a person
 * can no longer make a move and therefore the other person will be the
 * winner.
 *
 * Write a function to compute all possible states of the string after one
 * valid move.
 *
 * Example:
 *
 *
 * Input: s = "++++"
 * Output:
 * [
 * ⁠ "--++",
 * ⁠ "+--+",
 * ⁠ "++--"
 * ]
 *
 *
 * Note: If there is no valid move, return an empty list [].
 *
 */
class Solution {
public:
  vector<string> generatePossibleNextMoves(const string &s) {
    if (s.empty()) {
      return {};
    }
    string str{s};
    vector<string> res;
    for (int i = 0; i < str.size() - 1; ++i) {
      if (str[i] == '+' && str[i + 1] == '+') {
        res.push_back(str);
        res.back()[i] = res.back()[i + 1] = '-';
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  auto results = sol.generatePossibleNextMoves("++++");
  for (auto r : results) {
    cout << r << " ";
  }
  cout << endl;
}
#endif
