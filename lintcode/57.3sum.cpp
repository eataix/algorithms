class Solution {
public:
  /**
   * @param numbers: Give an array numbers of n integer
   * @return: Find all unique triplets in the array which gives the sum of zero.
   */
  vector<vector<int>> threeSum(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());

    vector<vector<int>> res;
    for (int i = 0; i < numbers.size(); ++i) {
      if (i > 0 && numbers[i] == numbers[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = numbers.size() - 1;
      int currVal = numbers[i];

      while (left < right) {
        int numLeft = numbers[left];
        int numRight = numbers[right];
        int sum = currVal + numLeft + numRight;
        if (sum == 0) {
          res.push_back({currVal, numLeft, numRight});

          while (left < right && numbers[left] == numLeft) {
            left += 1;
          }

          while (left < right && numbers[right] == numRight) {
            right -= 1;
          }
        }

        if (sum < 0) {
          left += 1;
        }

        if (sum > 0) {
          right -= 1;
        }
      }
    }

    return res;
  }
};
