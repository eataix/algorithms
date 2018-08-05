#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [787] Sliding Puzzle
 *
 * https://leetcode.com/problems/sliding-puzzle/description/
 *
 * algorithms
 * Hard (46.43%)
 * Total Accepted:    5K
 * Total Submissions: 10.6K
 * Testcase Example:  '[[1,2,3],[4,0,5]]'
 *
 * On a 2x3 board, there are 5 tiles represented by the integers 1 through 5,
 * and an empty square represented by 0.
 *
 * A move consists of choosing 0 and a 4-directionally adjacent number and
 * swapping it.
 *
 * The state of the board is solved if and only if the board is
 * [[1,2,3],[4,5,0]].
 *
 * Given a puzzle board, return the least number of moves required so that the
 * state of the board is solved. If it is impossible for the state of the board
 * to be solved, return -1.
 *
 * Examples:
 *
 *
 * Input: board = [[1,2,3],[4,0,5]]
 * Output: 1
 * Explanation: Swap the 0 and the 5 in one move.
 *
 *
 *
 * Input: board = [[1,2,3],[5,4,0]]
 * Output: -1
 * Explanation: No number of moves will make the board solved.
 *
 *
 *
 * Input: board = [[4,1,2],[5,0,3]]
 * Output: 5
 * Explanation: 5 is the smallest number of moves that solves the board.
 * An example path:
 * After move 0: [[4,1,2],[5,0,3]]
 * After move 1: [[4,1,2],[0,5,3]]
 * After move 2: [[0,1,2],[4,5,3]]
 * After move 3: [[1,0,2],[4,5,3]]
 * After move 4: [[1,2,0],[4,5,3]]
 * After move 5: [[1,2,3],[4,5,0]]
 *
 *
 *
 * Input: board = [[3,2,4],[1,5,0]]
 * Output: 14
 *
 *
 * Note:
 *
 *
 * board will be a 2 x 3 array as described above.
 * board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
 *
 */
class Solution {
  vector<vector<int>> moves{{1, 3}, {0, 2, 4}, {1, 5},
                            {0, 4}, {3, 5, 1}, {4, 2}};

public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string s = to_string(board[0][0]) + to_string(board[0][1]) +
               to_string(board[0][2]) + to_string(board[1][0]) +
               to_string(board[1][1]) + to_string(board[1][2]);
    unordered_set<string> seen;
    queue<pair<pair<string, int>, int>> q;
    q.push({{s, s.find('0')}, 0});
    seen.insert(s);

    while (!q.empty()) {
      auto currState = q.front().first.first;
      auto currZeroLoc = q.front().first.second;
      auto currDist = q.front().second;
      q.pop();

      if (currState == "123450") {
        return currDist;
      }

      for (auto newZeroLoc : moves[currZeroLoc]) {
        auto newState = currState;
        swap(newState[currZeroLoc], newState[newZeroLoc]);

        if (!seen.count(newState)) {
          seen.insert(newState);
          q.push({{newState, newZeroLoc}, currDist + 1});
        }
      }
    }
    return -1;
  }
};
