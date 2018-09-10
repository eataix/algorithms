#include <vector>
using namespace std;
/*
 * [444] Sequence Reconstruction
 *
 * https://leetcode.com/problems/sequence-reconstruction/description/
 *
 * algorithms
 * Medium (19.57%)
 * Total Accepted:    11.4K
 * Total Submissions: 58.1K
 * Testcase Example:  '[1,2,3]\n[[1,2],[1,3]]'
 *
 * Check whether the original sequence org can be uniquely reconstructed from
 * the sequences in seqs. The org sequence is a permutation of the integers
 * from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest
 * common supersequence of the sequences in seqs (i.e., a shortest sequence so
 * that all sequences in seqs are subsequences of it). Determine whether there
 * is only one sequence that can be reconstructed from seqs and it is the org
 * sequence.
 *
 * Example 1:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3]]
 *
 * Output:
 * false
 *
 * Explanation:
 * [1,2,3] is not the only one sequence that can be reconstructed, because
 * [1,3,2] is also a valid sequence that can be reconstructed.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2]]
 *
 * Output:
 * false
 *
 * Explanation:
 * The reconstructed sequence can only be [1,2].
 *
 *
 *
 * Example 3:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
 *
 * Output:
 * true
 *
 * Explanation:
 * The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original
 * sequence [1,2,3].
 *
 *
 *
 * Example 4:
 *
 * Input:
 * org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
 *
 * Output:
 * true
 *
 *
 *
 *
 * UPDATE (2017/1/8):
 * The seqs parameter had been changed to a list of list of strings (instead of
 * a 2d array of strings). Please reload the code definition to get the latest
 * changes.
 *
 */

class Solution {
public:
  bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {

    int N = org.size();
    vector<unordered_set<int>> edges(N + 1);
    vector<int> indegree(N + 1);

    bool empty = true;
    for (auto const &seq : seqs) {
      if (seq.empty()) {
        continue;
      }
      empty = false;
      for (int i = 0; i < seq.size(); ++i) {
        int currNode = seq[i];
        if (currNode > N || currNode <= 0) {
          return false;
        }
        if (i > 0) {
          int prevNode = seq[i - 1];
          if (!edges[prevNode].count(currNode)) {
            edges[prevNode].insert(currNode);
            indegree[currNode] += 1;
          }
        }
      }
    }

    if (empty) {
      return false;
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    // In order to get a unique sequence, myq.size is always 1, also the order
    // is the same as org
    int idx = 0;
    while (!q.empty()) {
      if (q.size() > 1) {
        return false;
      }
      int k = q.front();
      q.pop();
      if (k != org[idx++]) {
        return false;
      }
      for (int i : edges[k]) {
        if (--indegree[i] == 0) {
          q.push(i);
        }
      }
    }
    return idx == N;
  }
};
