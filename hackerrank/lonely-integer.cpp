#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ret ^= a;
  }
  cout << ret << endl;
  return 0;
}
