#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  long long t;
  long long x, y, z, b, w;
  cin >> t;

  while (t--) {
    cin >> b >> w;
    cin >> x >> y >> z;

    x = min(y + z, x);
    y = min(x + z, y);

    cout << x * b + y * w << endl;
  }

  return 0;
}
