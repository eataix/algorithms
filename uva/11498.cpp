#include <iostream>

using namespace std;

int main(void)
{
    while (true) {
        int k;
        cin >> k;
        if (k == 0) {
            break;
        }
        int n, m;
        cin >> n >>m;
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            if (x == n || y == m) {
                cout << "divisa" << endl;
            }

            if (x > n && y > m) {
                cout << "NE" << endl;
            }
            if (x > n && y < m) {
                cout << "SE" << endl;
            }
            if (x < n && y > m) {
                cout << "NO" << endl;
            }
            if (x < n && y < m) {
                cout << "SO" << endl;
            }
        }
    }
}
