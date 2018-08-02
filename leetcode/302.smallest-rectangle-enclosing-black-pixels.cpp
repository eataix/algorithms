#include <vector>
using namespace std;
/*
 * [302] Smallest Rectangle Enclosing Black Pixels
 *
 * https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/description/
 *
 * algorithms
 * Hard (47.18%)
 * Total Accepted:    18.6K
 * Total Submissions: 39.5K
 * Testcase Example:
 * '[["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]]\n0\n2'
 *
 * An image is represented by a binary matrix with 0 as a white pixel and 1 as
 * a black pixel. The black pixels are connected, i.e., there is only one black
 * region. Pixels are connected horizontally and vertically. Given the location
 * (x, y) of one of the black pixels, return the area of the smallest
 * (axis-aligned) rectangle that encloses all black pixels.
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠ "0010",
 * ⁠ "0110",
 * ⁠ "0100"
 * ]
 * and x = 0, y = 2
 *
 * Output: 6
 *
 *
 */
class Solution {
  int searchRows(const vector<vector<char>> &image, int i, int j, int low,
                 int high, bool opt) {
    while (i != j) {
      int k = low;
      int mid = (i + j) / 2;

      while (k < high && image[mid][k] == '0') {
        k += 1;
      }

      if (k < high == opt) {
        j = mid;
      } else {
        i = mid + 1;
      }
    }
    return i;
  }

  int searchCols(const vector<vector<char>> &image, int i, int j, int low,
                 int high, bool opt) {
    while (i != j) {
      int k = low;
      int mid = (i + j) / 2;
      while (k < high && image[k][mid] == '0') {
        k += 1;
      }

      if (k < high == opt) {
        j = mid;
      } else {
        i = mid + 1;
      }
    }
    return i;
  }

public:
  int minArea(vector<vector<char>> &image, int x, int y) {
    int numRows = image.size();
    int numCols = image[0].size();
    int top = searchRows(image, 0, x, 0, numCols, true);
    int bottom = searchRows(image, x + 1, numRows, 0, numCols, false);
    int left = searchCols(image, 0, y, top, bottom, true);
    int right = searchCols(image, y + 1, numCols, top, bottom, false);

    return (right - left) * (bottom - top);
  }
};
