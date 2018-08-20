#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (33.25%)
 * Total Accepted:    96.2K
 * Total Submissions: 289.2K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 *
 * Example:
 *
 *
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 *
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 *
 *
 */
const int mask = 0x7ffffff;
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> res;
    unordered_set<int> st;

    int curr = 0;
    for (int i = 0; i < s.size(); ++i) {
      curr = (curr & mask) << 3;
      curr |= s[i] & 0b111;

      if (i >= 9) {
        if (st.count(curr)) {
          res.insert(s.substr(i - 9, 10));
        } else {
          st.insert(curr);
        }
      }
    }
    return vector<string>(res.begin(), res.end());
  }
};
