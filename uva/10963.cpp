#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int yes = true;
        int a, b;
        cin >> a >> b;
        int diff = a - b;
        for (; n > 1; --n) {
            int a, b;
            cin  >> a >> b;
            if (a - b != diff) {
                yes = false;
            }
        }
        if (yes) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

        if (i < t - 1) {
            cout << endl;
        }
    }
}
