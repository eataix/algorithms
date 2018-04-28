#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [822] Unique Morse Code Words
 *
 * https://leetcode.com/problems/unique-morse-code-words/description/
 *
 * algorithms
 * Easy (75.54%)
 * Total Accepted:    11.1K
 * Total Submissions: 14.7K
 * Testcase Example:  '["gin", "zen", "gig", "msg"]'
 *
 * International Morse Code defines a standard encoding where each letter is
 * mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b"
 * maps to "-...", "c" maps to "-.-.", and so on.
 *
 * For convenience, the full table for the 26 letters of the English alphabet
 * is given below:
 *
 *
 *
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 *
 * Now, given a list of words, each word can be written as a concatenation of
 * the Morse code of each letter. For example, "cab" can be written as
 * "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll
 * call such a concatenation, the transformation of a word.
 *
 * Return the number of different transformations among all words we have.
 *
 *
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation:
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 *
 * There are 2 different transformations, "--...-." and "--...--.".
 *
 *
 *
 *
 * Note:
 *
 *
 * The length of words will be at most 100.
 * Each words[i] will have length in range [1, 12].
 * ⁠   words[i] will only consist of lowercase letters.
 *
 *
 */
const vector<string> dict{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                          "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                          "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                          "...-", ".--",  "-..-", "-.--", "--.."};

class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    unordered_set<string> res;
    for (const auto &word : words) {
      string str;
      for (const auto &ch : word) {
        str += dict[ch - 'a'];
      }
      res.insert(str);
    }
    return res.size();
  }
};

#ifdef DEBUG
int main() {
  vector<string> v{"gin", "zen", "gig", "msg"};
  Solution sol;
  cout << sol.uniqueMorseRepresentations(v) << endl;
}
#endif
