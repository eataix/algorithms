#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [734] Sentence Similarity
 *
 * https://leetcode.com/problems/sentence-similarity/description/
 *
 * algorithms
 * Easy (38.75%)
 * Total Accepted:    10.4K
 * Total Submissions: 26.7K
 * Testcase Example:
 * '["great","acting","skills"]\n["fine","drama","talent"]\n[["great","fine"],["drama","acting"],["skills","talent"]]'
 *
 * Given two sentences words1, words2 (each represented as an array of
 * strings), and a list of similar word pairs pairs, determine if two sentences
 * are similar.
 *
 * For example, "great acting skills" and "fine drama talent" are similar, if
 * the similar word pairs are pairs = [["great", "fine"],
 * ⁠["acting","drama"], ["skills","talent"]].
 *
 * Note that the similarity relation is not transitive. For example, if "great"
 * and "fine" are similar, and "fine" and "good" are similar, "great" and
 * "good" are not necessarily similar.
 *
 * However, similarity is symmetric.  For example, "great" and "fine" being
 * similar is the same as "fine" and "great" being similar.
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
class Solution {
public:
  bool areSentencesSimilar(const vector<string> &words1,
                           const vector<string> &words2,
                           const vector<pair<string, string>> &pairs) {
    if (words1.size() != words2.size()) {
      return false;
    }

    unordered_map<string, unordered_set<string>> m;
    for (const auto &p : pairs) {
      string s1 = p.first;
      string s2 = p.second;

      m[s1].insert(s2);
      m[s2].insert(s1);
    }

    int n = words1.size();

    for (int i = 0; i < n; ++i) {
      string s1 = words1[i];
      string s2 = words2[i];

      if (!m[s1].count(s2) && s1 != s2) {
        return false;
      }
    }

    return true;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;

  cout << sol.areSentencesSimilar(
              vector<string>{"great", "acting", "skills"},
              vector<string>{"fine", "drama", "talent"},
              vector<pair<string, string>>{
                  {"great", "fine"}, {"acting", "drama"}, {"skills", "talent"}})
       << endl;
}
#endif
