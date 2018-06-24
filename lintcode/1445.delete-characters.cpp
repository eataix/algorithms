class Solution {
public:
    /**
     * @param s: The string s
     * @param t: The string t
     * @return: Return if can get the string t
     */
    bool canGetString(string &s, string &t) {
        int i = 0;
        int j = 0;
        
        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                i += 1;
                if (i == s.size()) {
                    break;
                }
            }
            i += 1;
            j += 1;
        }
        
        return j == t.size();
    }
};
