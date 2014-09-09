#include <iostream>
#include <string>

using namespace std;

bool automaton(string str1, string str2)
{
    int last_pos = 0;
    for (int i = 0; i < str2.length(); ++i) {
        bool found = false;
        for (int j = last_pos; j < str1.length(); ++j) {
            if (str1[j] == str2[i]) {
                found = true;
                last_pos = j;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}


bool test_array(string str1, string str2)
{
    int count[26];
    for (int i = 0; i < 26; ++i) {
        count[i] = 0;
    }
    for (char ch : str1) {
        count[ch - 'a'] += 1;
    }
    for (char ch : str2) {
        count[ch - 'a'] -= 1;
    }
    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

bool test_both(string str1, string str2)
{
    int count[26];
    for (int i = 0; i < 26; ++i) {
        count[i] = 0;
    }
    for (char ch : str1) {
        count[ch - 'a'] += 1;
    }
    for (char ch : str2) {
        count[ch - 'a'] -= 1;
    }
    for (int i = 0; i < 26; ++i) {
        if (count[i] < 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.length() < str2.length()) {
        cout << "need tree" << endl;
    } else if (automaton(str1, str2)) {
        cout << "automaton" << endl;
    } else if (test_array(str1, str2)) {
        cout << "array" << endl;
    } else if (test_both(str1, str2)) {
        cout << "both" << endl;
    } else {
        cout << "need tree" << endl;
    }
}
