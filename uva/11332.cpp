#include <string>
#include <iostream>

using namespace std;

int cal(string str)
{
    int sum = 0;
    for (char ch : str) {
        sum += ch - '0';
    }
    return sum;
}

int main()
{
    while (true) {
        string str;
        cin >> str;
        if (str == "0") {
            break;
        }
        while (true) {
            string str2 = to_string(cal(str));
            if (str == str2) {
                cout << str << endl;
                break;
            }
            str = str2;
        }
    }
}
