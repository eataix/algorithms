class Solution:
    """
    @param source : A string
    @param target: A string
    @return: A string denote the minimum window, return "" if there is no such a string
    """

    def minWindow(self, source, target):
        target_map = {}
        source_map = {}

        for c in target:
            if c not in target_map:
                target_map[c] = 0
            source_map[c] = 0
            target_map[c] += 1

        left = 0
        count = 0
        minD = len(source) + 1
        minLeft = -1
        for right in range(len(source)):
            ch = source[right]
            if ch not in target_map:
                continue

            source_map[ch] += 1

            if source_map[ch] <= target_map[ch]:
                count += 1

            while count == len(target):
                if right - left + 1 < minD:
                    minD = right - left + 1
                    minLeft = left

                removed_ch = source[left]
                left += 1
                if removed_ch not in target_map:
                    continue
                source_map[removed_ch] -= 1
                if source_map[removed_ch] < target_map[removed_ch]:
                    count -= 1

        if minLeft == -1:
            return ""
        else:
            return source[minLeft:minLeft + minD]


if __name__ == '__main__':
    s = Solution()

    print(s.minWindow('ADOBECODEBANC', 'ABC'))
