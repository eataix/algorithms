#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p;
        cin >> p;
        vector<int> ps(p);
        for (int i = 0; i < p; ++i) {
            cin >> ps[i];
        }

        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 7 == 6 || i % 7 == 0) {
                continue;
            }
            for (auto pi : ps) {
                if (i % pi == 0) {
                    count += 1;
                    break;
                }
            }
        }

        cout << count << endl;
    }
}
