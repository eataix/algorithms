"""
Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
"""


class Solution:
    """
    @param coordinates: The radars' coordinate
    @param radius: Detection radius of radars
    @return: The car was detected or not
    """

    def radarDetection(self, coordinates, radius):
        for i in range(len(coordinates)):
            upper = coordinates[i].y + radius[i]
            lower = coordinates[i].y - radius[i]
            if (upper > 0 and lower < 0) or (upper > 1 and lower < 1):
                return "YES"
        return "NO"
