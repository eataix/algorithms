#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0;i<n;++i)
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define DWN(i, b, a) for (int i=b-1;i>=a;--i)
#define REP_1(i, n) for (int i=1;i<=n;++i)
#define FOR_1(i, a, b) for (int i=a;i<=b;++i)
#define DWN_1(i, b, a) for (int i=b;i>=a;--i)

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

//}/* .................................................................................................................................. */

int main()
{
    ios_base::sync_with_stdio(false);
    int p, q, l, r;
    cin >> p >> q >> l >> r;

    vector<PII> Z;
    vector<PII> X;
    REP(i, p) {
        int a, b;
        cin >> a >> b;
        Z.PB(MP(a, b));
    }

    REP(i, q) {
        int c, d;
        cin >> c >> d;
        X.PB(MP(c, d));
    }

    bool ret[1005];
    FOR_1(i, l, r) {
        ret[i] = false;
    }
    for (auto p : Z) {
        for (auto q : X) {
            int min_t = p.first - q.second;
            int max_t = p.second - q.first;
            min_t = max(min_t, l);
            max_t = min(max_t, r);

            if (min_t <= max_t) {
                FOR_1(i, min_t, max_t) {
                    ret[i] = true;
                }
            }
        }
    }
    int c = 0;
    FOR_1(i, l, r) {
        if (ret[i]) {
            c += 1;
        }
    }
    cout << c << endl;

    return 0;
}
