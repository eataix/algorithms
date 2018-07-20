#include <vector>
using namespace std;
/*
 * [274] H-Index
 *
 * https://leetcode.com/problems/h-index/description/
 *
 * algorithms
 * Medium (34.00%)
 * Total Accepted:    102.8K
 * Total Submissions: 302.2K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * Given an array of citations (each citation is a non-negative integer) of a
 * researcher, write a function to compute the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index
 * h if h of his/her N papers have at least h citations each, and the other N −
 * h papers have no more than h citations each."
 *
 * Example:
 *
 *
 * Input: citations = [3,0,6,1,5]
 * Output: 3
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
 * of them had
 * ⁠            received 3, 0, 6, 1, 5 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining
 * two with no more than 3 citations each, her h-index is 3.
 *
 * Note: If there are several possible values for h, the maximum one is taken
 * as the h-index.
 *
 */
class Solution {
public:
  int hIndex(vector<int> &citations) {
    int len = citations.size();
    vector<int> count(len + 1, 0);

    for (auto const &citation : citations) {
      count[min(citation, len)] += 1;
    }

    int total = 0;
    for (int i = len; i >= 0; --i) {
      total += count[i];
      if (total >= i) {
        return i;
      }
    }
    return 0;
  }
};
