class Solution {
public:
  /**
   * @param A: An array of non-negative integers
   * @return: The maximum amount of money you can rob tonight
   */
  long long houseRobber(vector<int> &A) {
    if (A.empty()) {
      return 0;
    }

    if (A.size() == 1) {
      return A[0];
    }

    long long minusTwo = 0;
    long long minusOne = A[0];

    for (int i = 1; i < A.size(); ++i) {
      long long currV = max(minusTwo + A[i], minusOne);

      minusTwo = minusOne;
      minusOne = currV;
    }

    return minusOne;
  }
};
