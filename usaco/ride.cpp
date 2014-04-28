/*
ID: kid85781
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout {"ride.out"};
    ifstream fin {"ride.in"};
    string group;
    string comet;

    fin >> group >> comet;

    int a = 1;
    for (char ch : group) {
        a *= ch - 'A' + 1;
    }

    int b = 1;
    for (char ch : comet) {
        b *= ch - 'A' + 1;
    }

    if (a % 47 == b % 47) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
}
