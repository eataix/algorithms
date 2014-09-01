#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        if (str == "#") {
            break;
        }
        bool b = next_permutation(str.begin(), str.end());
        if (b) {
            cout << str << endl;
        } else {
            cout << "No Successor" << endl;
        }
    }
}
