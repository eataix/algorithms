#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        if (y + k <= 5) {
            count += 1;
        }
    }
    cout << count / 3 << endl;
}
