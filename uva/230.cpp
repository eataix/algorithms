#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct book {
    string title_;
    string author_;
};

bool cmp(const book &b1, const book &b2)
{
    if (b1.author_ == b2.author_) {
        return b1.title_ < b2.title_;
    } else {
        return b1.author_ < b2.author_;
    }
}

int main()
{
    vector<book> books;
    string line;
    bool returned = false;
    while (true) {
        std::getline (std::cin, line);
        if (line == "END") {
            if (!returned) {
                sort(books.begin(), books.end(), cmp);
                returned = true;
            } else {
                break;
            }
        } else {
            if (line[0] == '\"') {
                book b;
                b.title_ = line.substr(1, line.find("\"", 1) - 1);
                b.author_ = line.substr(line.find("by ") + 3);
                cout << "title " << b.title_ << " author_ " << b.author_ << endl;
            } else if (line == "SHELVE") {
            } else {
                string n {line.substr(line.find("\""), line.size() - 1)};
                if (line[0] == 'R') {
                }
            }
        }
    }
}
