#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    while (true) {
        int k, m;
        cin >> k;
        if (k == 0) {
            break;
        }
        cin >> m;
        vector<int> taken(k);
        for (int i = 0; i < k; ++i) {
            cin >> taken[i];
        }
        int yes = true;
        for (int i = 0; i < m; ++i) {
            int c, r;
            cin >> c >> r;
            int no;
            int t = 0;
            for (int j = 0; j < c; ++j) {
                cin >> no;
                if (find(taken.cbegin(), taken.cend(), no) != taken.cend()) {
                    t += 1;
                }
            }
            if (t < r) {
                yes = false;
            }
        }
        if (yes) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
