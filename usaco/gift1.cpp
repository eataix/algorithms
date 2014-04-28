/*
ID: kid85781
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout {"gift1.out"};
    ifstream fin {"gift1.in"};
    int np;
    fin >> np;
    map<string, int> names;
    vector<string> order;
    for (int i = 0; i < np; ++i) {
        string str;
        fin >> str;
        names[str] = 0;
        order.push_back(str);
    }
    for (int i = 0; i < np; ++i) {
        string str;
        fin >> str;
        int init, ng;
        fin >> init >> ng;
        if (ng != 0) {
            int give_per_p = init / ng;
            for (int j = 0; j < ng; ++ j) {
                string s;
                fin >> s;
                names[s] += give_per_p;
            }
            names[str] -= give_per_p * ng;
        }
    }
    for (int i = 0; i < np; ++i) {
        string name {order[i]};
        fout << name << " " << names[name] << endl;
    }
}
