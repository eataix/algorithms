#include <string>
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
    unordered_set<string> r;
    unordered_set<int> st;

    int curr = 0;
    int idx = 0;

    while (idx < 9) {
      curr <<= 3;
      curr |= s[idx] & 7;
      idx += 1;
    }

    while (idx < s.size()) {
      curr = (curr & mask) << 3;
      curr |= s[idx] & 7;
      idx += 1;
      if (st.find(curr) != cend(st)) {
        r.insert(s.substr(idx - 10, 10));
      } else {
        st.insert(curr);
      }
    }

    return vector<string>{cbegin(r), cend(r)};
  }
};
