#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int noP = 0;
    while (n > 0) {
        int event;
        cin >>  event;
        if (event == -1) {
            if (noP == 0) {
                count += 1;
            } else {
                noP -= 1;
            }
        } else {
            noP += event;
        }
        n -= 1;
    }
    cout << count << endl;
}
