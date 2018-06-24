class Solution {
public:
  /**
   * @param num: a string
   * @param k: an integer
   * @return: return a string
   */
  string removeKdigits(string &num, int k) {
    string res;
    int keep = num.size() - k;

    for (int i = 0; i < num.size(); ++i) {
      while (!res.empty() && num[i] < res.back() && k > 0) {
        res.pop_back();
        k -= 1;
      }
      res += num[i];
    }
    res.resize(keep);

    while (!res.empty() && res[0] == '0') {
      res.erase(res.begin());
    }

    return res == "" ? "0" : res;
  }
};
