class Solution {
public:
  bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
    if (org.empty()) {
      return true;
    }

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
      if (q.size() > 1)
        return false;
      int k = q.front();
      q.pop();
      if (k != org[idx++])
        return false;
      for (int i : edges[k]) {
        if (--indegree[i] == 0)
          q.push(i);
      }
    }
    return idx == N;
  }
};
