#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int T, N, K;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N >> K;
    int ret = 0;
    for (int j = 0; j < N; ++j) {
      int n;
      cin >> n;
      if (n <= 0) {
        ++ret;
      }
    }
    if (ret < K) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
