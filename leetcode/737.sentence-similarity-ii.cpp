#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [737] Sentence Similarity II
 *
 * https://leetcode.com/problems/sentence-similarity-ii/description/
 *
 * algorithms
 * Medium (40.22%)
 * Total Accepted:    10.8K
 * Total Submissions: 26.9K
 * Testcase Example:
 * '["great","acting","skills"]\n["fine","drama","talent"]\n[["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]'
 *
 * Given two sentences words1, words2 (each represented as an array of
 * strings), and a list of similar word pairs pairs, determine if two sentences
 * are similar.
 *
 * For example, words1 = ["great", "acting", "skills"] and words2 = ["fine",
 * "drama", "talent"] are similar, if the similar word pairs are pairs =
 * [["great", "good"], ["fine", "good"],
 * ⁠["acting","drama"], ["skills","talent"]].
 *
 * Note that the similarity relation is transitive. For example, if "great" and
 * "good" are similar, and "fine" and "good" are similar, then "great" and
 * "fine" are similar.
 *
 * Similarity is also symmetric.  For example, "great" and "fine" being similar
 * is the same as "fine" and "great" being similar.
 *
 * Also, a word is always similar with itself.  For example, the sentences
 * words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though
 * there are no specified similar word pairs.
 *
 * Finally, sentences can only be similar if they have the same number of
 * words.  So a sentence like words1 = ["great"] can never be similar to words2
 * = ["doubleplus","good"].
 *
 *
 * Note:
 * The length of words1 and words2 will not exceed 1000.
 * The length of pairs will not exceed 2000.
 * The length of each pairs[i] will be 2.
 * The length of each words[i] and pairs[i][j] will be in the range [1, 20].
 *
 */
static inline string find_id(unordered_map<string, string> &m,
                             const string &s) {
  if (!m.count(s)) {
    return m[s] = s;
  }
  if (m[s] == s) {
    return s;
  } else {
    return m[s] = find_id(m, m[s]);
  }
}

class Solution {
public:
  bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2,
                              vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) {
      return false;
    }
    unordered_map<string, string> m;
    for (auto const &p : pairs) {
      auto s1 = p.first;
      auto s2 = p.second;

      auto g1 = find_id(m, s1);
      auto g2 = find_id(m, s2);
      if (g1 != g2) {
        m[g1] = g2;
      }
    }

    for (int i = 0; i < words1.size(); ++i) {
      auto s1 = words1[i];
      auto s2 = words2[i];

      if (s1 != s2 && find_id(m, s1) != find_id(m, s2)) {
        return false;
      }
    }
    return true;
  }
};
