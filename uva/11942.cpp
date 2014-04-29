#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int curr, next;
        int order = true;
        bool asc;
        cin >> curr >> next;
        if (curr < next) {
            asc = true;
        }
        if (curr > next) {
            asc = false;
        }
        curr = next;
        for (int j = 0; j < 8; ++j) {
            cin >> next;
            if (asc && curr > next) {
                order = false;
            } else if (!asc && curr < next) {
                order = false;
            }
            curr = next;
        }
        if (i == 0) {
            cout << "Lumberjacks:" << endl;
        }
        if (order) {
            cout << "Ordered" << endl;
        } else {
            cout << "Unordered" << endl;
        }
    }
}
