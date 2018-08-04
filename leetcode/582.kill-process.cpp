#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [582] Kill Process
 *
 * https://leetcode.com/problems/kill-process/description/
 *
 * algorithms
 * Medium (51.97%)
 * Total Accepted:    14.2K
 * Total Submissions: 27.4K
 * Testcase Example:  '[1,3,10,5]\n[3,0,5,3]\n5'
 *
 * Given n processes, each process has a unique PID (process id) and its PPID
 * (parent process id).
 *
 * Each process only has one parent process, but may have one or more children
 * processes. This is just like a tree structure.  Only one process has PPID
 * that is 0, which means this process has no parent process. All the PIDs will
 * be distinct positive integers.
 *
 * We use two list of integers to represent a list of processes, where the
 * first list contains PID for each process and the second list contains the
 * corresponding PPID.
 * ⁠
 * Now given the two lists, and a PID representing a process you want to kill,
 * return a list of PIDs of processes that will be killed in the end. You
 * should assume that when a process is killed, all its children processes will
 * be killed. No order is required for the final answer.
 *
 * Example 1:
 *
 * Input:
 * pid =  [1, 3, 10, 5]
 * ppid = [3, 0, 5, 3]
 * kill = 5
 * Output: [5,10]
 * Explanation:
 * ⁠          3
 * ⁠        /   \
 * ⁠       1     5
 * ⁠            /
 * ⁠           10
 * Kill 5 will also kill 10.
 *
 *
 *
 * Note:
 *
 * The given kill id is guaranteed to be one of the given PIDs.
 * n >= 1.
 *
 *
 */
class Solution {
public:
  vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
    vector<int> killed;

    unordered_map<int, unordered_set<int>> children;

    for (int i = 0; i < pid.size(); ++i) {
      int child = pid[i];
      int parent = ppid[i];
      children[parent].insert(child);
    }

    queue<int> q;

    q.push(kill);

    while (!q.empty()) {
      auto id = q.front();
      q.pop();

      killed.push_back(id);

      for (int ch : children[id]) {
        q.push(ch);
      }
    }
    return killed;
  }
};
