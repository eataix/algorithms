#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i200 = 0;
    int i100 = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >>  k;
        if (k == 100) {
            i100 += 1;
        } else {
            i200 += 1;
        }
    }
    if (i100 % 2 != 0) {
        cout << "NO" << endl;
    } else {
        int r200 = i200 % 2;
        if (r200 == 1 && i100 < 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
