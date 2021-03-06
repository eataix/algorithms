#include <string>
#include <unordered_set>
using namespace std;
/*
 * [782] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (82.08%)
 * Total Accepted:    37.7K
 * Total Submissions: 45.9K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.  Each character in S is a type of stone
 * you have.  You want to know how many of the stones you have are also
 * jewels.
 *
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type
 * of stone from "A".
 *
 * Example 1:
 *
 *
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: J = "z", S = "ZZ"
 * Output: 0
 *
 *
 * Note:
 *
 *
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 *
 */
class Solution {
public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> jewels;
    for (char ch : J) {
      jewels.insert(ch);
    }
    int count = 0;
    for (char ch : S) {
      if (jewels.find(ch) != jewels.cend()) {
        count += 1;
      }
    }
    return count;
  }
};
