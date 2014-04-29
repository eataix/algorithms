#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int prev, next;
        cin >> prev;
        int short_jump = 0, long_jump = 0;
        for (int j = 0; j < n - 1; ++j) {
            cin >> next;
            if (prev > next) {
                short_jump += 1;
            }
            if (prev < next) {
                long_jump += 1;
            }
            prev = next;
        }
        cout << "Case " << i + 1 << ": " << long_jump << " " << short_jump << endl;
    }
}
