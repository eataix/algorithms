#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int minV = 100;
        int maxV = -1;
        for (int j = 0; j < n; ++j) {
            int k;
            cin >> k;
            minV = min(minV, k);
            maxV = max(maxV, k);
        }
        cout << (maxV - minV) * 2 << endl;
    }
    return 0;
}
