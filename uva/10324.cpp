#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buf[1000000 + 1];

int main()
{
    int seq = 1;
    while (scanf("%s", buf) != EOF) {
        int n;
        scanf("%d", &n);
        int i, j;
        printf("Case %d:\n", seq);

        while (n > 0) {
            scanf("%d %d", &i, &j);
            if (i > j) {
                swap(i, j);
            }
            char c = buf[i];
            bool same{true};
            for (int k = i; k <= j; ++k) {
                if (buf[k] != c) {
                    same = false;
                }
            }
            if (same) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            n--;

        }
        seq += 1;
    }
}
