class Solution:
    """
    @param dict: an array of n distinct non-empty strings
    @return: an array of minimal possible abbreviations for every word
    """

    def wordsAbbreviation(self, words):
        def abbrev(word, end=0):
            return word[0:end + 1] + str(len(word) - 2 - end) + word[-1]

        duplicates = {}
        for word in words:
            aword = abbrev(word)
            print(f'{word} -> {aword}')

            if aword not in duplicates:
                duplicates[aword] = []

            duplicates[aword].append(word)
        import pprint
        pprint.pprint(duplicates)

        final_map = {}

        class Trie:
            def __init__(self, val):
                self.children = {}
                self.count = 0

        for (k, v) in duplicates.items():
            if len(v) == 1:
                final_map[v[0]] = k
                continue

            dummy = Trie('')
            for aw in v:
                prev = dummy

                for (_, ch) in enumerate(aw):
                    if ch not in prev.children:
                        prev.children[ch] = Trie(ch)
                    prev.children[ch].count += 1
                    prev = prev.children[ch]

            for aw in v:
                prev = dummy

                for (idx, ch) in enumerate(aw):
                    curr = prev.children[ch]
                    if curr.count == 1:
                        final_map[aw] = abbrev(aw, idx)
                        break
                    prev = curr

        assert len(final_map) == len(words)

        res = []
        for word in words:
            new_word = final_map[word]
            if len(new_word) >= len(word):
                res.append(word)
            else:
                res.append(new_word)
        print(res)
        return res


if __name__ == '__main__':
    Solution().wordsAbbreviation([
        "like", "god", "internal", "me", "internet", "interval", "intension",
        "face", "intrusion"
    ])
