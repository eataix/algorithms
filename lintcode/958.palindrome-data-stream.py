class Solution:
    """
    @param s: The data stream
    @return: Return the judgement stream
    """

    def getStream(self, s):
        oldChars = set()
        result = [0] * len(s)

        for i in range(len(s)):
            ch = s[i]

            if ch not in oldChars:
                oldChars.add(ch)
            else:
                oldChars.remove(ch)

            if len(oldChars) > 1:
                result[i] = 0
            else:
                result[i] = 1
        return result
