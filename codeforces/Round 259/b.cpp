#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int sum = 0;
    int s = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] < a[i - 1]) {
            s = i;
            sum += 1;
        }
    }
    if (sum == 0) {
        cout << 0 << endl;
    } else if (sum > 1) {
        cout << -1 << endl;
    } else if (sum == 1 && a[n] <= a[1]) {
        cout << n - s + 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
