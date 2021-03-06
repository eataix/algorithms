#
# [734] Sentence Similarity
#
# https://leetcode.com/problems/sentence-similarity/description/
#
# algorithms
# Easy (38.75%)
# Total Accepted:    10.4K
# Total Submissions: 26.7K
# Testcase Example:  '["great","acting","skills"]\n["fine","drama","talent"]\n[["great","fine"],["drama","acting"],["skills","talent"]]'
#
# Given two sentences words1, words2 (each represented as an array of strings),
# and a list of similar word pairs pairs, determine if two sentences are
# similar.
#
# For example, "great acting skills" and "fine drama talent" are similar, if
# the similar word pairs are pairs = [["great", "fine"],
# ⁠["acting","drama"], ["skills","talent"]].
#
# Note that the similarity relation is not transitive. For example, if "great"
# and "fine" are similar, and "fine" and "good" are similar, "great" and "good"
# are not necessarily similar.
#
# However, similarity is symmetric.  For example, "great" and "fine" being
# similar is the same as "fine" and "great" being similar.
#
# Also, a word is always similar with itself.  For example, the sentences
# words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though
# there are no specified similar word pairs.
#
# Finally, sentences can only be similar if they have the same number of
# words.  So a sentence like words1 = ["great"] can never be similar to words2
# = ["doubleplus","good"].
#
#
# Note:
# The length of words1 and words2 will not exceed 1000.
# The length of pairs will not exceed 2000.
# The length of each pairs[i] will be 2.
# The length of each words[i] and pairs[i][j] will be in the range [1, 20].
#
#
from collections import defaultdict


class Solution:
    def areSentencesSimilar(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        m = len(words1)
        n = len(words2)
        if m != n:
            return False
        mapping = defaultdict(set)
        for w1, w2 in pairs:
            mapping[w1].add(w2)
            mapping[w2].add(w1)

        for w1, w2 in zip(words1, words2):
            if w1 == w2:
                continue
            if w1 not in mapping[w2]:
                return False

        return True
