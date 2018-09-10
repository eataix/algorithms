static string dec_to_hex = "0123456789abcdef";

class Solution {
  string helper(const string &str) {

    int dec_num = stoi(str, 0, 16);
    int q = dec_num / 17;

    if ((dec_num % 17) > 8) {
      q += 1;
    }

    string res = "";
    res = res + dec_to_hex[q] + dec_to_hex[q];

    return res;
  }

public:
  string similarRGB(string color) {
    return '#' + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) +
           helper(color.substr(5, 2));
  }
};
