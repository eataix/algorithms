#include <map>
#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    for (int k = 1; k <= x; ++k) {
        int r, c, m, n;
        cin >> r >> c >> m >> n;
        map<char, int> dict;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char ch;
                cin >> ch;
                dict[ch] += 1;
            }
        }
        int max_frequency = -1;
        for (auto kv : dict) {
            max_frequency = max(max_frequency, kv.second);
        }
        int count = 0;
        for (auto kv : dict) {
            if (kv.second == max_frequency) {
                count += kv.second * m;
            } else {
                count += kv.second * n;
            }
        }
        cout << "Case " << k << ": " << count << endl;
    }
}

