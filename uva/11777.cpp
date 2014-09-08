#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        double term1, term2, finall, attendance;
        vector<double> class_test(3);
        cin >> term1 >> term2 >> finall >> attendance;
        cin >> class_test[0];
        cin >> class_test[1];
        cin >> class_test[2];
        sort(class_test.begin(), class_test.end());
        double average = (class_test[1] + class_test[2]) / 2;
        double total = term1 + term2 + finall + attendance + average;
        cout << "Case " << i << ": ";
        if (total >= 90) {
            cout << "A";
        } else if (total >= 80 && total < 90) {
            cout << "B";
        } else if (total >= 70 && total < 80) {
            cout << "C";
        } else if (total >= 60 && total < 70) {
            cout << "D";
        } else if (total < 60) {
            cout << "F";
        }
        cout << endl;
    }
}
