#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int> &ratings, const vector<int> &awake, int k, int n) {
  vector<int> presums1(n + 1, 0);
  vector<int> presums2(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    presums1[i + 1] = presums1[i] + (awake[i] == 1 ? ratings[i] : 0);
    presums2[i + 1] = presums2[i] + ratings[i];
  }

  int maxValue = 0;
  for (int i = 0; i < n; ++i) {
    int end = min(i + k, n);
    int pre = presums1[i] - presums1[0];
    int mid = presums2[end] - presums2[i];
    int post = presums1[n] - presums1[end];

    maxValue = max(maxValue, pre + mid + post);
  }

  return maxValue;
}

int main() {
#ifndef DEBUG
  int N, K;
  cin >> N >> K;

  vector<int> ratings(N);
  for (int i = 0; i < N; ++i) {
    cin >> ratings[i];
  }

  vector<int> awake(N);
  for (int i = 0; i < N; ++i) {
    cin >> awake[i];
  }
  cout << solve(ratings, awake, K, N) << endl;
#else
  cout << solve({1, 3, 5, 2, 5, 4}, {1, 1, 0, 1, 0, 0}, 3, 6) << endl;
#endif
}
