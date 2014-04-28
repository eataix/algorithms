#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int total = 0;
    for (int i = 0; i < t; ++i) {
        string str;
        cin >> str;
        if (str ==  "report") {
            cout << total << endl;
        } else {
            int d;
            cin >> d;
            total += d;
        }
    }
}
