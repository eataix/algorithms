class Solution:
    """
    @param words: a list of words
    @return: a string which is correct order
    """

    def alienOrder(self, words):
        nodes = set()
        edges = {}
        indegrees = {}
        for word in words:
            for ch in word:
                nodes.add(ch)

        for node in nodes:
            edges[node] = set()
            indegrees[node] = 0

        for i in range(len(words) - 1):
            m = len(words[i])
            n = len(words[i + 1])

            mn = min(m, n)

            idx = 0

            while idx < mn:
                ch1 = words[i][idx]
                ch2 = words[i + 1][idx]
                if ch1 != ch2:
                    edges[ch1].add(ch2)
                    break
                idx += 1

            if idx == mn and m > n:
                return ""

        for node in nodes:
            for nei in edges[node]:
                indegrees[nei] += 1

        import heapq
        q = []

        for node in nodes:
            print(f'node: {node}, degrees: {indegrees[node]}')
            if indegrees[node] == 0:
                heapq.heappush(q, node)

        res = ""
        while len(q) > 0:
            node = heapq.heappop(q)
            res += node
            for nei in edges[node]:
                indegrees[nei] -= 1
                if indegrees[nei] == 0:
                    heapq.heappush(q, nei)
        if len(res) == len(nodes):
            return res
        else:
            return ""


if __name__ == '__main__':
    #print(Solution().alienOrder(["wrt","wrf","er","ett","rftt"]))
    #print(Solution().alienOrder([  "z", "x" ]))
    print(Solution().alienOrder(["abc", "bcd", "qwert", "ab"]))
