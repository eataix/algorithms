class Solution {
  bool isSubsequence(const string &longer, const string &shorter) {
    int i = 0;
    int j = 0;

    while (i < longer.size() && j < shorter.size()) {
      if (longer[i] == shorter[j]) {
        j += 1;
      }
      i += 1;
    }
    return j == shorter.size();
  }

public:
  /**
   * @param s: a string
   * @param d: List[str]
   * @return: return a string
   */
  string findLongestWord(string &s, vector<string> &d) {
    sort(d.begin(), d.end(), [](auto const &s1, auto const &s2) {
      return s1.size() > s2.size() ||
             (s1.size() == s2.size() && s1.compare(s2) < 0);
    });

    for (auto const &word : d) {
      if (isSubsequence(s, word)) {
        return word;
      }
    }
    return "";
  }
};
