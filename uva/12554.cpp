#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string song[] = {"Happy", "birthday", "to", "you",
                 "Happy", "birthday", "to", "you",
                 "Happy", "birthday", "to", "Rujia",
                 "Happy", "birthday", "to", "you"};

int main()
{

    int n;
    string name;
    vector<string> names;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> name;
        names.push_back(name);
    }

    int max = n % 16 == 0 ? n : 16 * (n / 16 + 1);

    for (int i = 0; i < max; ++i) {
        cout << names[i % n] << ": " << song[i % 16] << endl;
    }
}
