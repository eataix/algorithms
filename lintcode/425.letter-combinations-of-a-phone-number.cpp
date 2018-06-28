class Solution {
  vector<string> m{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
  /**
   * @param digits: A digital string
   * @return: all posible letter combinations
   */
  vector<string> letterCombinations(string &digits) {

    if (digits.empty()) {
      return {};
    }
    vector<string> res;
    string out;

    dfs(digits, 0, out, res);
    return res;
  }

  void dfs(const string &digits, int numIncluded, string &out,
           vector<string> &res) {
    if (numIncluded == digits.size()) {
      res.push_back(out);
      return;
    }

    char ch = digits[numIncluded];
    int v = ch - '2';
    for (char ch : m[v]) {
      out.push_back(ch);
      dfs(digits, numIncluded + 1, out, res);
      out.pop_back();
    }
  }
};
