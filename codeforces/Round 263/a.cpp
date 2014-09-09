#include <iostream>

using namespace std;

int main()
{
    int input[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == 'o') {
                input[i][j] = 1;
            } else {
                input[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int count = 0;
            if (i - 1 >= 0) {
                count += input[i - 1][j];
            }
            if (i + 1 < n) {
                count += input[i + 1][j];
            }
            if (j - 1 >= 0) {
                count += input[i][j - 1];
            }
            if (j + 1 < n) {
                count += input[i][j + 1];
            }
            if (count % 2 != 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
