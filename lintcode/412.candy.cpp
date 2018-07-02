class Solution {
public:
  /**
   * @param ratings: Children's ratings
   * @return: the minimum candies you must give
   */
  int candy(vector<int> &ratings) {
    if (ratings.size() <= 1) {
      return ratings.size();
    }

    int total = 1;
    int prev = 1;
    int numDecreasing = 0;

    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] >= ratings[i - 1]) {
        if (numDecreasing > 0) {
          total += numDecreasing * (numDecreasing + 1) / 2;
          total += max(0, numDecreasing + 1 - prev);
          prev = 1;
          numDecreasing = 0;
        }

        prev = ratings[i] == ratings[i - 1] ? 1 : prev + 1;
        total += prev;
      } else {
        numDecreasing += 1;
      }
    }

    if (numDecreasing > 0) {
      total += numDecreasing * (numDecreasing + 1) / 2;
      total += max(0, numDecreasing + 1 - prev);
    }
    return total;
  }
};
