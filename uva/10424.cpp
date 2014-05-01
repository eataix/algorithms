#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int to_one(int n)
{
    string str {to_string(n)};
    while (str.length() != 1) {
        n = 0;
        for (char ch : str) {
            n += ch - '0';
        }
        str = to_string(n);
    }
    return n;
}

int main()
{
    string str1, str2;
    while (getline(cin, str1)) {
        getline(cin, str2);
        int sum1 = 0;
        int sum2 = 0;

        for (char ch : str1) {
            if (isalpha(ch)) {
                sum1 += tolower(ch) - 'a' + 1;
            }
        }

        for (char ch : str2) {
            if (isalpha(ch)) {
                sum2 += tolower(ch) - 'a' + 1;
            }
        }

        sum1 = to_one(sum1);
        sum2 = to_one(sum2);

        int maxV = max(sum1, sum2);
        int minV = min(sum1, sum2);
        printf("%.2f %%\n", static_cast<double>(minV) / maxV * 100);
    }
}
