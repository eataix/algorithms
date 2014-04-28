#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i = 1;
    while (true) {
        string str;
        cin >> str;
        if (str == "*") {
            break;
        }
        if (str == "Hajj") {
            cout << "Case " << i << ": Hajj-e-Akbar" << endl;
        } else {
            cout << "Case " << i << ": Hajj-e-Asghar" << endl;
        }
        i += 1;
    }
}
