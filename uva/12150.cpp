#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> r(n, -1);
        bool failed = false;
        for (int i = 0; i < n; ++i) {
            int c, p;
            cin >> c >> p;
            int orig = i + p;
            if (orig >= 0 && orig < n && r[orig] == -1) {
                r[orig] = c;
            } else {
                failed = true;
            }
        }
        if (failed) {
            cout << -1 << endl;
        } else {
            for (auto it = r.cbegin(); it != r.cend(); ++it) {
                cout << *it;
                if (it + 1 != r.cend()) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}
