#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (49.41%)
 * Total Accepted:    40.9K
 * Total Submissions: 82.8K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 *
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 *
 *
 *
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 *
 *
 * Example 1:
 *
 * Input:
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 *
 *
 *
 *
 * Note:
 *
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 *
 *
 */

class Solution {
  int find_set(vector<int> &parent, int i) {
    if (parent[i] == -1) {
      return i;
    }

    return find_set(parent, parent[i]);
  }
  void union_set(vector<int> &parent, int x, int y) {
    int xset = find_set(parent, x);
    int yset = find_set(parent, y);

    if (xset != yset) {
      parent[xset] = yset;
    }
  }

public:
  int findCircleNum1(vector<vector<int>> &M) {
    vector<int> parent(M.size(), -1);

    for (int i = 0; i < M.size(); ++i) {
      for (int j = 0; j < M.size(); ++j) {
        if (M[i][j] == 1 && i != j) {
          union_set(parent, i, j);
        }
      }
    }

    int count = 0;
    for (int i = 0; i < parent.size(); ++i) {
      if (parent[i] == -1) {
        count += 1;
      }
    }
    return count;
  }

  int findCircleNum(vector<vector<int>> &M) {
    vector<bool> visited(M.size(), false);
    int count = 0;
    queue<int> q;

    for (int i = 0; i < M.size(); ++i) {
      if (!visited[i]) {
        q.push(i);

        while (!q.empty()) {
          int s = q.front();
          q.pop();
          visited[s] = true;

          for (int j = 0; j < M.size(); ++j) {
            if (M[s][j] == 1 && !visited[j]) {
              q.push(j);
            }
          }
        }
        count += 1;
      }
    }
    return count;
  }

  void dfs(const vector<vector<int>> &M, int i, vector<bool> &visited) {
    for (int j = 0; j < M.size(); ++j) {
      if (M[i][j] == 1 && !visited[j]) {
        visited[j] = true;
        dfs(M, j, visited);
      }
    }
  }

  int findCircleNum2(vector<vector<int>> &M) {
    vector<bool> visited(M.size(), false);

    int count = 0;

    for (int i = 0; i < M.size(); ++i) {
      if (!visited[i]) {
        dfs(M, i, visited);
        count += 1;
      }
    }
    return count;
  }
};

class Solution {
  int find_set(const vector<int> &parents, int id) {
    if (parents[id] == id) {
      return id;
    } else {
      return find_set(parents, parents[id]);
    }
  }
  void union_set(vector<int> &parents, int i, int j) {
    int p = find_set(parents, i);
    int q = find_set(parents, j);

    if (p != q) {
      parents[p] = q;
    }
  }

public:
  int findCircleNum(vector<vector<int>> &M) {
    int n = M.size();

    vector<int> parents(n);
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (M[i][j] == 1) {
          union_set(parents, i, j);
        }
      }
    }

    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
      s.insert(find_set(parents, i));
    }
    return s.size();
  }
};
