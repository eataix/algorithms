#include <deque>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (33.81%)
 * Total Accepted:    122.5K
 * Total Submissions: 362.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 *
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 *
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So it is possible.
 *
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0, and to take course 0 you should also have finished course
 * 1. So it is impossible.
 *
 * Note:
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 *
 * click to show more hints.
 *
 * Hints:
 *
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 *
 *
 */
class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<unordered_set<int> *> courses(numCourses, nullptr);
    for (int i = 0; i < numCourses; ++i) {
      courses[i] = new unordered_set<int>();
    }

    vector<int> numPrerequisites(numCourses, 0);
    vector<bool> done(numCourses, false);
    deque<int> zeroPrerequisiteCourse;

    for (const auto &kv : prerequisites) {
      int a = kv.first;
      int b = kv.second;
      courses[b]->insert(a);
      numPrerequisites[a] += 1;
    }

    for (int c = 0; c < numCourses; ++c) {
      if (numPrerequisites[c] == 0) {
        zeroPrerequisiteCourse.push_back(c);
      }
    }

    while (!zeroPrerequisiteCourse.empty()) {
      int c = zeroPrerequisiteCourse.front();
      cout << "Can start  " << c << endl;
      zeroPrerequisiteCourse.pop_front();
      done[c] = true;
      for (const auto &i : *courses[c]) {
        numPrerequisites[i] -= 1;
        if (numPrerequisites[i] == 0) {
          zeroPrerequisiteCourse.push_back(i);
        }
      }
    }

    for (int c = 0; c < numCourses; ++c) {
      if (!done[c]) {
        return false;
      }
    }
    return true;
  }
};

#ifdef DEBUG
int main() {
  int n = 3;
  vector<pair<int, int>> v{make_pair(1, 0), make_pair(1, 2), make_pair(0, 1)};
  Solution sol;
  cout << sol.canFinish(n, v) << endl;
}
#endif
