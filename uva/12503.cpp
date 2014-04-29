#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int pos = 0;
        vector<string> rec(110);
        for (int j = 1; j <= n; ++j) {
            string str;
            cin >>  str;
            if (str == "LEFT") {
                pos -= 1;
                rec[j] = str;
            } else if (str == "RIGHT") {
                pos += 1;
                rec[j] = str;
            } else {
                int k;
                cin >> str >> k;
                str = rec[k];
                if (str == "LEFT") {
                    pos -= 1;
                } else if (str == "RIGHT") {
                    pos += 1;
                }
                rec[j] = str;
            }
        }
        cout << pos << endl;
    }
}
