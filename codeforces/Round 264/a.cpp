#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    s *= 100;
    int max  = -1;
    while (n--) {
        int x, y;
        cin >> x >> y;
        int cost = x * 100 + y;
        int m = s / cost;
        if (m > 0) {
            m += 99 - (s - m * cost) % 100;
        }
        cout << cost << " " << m << endl;
        if (m > max) {
            max = m;
        }
    }
    cout << max << endl;
}
