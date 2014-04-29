#include <vector>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int maxV = -1;
        vector<string> result;
        for (int j = 0; j < 10; ++j) {
            string link;
            int r;
            cin >> link >> r;
            if (r >= maxV) {
                if (r > maxV) {
                    result.clear();
                    maxV = r;
                }
                result.push_back(link);
            }
        }
        printf("Case #%d:\n", i);
        for (auto link : result) {
            cout << link << endl;
        }
    }
}
