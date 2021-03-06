#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define DWN(i, b, a) for (int i = b - 1; i >= a; --i)
#define REP_1(i, n) for (int i = 1; i <= n; ++i)
#define FOR_1(i, a, b) for (int i = a; i <= b; ++i)
#define DWN_1(i, b, a) for (int i = b; i >= a; --i)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()

#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int((A).size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>

typedef long long LL;
typedef double DB;
typedef unsigned uint;
typedef unsigned long long uLL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

//}/*
//..................................................................................................................................
//*/

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    string str;
    cin >> str;

    bool found = false;
    for (int i = str.size() - 2; i >= 0 && !found; --i) {
      for (int j = str.size() - 1; j > i; --j) {
        if (str[i] < str[j]) {
          swap(str[i], str[j]);
          found = true;
          break;
        }
      }
    }

    if (!found) {
      cout << "no answer" << endl;
    } else {
      cout << str << endl;
    }
  }

  return 0;
}
