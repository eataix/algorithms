#include <bits/stdc++.h>

using namespace std;

int matrix[100][100];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    (void)cin.get();
    for (int j = 0; j < n; ++j) {
      matrix[i][j] = cin.get() - '0';
#ifdef DEBUG
      cout << matrix[i][j];
#endif
    }
#ifdef DEBUG
    cout << endl;
#endif
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
        cout << matrix[i][j];
      } else {
        int left = matrix[i - 1][j];
        int right = matrix[i + 1][j];
        int up = matrix[i][j - 1];
        int down = matrix[i][j + 1];
        int curr = matrix[i][j];
        if (curr > left && curr > right && curr > up && curr > down) {
          cout << 'X';
        } else {
          cout << matrix[i][j];
        }
      }
    }
    cout << endl;
  }

  return 0;
}
