class Solution {
public:
    /**
     * @param str: s string
     * @return: return an integer, denote the number of the palindromic substrings
     */
    int countPalindromicSubstrings(string &str) {
        int res = 0;
        
        for (int i = 0; i < str.size(); ++i) {
            res += expandAroundCenter(str, i, i);
            res += expandAroundCenter(str, i, i + 1);
        }
        
        return res;
    }
    
    int expandAroundCenter(const string &str, int left, int right) {
        int res = 0;
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            res += 1;
            left -= 1;
            right += 1;
        }
        
        return res;
    }
};
