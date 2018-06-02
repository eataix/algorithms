class Solution:
    """
    @param arr: The K spaced array
    @param k: The param k
    @return: Return the sorted array
    """

    def getSortedArray(self, arr, k):
        res = []
        pq = []

        import heapq

        upper = min(len(arr), k)
        for i in range(0, upper):
            heapq.heappush(pq, (arr[i], i))

        while len(pq) > 0:
            v, idx = heapq.heappop(pq)

            res.append(v)
            new_idx = idx + k
            if new_idx < len(arr):
                heapq.heappush(pq, (arr[new_idx], new_idx))

        return res


if __name__ == '__main__':
    Solution().getSortedArray([4, 0, 5, 3, 10], 2)
