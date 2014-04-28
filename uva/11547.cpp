#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int r = (n * 567 / 9 + 7492) * 235 / 47 - 498;
        string s {to_string(r)};
        cout << s[s.length() - 2] << endl;
    }
}
