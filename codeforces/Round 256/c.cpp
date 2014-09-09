#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int count = 0;

    if (n > 1) {
        int minV = 5001;
        for (int v : a) {
            if (v < minV) {
                minV = v;
            }
        }
        if (n <= minV) {
            cout << n << endl;
            return 0;
        } else {
            for (int &v : a) {
                v -= minV;
            }
            count += minV;
        }
    }

    int rem = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            rem += 1;
        }
    }
    while (rem != 0) {
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                int minV = a[i];
                int c = 1;
                for (int j = i + 1; j < n; ++j) {
                    if (a[j] > 0){
                        c += 1;
                        if (a[j] < minV) {
                            minV = a[j];
                        }
                    } else {
                        break;
                    }
                }
                if (c == 1) {
                    a[i] = 0;
                    count += 1;
                } else {
                    if (c <= minV) {
                        count += c;
                        for (int j = i; j < n; ++j) {
                            if (a[j] > 0) {
                                a[j] = 0;
                            } else {
                                break;
                            }
                        }
                    } else {
                        count += minV;
                        for (int j = i; j < n; ++j) {
                            if (a[j] > 0) {
                                a[j] -= minV;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }
        rem = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                rem += 1;
            }
        }
    }
    cout << count << endl;
}
