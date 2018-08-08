#include <map>
#include <vector>
using namespace std;
/*
 * [876] Hand of Straights
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (42.84%)
 * Total Accepted:    5K
 * Total Submissions: 11.7K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice has a hand of cards, given as an array of integers.
 *
 * Now she wants to rearrange the cards into groups so that each group is size
 * W, and consists of W consecutive cards.
 *
 * Return true if and only if she can.
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
 *
 * Example 2:
 *
 *
 * Input: hand = [1,2,3,4,5], W = 4
 * Output: false
 * Explanation: Alice's hand can't be rearranged into groups of 4.
 *
 *
 *
 * Note:
 *
 *
 * 1 <= hand.length <= 10000
 * 0 <= hand[i] <= 10^9
 * 1 <= W <= hand.length
 *
 */
class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int W) {
    map<int, int> s;
    for (int h : hand) {
      s[h] += 1;
    }

    for (auto kv : s) {
      if (kv.second > 0) {
        for (int i = 1; i <= W - 1; ++i) {
          if (s[kv.first + i] < kv.second) {
            return false;
          }
          s[kv.first + i] -= kv.second;
        }
        kv.second = 0;
      }
    }
    return true;
  }
};
