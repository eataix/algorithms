class Solution {
public:
  /**
   * @param N: a positive number
   * @return: how many numbers X from 1 to N are good
   */
  int rotatedDigits(int N) {
    int count = 0;

    for (int i = 1; i <= N; ++i) {
      if (isValid(i)) {
        // cout << i <<endl;
        count += 1;
      }
    }

    return count;
  }

  unordered_set<char> validChars = {'0', '1', '2', '5', '6', '8', '9'};
  unordered_set<char> mustHaveChars = {'2', '5', '6', '9'};

  bool isValid(int n) {
    string str = to_string(n);

    unordered_set<char> chars{str.begin(), str.end()};

    bool flag = false;

    for (char ch : mustHaveChars) {
      if (chars.find(ch) != chars.cend()) {
        flag = true;
        break;
      }
    }

    if (!flag) {
      return false;
    }

    for (char ch : chars) {
      if (validChars.find(ch) == validChars.end()) {
        return false;
      }
    }

    return true;
  }
};
