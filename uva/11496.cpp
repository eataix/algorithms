#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        int c = 0;
        for (int i = 0; i < n; ++i) {
            int l = ((i - 1) % n + n) % n;
            int r = (i + 1) % n;
            if ((h[i] > h[l] && h[i] > h[r]) ||
                    (h[i] < h[l] && h[i] < h[r])) {
                c += 1;
            }
        }
        cout << c << endl;
    }
}
