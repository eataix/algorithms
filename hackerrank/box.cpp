#include <bits/stdc++.h>

using namespace std;

int main() {
  int M, N;
  cin >> M >> N;
  map<vector<int>, int> map;
  for (int i = 0; i < M; ++i) {
    string str;
    cin >> str;
    vector<int> v(N, 0);
    for (int j = 0; j < N; ++j) {
      char ch = str[j];
      if (ch == 'T') {
        v[j] = 1;
      }
    }
    if (v[0] == 1) {
      for (int j = 0; j < N; ++j) {
        if (v[j] == 1) {
          v[j] = 0;
        } else {
          v[j] = 1;
        }
      }
    }
    /*
    for (int j = 0; j < N; ++j) {
        cout << v[j] << " ";
    }
    cout << endl;
    */
    map[v] += 1;
  }
  int maxV = 0;
  for (auto kv : map) {
    maxV = max(maxV, kv.second);
  }
  cout << maxV << endl;
  return 0;
}
