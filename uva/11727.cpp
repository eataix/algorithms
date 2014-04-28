#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        vector<int> v;
        for (int j = 0; j < 3; ++j) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        sort(v.begin(), v.end());
        cout << "Case " << (i + 1) << ": " << v[1] << endl;
    }
}
