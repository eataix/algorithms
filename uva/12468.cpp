#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) {
            break;
        } else if (a == 0 && b == 99) {
            cout << 1 << endl;
        } else if (a == 99 && b == 0) {
            cout << 1 << endl;
        } else {
            int c  = abs(b - a);
            if (c >= 50) {
                c = 100 -c;
            }
            cout << c << endl;
        }
    }
}
