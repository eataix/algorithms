#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i  = 1; i <= t; ++i) {
        int n;
        int maxV = -1;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int c;
            cin >> c;
            maxV = max(maxV, c);
        }
        printf("Case %d: %d\n", i, maxV);
    }
}
