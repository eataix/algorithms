#include <iostream>
#include <cmath>

using namespace std;

int cal(int n, int m)
{
    return ceil((n - 2) / 3.) * ceil((m - 2) / 3.);
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int n, m;
        cin >> n >> m;
        cout << cal(n, m) << endl;
    }
    return 0;
}
