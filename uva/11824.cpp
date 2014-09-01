#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        vector<int> ls;
        while (true) {
            int l;
            cin >> l;
            if (l == 0) {
                break;
            }
            ls.push_back(l);
        }
        sort(ls.begin(), ls.end());
        reverse(ls.begin(), ls.end());
        bool failed = false;
        long long total_cost = 0;
        for (auto it = ls.cbegin(); it != ls.cend(); ++it) {
            long long cost = pow(*it, it - ls.cbegin() + 1);
            if (cost > 5000000 || cost * 2 > 5000000) {
                cout << "Too expensive" << endl;
                failed = true;
                break;
            }
            total_cost += cost * 2;
            //cout << total_cost << endl;
            if (total_cost > 5000000) {
                cout << "Too expensive" << endl;
                failed = true;
                break;
            }
        }
        if (!failed) {
            cout << total_cost << endl;
        }
    }
}
