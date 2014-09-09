#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    int s[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    memcpy(s, v, sizeof(int) * n);
    sort(s, s + n);

    int m;
    scanf("%d", &m);
    for (int i =0; i < m; ++i) {
        int type;
        int l, r;
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1) {
            long long count = 0;
            for (int j = l; j <= r; ++j) {
                count += v[j - 1];
            }
            printf("%I64d\n", count);
        } else {
            long long count = 0;
            for (int j = l; j <= r; ++j) {
                count += s[j - 1];
            }
            printf("%I64d\n", count);
        }
    }
}
