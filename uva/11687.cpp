#include <iostream>
#include <string>

using namespace std;

string iter(string str)
{
    return to_string(str.length());
}

int main()
{
    string s;
    while (true) {
        cin >> s;
        if (s == "END") {
            break;
        }
        int i = 0;
        while (iter(s) != s) {
            s = iter(s);
            i += 1;
        }
        cout << i + 1 << endl;
    }
}
