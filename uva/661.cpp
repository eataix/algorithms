#include <iostream>

using namespace std;

int main()
{
    long long n, m, c;
    int seq = 1;
    while (true) {
        cin >> n >> m >> c;
        long long cap[21];
        long long state[21];
        if (n == 0) {
            break;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> cap[i];
            state[i] = false;
        }
        long long maxv = -1;
        long long cur = 0;
        for (int i = 1; i <= m; ++i) {
            int j;
            cin >> j;
            if (state[j]) { // turned on
                cur -= cap[j];
            } else {
                cur += cap[j];
                if (cur > maxv) {
                    maxv = cur;
                }
            }
            state[j] = !state[j];
        }
        cout << "Sequence " <<  seq << endl;
        if (maxv > c) {
            cout << "Fuse was blown." << endl;
        } else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << maxv << " amperes." << endl;
        }
        seq += 1;
        cout << endl;
    }
}
