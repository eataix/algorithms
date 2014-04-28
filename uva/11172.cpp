#include <iostream>
#include <cmath>

using namespace std;

string cal(int n, int m)
{
    if (n < m) {
        return "<";
    } else if (n == m) {
        return "=";
    } else {
        return ">";
    }
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
