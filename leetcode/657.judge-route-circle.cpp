#include <string>
using namespace std;
/*
 * [657] Judge Route Circle
 *
 * https://leetcode.com/problems/judge-route-circle/description/
 *
 * algorithms
 * Easy (68.48%)
 * Total Accepted:    72.2K
 * Total Submissions: 105.5K
 * Testcase Example:  '"UD"'
 *
 *
 * Initially, there is a Robot at position (0, 0). Given a sequence of its
 * moves, judge if this robot makes a circle, which means it moves back to the
 * original place.
 *
 *
 *
 * The move sequence is represented by a string. And each move is represent by
 * a character. The valid robot moves are R (Right), L (Left), U (Up) and D
 * (down). The output should be true or false representing whether the robot
 * makes a circle.
 *
 *
 * Example 1:
 *
 * Input: "UD"
 * Output: true
 *
 *
 *
 * Example 2:
 *
 * Input: "LL"
 * Output: false
 *
 *
 */
class Solution
{
  public:
    bool judgeCircle(string moves)
    {
        int x = 0;
        int y = 0;
        for (char ch : moves)
        {
            switch (ch)
            {
            case 'U':
                x += 1;
                break;
            case 'D':
                x -= 1;
                break;
            case 'L':
                y -= 1;
                break;
            case 'R':
                y += 1;
                break;
            }
        }
        return x == 0 && y == 0;
    }
};
