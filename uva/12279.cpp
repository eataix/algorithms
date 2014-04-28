#include <iostream>

using namespace std;

int main()
{
    int c = 1;
    while (true) {
        int t;
        cin >> t;
        if (t == 0) {
            break;
        }
        int treat = 0;
        int  party = 0;
        for (int i = 0; i < t; ++i) {
            int j;
            cin >> j;
            if (j == 0) {
                treat += 1;
            } else {
                party += 1;
            }
        }
        cout << "Case " << c << ": " << party - treat << endl;
        c += 1;
    }
}
