class Solution {
public:
  char firstUniqChar(string s) {
    vector<int> dict(26, 0);
    for (char ch : s) {
      dict[ch] += 1;
    }

    for (char ch : s) {
      if (dict[ch] == 1) {
        return ch;
      }
    }
    return ' ';
  }
};
