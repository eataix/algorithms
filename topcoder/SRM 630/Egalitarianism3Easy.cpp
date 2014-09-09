#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <limits>
#include <map>

using namespace std;

class Egalitarianism3Easy {
    public:
public:
        int bitcount(int x) {
            int ans = 0;
            while (x) {
                ans += (x&1);
                x >>= 1;
            }
            return ans;
        }

        int maxCities(int n, vector<int> a, vector<int> b, vector<int> len) {
            int g[15][15];
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++) {
                    if (i == j) g[i][j] = 0;
                    else g[i][j] = 1000000000;
                }
            for (int i = 0; i < n - 1; i++)
                g[a[i]][b[i]] = g[b[i]][a[i]] = len[i];
            for (int k = 1; k <= n; k++) {
                for (int i = 1 ; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
            int tmp[15], tn;
            int ans = 1;
            for (int i = 1; i < (1<<n); i++) {
                tn = 0;
                for (int j = 0; j < n; j++) {
                    if (i&(1<<j)) {
                        tmp[tn++] = j + 1;
                    }
                }
                int ss = -1;
                int flag = 0;
                for (int j = 0; j < tn; j++) {
                    for (int k = j + 1; k < tn; k++) {
                        if (ss == -1) ss = g[tmp[j]][tmp[k]];
                        else {
                            if (ss != g[tmp[j]][tmp[k]]) {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if (flag)
                        break;
                }
                if (flag == 0) ans = max(ans, bitcount(i));
            }
            return ans;
        }
};

// CUT begin
ifstream data("Egalitarianism3Easy.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, vector<int> a, vector<int> b, vector<int> len, int __expected) {
    time_t startClock = clock();
    Egalitarianism3Easy *instance = new Egalitarianism3Easy();
    int __result = instance->maxCities(n, a, b, len);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int n;
        from_stream(n);
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        vector<int> len;
        from_stream(len);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, a, b, len, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1409912107;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "Egalitarianism3Easy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
