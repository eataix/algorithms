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
//
int sumThreeSmallest(vector<int> input) {

  // Imagine a number line where `a` is the smallest element seen so far,
  // `b` is the second smallest element, and `c` is the third smallest,
  // i.e.,:
  // negative infinity ---- a ---- b ---- c ---- infinity
  int a = std::numeric_limits<int>::max();
  int b = std::numeric_limits<int>::max();
  int c = std::numeric_limits<int>::max();

  for (int i : input) {
    if (i < a) {
      // The situation is like this:
      // negative infinity ---- i (becomes the new a) ---- a (becomes the new b)
      // ---- b (becomes the new c) ---- c (evicted) ---- infinity
      c = b;
      b = a;
      a = i;
    } else if (a <= i && i < b) {
      // The situation is like this:
      // negative infinity ---- a (unchanged) -- i (becomes the new b) -- b
      // (becomes the new c) ---- c (evicted) ---- infinity
      c = b;
      b = i;
    } else if (b <= i && i < c) {
      // The situation is like this:
      // negative infinity ---- a (unchanged) ---- b (unchanged) -- i (become
      // the new c) -- c (evicted) ---- infinity
      c = i;
    }
  }

  int ret = 0;
  if (a != std::numeric_limits<int>::max()) {
    ret += a;
  }
  if (b != std::numeric_limits<int>::max()) {
    ret += b;
  }
  if (c != std::numeric_limits<int>::max()) {
    ret += c;
  }

  return ret;
}

int main() {
  int res;
  int _input_size;
  cin >> _input_size;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  vector<int> _input;
  int _input_item;
  for (int _input_i = 0; _input_i < _input_size; _input_i++) {
    cin >> _input_item;
    _input.push_back(_input_item);
  }
  res = sumThreeSmallest(_input);
  cout << res;

  return 0;
}