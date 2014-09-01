#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
    public:
    int day_, month_, year_;
    string name_;

    Person(string name, int day, int month, int year) {
        name_ = name;
        day_ = day;
        month_ = month;
        year_ = year;
    }

    bool operator< (const Person &p) const {
        if (year_ != p.year_) {
            return year_ < p.year_;
        } else {
            if (month_ != p.month_) {
                return month_ < p.month_;
            } else {
                return day_ < p.day_;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Person> list;
    while (n--) {
        string name;
        int d, m, y;
        cin >> name;
        cin >> d >> m >> y;
        list.emplace_back(name, d, m, y);
    }
    sort(list.begin(), list.end());
    cout << list.rbegin()->name_ << endl;
    cout << list.begin()->name_ << endl;
}
