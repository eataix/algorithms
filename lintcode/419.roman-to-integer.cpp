class Solution {
private:
    unordered_map<char, int> values {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    /**
     * @param s: Roman representation
     * @return: an integer
     */
    int romanToInt(string &s) {
      int res = 0;
      
      for (int i = 0; i < s.size(); ++i) {
          int v1 = values[s[i]];
          
          if (i < s.size() - 1) {
              int v2 = values[s[i+ 1]];
              if (v1 >= v2) {
                  res += v1;
              } else {
                  res += v2 - v1;
                  i += 1;
              }
          } else {
              res += v1;
          }
      }
      return res;
    }
};
