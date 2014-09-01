#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define all(c) (c).begin(), (c).end()

int distance(const string &str)
{
    int min_dist= abs(str[0] - str[1]);
    for (auto it = str.cbegin(); it != str.cend() - 1; ++it) {
        min_dist = min(min_dist, abs(*it - *(it + 1)));
    }
    return min_dist;
}

int main()
{
    string str;

    while (cin >> str)
    {

        string str2 {str};
        int max_distance = distance(str);
        string max_string = str;
        for (int i = 0; i < 10; ++i) {
            prev_permutation(str2.begin(), str2.end());
            //cout << str2 << distance(str2) << endl;
            if (distance(str2) >= max_distance) {
                max_distance = distance(str2);
                max_string = str2;
            }
        }

        str2 = str;
        for (int i = 0; i < 10; ++i) {
            next_permutation(str2.begin(), str2.end());
            //cout << str2 << distance(str2) << endl;
            if (distance(str2) > max_distance) {
                max_distance = distance(str2);
                max_string = str2;
            }
        }
        cout << max_string << max_distance << endl;
    }
}
