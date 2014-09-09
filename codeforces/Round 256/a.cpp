#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int a1, a2, a3;
    int b1, b2, b3;
    int n;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;
    int a = a1 + a2 + a3;
    int b = b1 + b2 + b3;
    int needed = 0;
    if (a % 5 == 0) {
        needed += (int) (a / 5);
    } else {
        needed += (int) (a / 5) + 1;
    }
    if (b % 5 == 0) {
        needed += (int) (b / 10);
    } else {
        needed += (int) (b / 10) + 1;
    }
    if (needed <= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
