#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        int mike = 0;
        int juice = 0;
        for (int j = 0; j < n; ++j) {
            int d;
            cin >> d;
            mike += 10 * (d / 30 + 1);
            juice += 15 * (d / 60 + 1);
        }
        if (mike < juice) {
            printf("Case %d: Mile %d", i, mike);
        } else if (mike > juice) {
            printf("Case %d: Juice %d", i, juice);
        } else {
            printf("Case %d: Mile Juice %d", i, juice);
        }
        printf("\n");
    }
}
