#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (; n >0; --n) {
        int f;
        cin >> f;
        int total = 0;
        for (; f >0; --f) {
            int a, b, c;
            cin >> a >> b >> c;
            total += a * c;
        }
        cout << total << endl;
    }
}
