#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    vector<int> map(26, 0);

    for (char ch : str) {
        map[ch - 'A'] += 1;
    }
    sort(map.begin(), map.end());

    long long sum = 0;
    for (auto it = map.crbegin(); it != map.crend(); ++it) {
        if (k == 0) {
            break;
        }
        if (k >= *it) {
            sum += static_cast<long long>(*it) * (*it);
            k -= *it;
        } else {
            sum += static_cast<long long>(k) * k;
            k = 0;
        }
        if (k == 0) {
            break;
        }
    }
    cout << sum << endl;

}
