#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    if (dx == 0 && dy == 0) {
        printf("-1\n");
    } else if (dx == 0 && dy != 0) {
        printf("%d %d %d %d\n", x1 + dy, y1, x2 + dy, y2);
    } else if (dx != 0 && dy == 0) {
        printf("%d %d %d %d\n", x1, y1 + dx, x2, y2 + dx);
    } else {
        if (dx != dy) {
            printf("-1\n");
        } else {
            printf("%d %d %d %d\n", x2, y1, x1, y2);
        }
    }
}
