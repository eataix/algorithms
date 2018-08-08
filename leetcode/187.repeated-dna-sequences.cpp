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
class Solution {
  int mask = 0x7ffffff;

public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> res;
    unordered_set<int> st;
    unordered_map<int, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    int cur = 0, i = 0;
    while (i < 9)
      cur = cur << 2 | m[s[i++]];
    while (i < s.size()) {
      cur = ((cur & 0x3ffff) << 2) | (m[s[i++]]);
      if (st.count(cur)) {
        res.insert(s.substr(i - 10, 10));
      } else {
        st.insert(cur);
      }
    }
    return vector<string>(res.begin(), res.end());
  }
};
