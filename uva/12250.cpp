#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int i = 1;
    while (true) {
        string input, result;
        cin >> input;
        if (input == "#") {
            break;
        }
        if (input == "HELLO") {
            result = "ENGLISH";
        } else if (input  == "HOLA") {
            result = "SPANISH";
        } else if (input == "HALLO") {
            result = "GERMAN";
        } else if (input == "BONJOUR") {
            result = "FRENCH";
        } else if (input == "CIAO") {
            result = "ITALIAN";
        } else if (input == "ZDRAVSTVUJTE") {
            result = "RUSSIAN";
        } else {
            result = "UNKNOWN";
        }
        cout << "Case " << i << ": " << result << endl;;
        i += 1;
    }
}
