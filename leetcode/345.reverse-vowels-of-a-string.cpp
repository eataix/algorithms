#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
using namespace std;
/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (39.26%)
 * Total Accepted:    106.6K
 * Total Submissions: 271.5K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 *
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 *
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 *
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 */

const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                 'A', 'E', 'I', 'O', 'U'};

class Solution {
public:
  string reverseVowels(string s) {
    string res{s};
    stack<char> seenVowels;
    deque<int> positions;
    for (int i = 0; i < res.size(); ++i) {
      char ch = res[i];
      if (vowels.find(ch) != vowels.cend()) {
        seenVowels.push(ch);
        positions.push_back(i);
      }
    }

    while (!positions.empty()) {
      int p = positions.front();
      positions.pop_front();
      char ch = seenVowels.top();
      seenVowels.pop();
      res[p] = ch;
    }

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.reverseVowels(string{"hello"}) << endl;
  cout << sol.reverseVowels(string{"leetcode"}) << endl;
}
#endif
