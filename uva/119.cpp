#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int np;
    int count = 0;
    while ( cin >> np) {
        if (count > 0) {
            cout << endl;
        }
        map<string, int> names;
        vector<string> order;
        for (int i = 0; i < np; ++i) {
            string str;
            cin >> str;
            names[str] = 0;
            order.push_back(str);
        }
        for (int i = 0; i < np; ++i) {
            string str;
            cin >> str;
            int init, ng;
            cin >> init >> ng;
            if (ng != 0) {
                int give_per_p = init / ng;
                for (int j = 0; j < ng; ++ j) {
                    string s;
                    cin >> s;
                    names[s] += give_per_p;
                }
                names[str] -= give_per_p * ng;
            }
        }
        for (int i = 0; i < np; ++i) {
            string name {order[i]};
            cout << name << " " << names[name] << endl;
        }
        count += 1;
    }
}
