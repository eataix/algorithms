#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ret = 0;
    for (int i = 0; i < n - 1; ++i) {
        ret += 1LL * a[i] * (i + 2);
    }
    ret += 1LL * a[n - 1] * n;
    cout << ret << endl;
}
