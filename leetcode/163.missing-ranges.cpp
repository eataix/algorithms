#include <string>
#include <vector>
using namespace std;
/*
 * [163] Missing Ranges
 *
 * https://leetcode.com/problems/missing-ranges/description/
 *
 * algorithms
 * Medium (23.00%)
 * Total Accepted:    41.1K
 * Total Submissions: 178.9K
 * Testcase Example:  '[0,1,3,50,75]\n0\n99'
 *
 * Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges.
 *
 * Example:
 *
 *
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 *
 *
 */
class Solution {
  string getRange(long long start, long long end) {
    if (start == end) {
      return to_string(start);
    } else {
      return to_string(start) + "->" + to_string(end);
    }
  }

public:
  vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    vector<string> res;
    if (nums.empty()) {
      return {getRange(lower, upper)};
    }

    for (int i = 0; i <= nums.size(); ++i) {
      auto left = (i == 0) ? static_cast<long long>(lower)
                           : static_cast<long long>(nums[i - 1]) + 1LL;
      auto right = (i == nums.size()) ? static_cast<long long>(upper)
                                      : static_cast<long long>(nums[i]) - 1LL;
      if (right >= left) {
        res.push_back(getRange(left, right));
      }
    }
    return res;
  }

  vector<string> findMissingRanges3(vector<int> &nums, int lower, int upper) {
    vector<long long> newNums{nums.begin(), nums.end()};
    newNums.insert(newNums.begin(), static_cast<long long>(lower) - 1LL);
    newNums.push_back(static_cast<long long>(upper) + 1LL);

    vector<string> res;

    for (int i = 1; i < newNums.size(); ++i) {
      if (newNums[i] - newNums[i - 1] > 1) {
        res.push_back(getRange(newNums[i - 1] + 1, newNums[i] - 1));
      }
    }
    return res;
  }

  vector<string> findMissingRanges1(vector<int> &nums, int lower, int upper) {
    if (nums.empty()) {
      return {getRange(lower, upper)};
    }
    vector<string> res;
    auto lastSeen = static_cast<long long>(lower) - 1LL;
    for (int i = 0; i <= nums.size(); ++i) {
      auto currSeen = i == nums.size() ? static_cast<long long>(upper) + 1LL
                                       : static_cast<long long>(nums[i]);

      // (lastSeen, currSee) is the interval
      if (currSeen - lastSeen >= 2) {
        res.push_back(getRange(lastSeen + 1LL, currSeen - 1LL));
      }
      lastSeen = currSeen;
    }
    return res;
  }
};
