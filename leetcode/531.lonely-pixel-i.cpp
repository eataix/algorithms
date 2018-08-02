#include <vector>
using namespace std;
/*
 * [531] Lonely Pixel I
 *
 * https://leetcode.com/problems/lonely-pixel-i/description/
 *
 * algorithms
 * Medium (56.47%)
 * Total Accepted:    12.7K
 * Total Submissions: 22.5K
 * Testcase Example:  '[["W","W","B"],["W","B","W"],["B","W","W"]]'
 *
 * Given a picture consisting of black and white pixels, find the number of
 * black lonely pixels.
 *
 * The picture is represented by a 2D char array consisting of 'B' and 'W',
 * which means black and white pixels respectively.
 *
 * A black lonely pixel is character 'B' that located at a specific position
 * where the same row and same column don't have any other black pixels.
 *
 * Example:
 *
 * Input:
 * [['W', 'W', 'B'],
 * ⁠['W', 'B', 'W'],
 * ⁠['B', 'W', 'W']]
 *
 * Output: 3
 * Explanation: All the three 'B's are black lonely pixels.
 *
 *
 *
 * Note:
 *
 * The range of width and height of the input 2D array is [1,500].
 *
 *
 */
class Solution {
public:
  int findLonelyPixel(vector<vector<char>> &picture) {
    if (picture.empty() || picture[0].empty()) {
      return 0;
    }
    int numRows = picture.size();
    int numCols = picture[0].size();

    vector<int> rows(numRows, 0);
    vector<int> cols(numCols, 0);

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (picture[r][c] == 'B') {
          rows[r] += 1;
          cols[c] += 1;
        }
      }
    }
    int res = 0;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (picture[r][c] == 'B' && rows[r] == 1 && cols[c] == 1) {
          res += 1;
        }
      }
    }
    return res;
  }
};
