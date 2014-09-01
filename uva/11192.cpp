#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        string s;
        cin >> s;
        string::iterator iter(s.begin());
        size_t groupSize = s.size() / n;
        for ( ; iter != s.end(); iter += groupSize)
            reverse(iter, iter + groupSize);
        cout << s << endl;;
    }
}
