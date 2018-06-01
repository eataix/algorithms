class Solution:
    """
    @param: start: a string
    @param: end: a string
    @param: dict: a set of string
    @return: An integer
    """

    def ladderLength(self, start, end, dict):
        dict.add(end)
        import queue
        q = queue.Queue()

        q.put((start, 1))
        explored = set()

        while not q.empty():
            curr_str, level = q.get()
            if curr_str == end:
                return level

            import string
            for i in range(len(curr_str)):
                for c in list(string.ascii_lowercase):
                    new_str = curr_str[0:i] + c + curr_str[i + 1:]
                    if new_str in dict and new_str not in explored:
                        q.put((new_str, level + 1))
                        explored.add(new_str)


if __name__ == '__main__':
    res = Solution().ladderLength('hit', 'cog',
                                  set(["hot", "dot", "dog", "lot", "log"]))
    print(res)
