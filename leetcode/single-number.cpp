#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    (void)n;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      ret ^= A[i];
    }
    return ret;
  }
};

#ifdef DEBUG
int main() {
  Solution s;
  int A[] = {1, 2, 2, 1, 4};
  cout << s.singleNumber(A, 5) << endl;
}
#endif
