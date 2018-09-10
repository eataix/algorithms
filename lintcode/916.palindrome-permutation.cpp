class Solution {
public:
  /**
   * @param s: the given string
   * @return: if a permutation of the string could form a palindrome
   */
  bool canPermutePalindrome(string &s) {
    unordered_set<char> seen;
    for (char ch : s) {
      if (seen.count(ch)) {
        seen.erase(ch);
      } else {
        seen.insert(ch);
      }
    }
    return seen.size() <= 1;
  }
};
