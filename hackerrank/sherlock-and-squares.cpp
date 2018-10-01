#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int A, B;
    cin >> A >> B;
    cout << floor(sqrt(B)) - ceil(sqrt(A)) + 1 << endl;
  }

  return 0;
}
