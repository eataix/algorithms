#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, p;
    int seq = 1;
    while (true) {
        cin >> n >> p;
        if (n == 0 && p == 0) {
            break;
        }
        if (seq > 1) {
            cout << endl;
        }
        string str;
        getline(cin, str);
        while (n > 0) {
            getline(cin, str);
            n -= 1;
        }
        long long min_price = -1;
        int max_met = -1;
        string best;
        while (p > 0) {
            string name;
            getline(cin, name);
            double price;
            int met;
            cin >> price;
            cin >> met;
            if (met > max_met) {
                max_met = met;
                min_price = price;
                best = name;
            } else if (met == max_met && price < min_price) {
                min_price = price;
                best = name;
            }
        getline(cin, str);
            while (met > 0) {
                getline(cin, str);
                met -= 1;
            }
            p -= 1;
        }
        cout << "RFP #" << seq << endl;
        cout << best << endl;
        seq += 1;
    }
}
