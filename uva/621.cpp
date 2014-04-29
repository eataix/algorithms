#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (; n > 0; --n) {
        string s;
        cin >> s;
        if (s == "1" || s == "4" || s == "78") {
            cout << "+" << endl;
        } else if (s[s.length() - 1] == '5' && s[s.length() - 2] == '3'){
            cout << "-" << endl;
        } else if (s[s.length() - 1] == '4' && s[0] == '9'){
            cout << "*" << endl;
        } else{
            cout << "?" << endl;
        }
    }
    return 0;
}
