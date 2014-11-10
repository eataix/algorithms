#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int singleNumber(int A[], int n) {
            int ret = A[0];
            for (int i = 1; i < n; ++i) {
                ret ^= A[i];
            }
            return ret;
        }
};
