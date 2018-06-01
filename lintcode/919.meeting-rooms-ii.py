"""
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """

    def minMeetingRooms(self, intervals):
        intervals.sort(key=lambda i: i.start)

        import heapq
        heap = []

        for interval in intervals:
            if len(heap) > 0 and heap[0] <= interval.start:
                heapq.heappop(heap)
            heapq.heappush(heap, interval.end)
        return len(heap)


if __name__ == '__main__':
    i1 = Interval(0, 30)
    i2 = Interval(5, 10)
    i3 = Interval(15, 20)

    s = Solution()

    print(s.minMeetingRooms([i1, i2, i3]))
