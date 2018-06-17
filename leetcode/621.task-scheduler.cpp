#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (42.45%)
 * Total Accepted:    32.5K
 * Total Submissions: 76.6K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval. For
 * each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 *
 * Example 1:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 *
 *
 * Note:
 *
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 *
 */
class Solution {
public:
  int leastInterval(const vector<char> &tasks, int n) {
    vector<int> m(26, 0);
    for (char task : tasks) {
      m[task - 'A'] += 1;
    }

    sort(m.begin(), m.end());

    int maxVal = m[25] - 1;
    int slots = maxVal * n;

    for (int i = 24; i >= 0 && m[i] > 0; --i) {
      slots -= min(m[i], maxVal);
    }

    return tasks.size() + max(slots, 0);
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.leastInterval(vector<char>{'A', 'A', 'A', 'B', 'B', 'B'}, 3)
       << endl;
}
#endif
