#
# [676] Implement Magic Dictionary
#
# https://leetcode.com/problems/implement-magic-dictionary/description/
#
# algorithms
# Medium (49.08%)
# Total Accepted:    14.2K
# Total Submissions: 29K
# Testcase Example:  '["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]'
#
#
# Implement a magic directory with buildDict, and search methods.
#
#
#
# For the method buildDict, you'll be given a list of non-repetitive words to
# build a dictionary.
#
#
#
# For the method search, you'll be given a word, and judge whether if you
# modify exactly one character into another character in this word, the
# modified word is in the dictionary you just built.
#
#
# Example 1:
#
# Input: buildDict(["hello", "leetcode"]), Output: Null
# Input: search("hello"), Output: False
# Input: search("hhllo"), Output: True
# Input: search("hell"), Output: False
# Input: search("leetcoded"), Output: False
#
#
#
# Note:
#
# You may assume that all the inputs are consist of lowercase letters a-z.
# For contest purpose, the test data is rather small by now. You could think
# about highly efficient algorithm after the contest.
# Please remember to RESET your class variables declared in class
# MagicDictionary, as static/class variables are persisted across multiple test
# cases. Please see here for more details.
#
#
#
class MagicDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """

    def buildDict(self, words):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: void
        """
        self.dictionary = {}
        for word in words:
            n = len(word)
            if n not in self.dictionary:
                self.dictionary[n] = []
            self.dictionary[n].append(word)

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        n = len(word)
        if n not in self.dictionary:
            return False

        def countDifference(s1, s2):
            cnt = 0
            for c1, c2 in zip(s1, s2):
                if c1 != c2:
                    cnt += 1
                    if cnt > 1:
                        break

            return cnt

        for w in self.dictionary[n]:
            if countDifference(w, word) == 1:
                return True
        return False


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
