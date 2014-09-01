#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    int n;
    cin >> n;
    map<string, string> map;
    string tmp;
    getline(cin, tmp);
    while (n--) {
        string k, v;
        getline(cin, k);
        getline(cin, v);
        map[k] = v;
    }

    int q;
    cin >> q;
    getline(cin, tmp);
    while (q--) {
        string k;
        getline(cin, k);
        cout << map[k] << endl;
    }
}
