#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    double h, u, d, f;
    while (true) {
        cin >> h >> u >> d >> f;
        if (h == 0) {
            break;
        }
        double init = 0;
        int day = 1;
        bool succ = true;
        f *= u / 100;

        while (true) {
            double h_a_c = init + u;
            if (h_a_c > h) {
                break;
            }
            double h_a_s = h_a_c - d;
            if (h_a_s < 0) {
                succ = false;
                break;
            }
            init = h_a_s;
            u -= f;
            if (u < 0) {
                u = 0;
            }
            day += 1;
        }
        if (succ) {
            cout << "success on day " << day << endl;
        } else {
            cout << "failure on day " << day << endl;
        }
    }
}
