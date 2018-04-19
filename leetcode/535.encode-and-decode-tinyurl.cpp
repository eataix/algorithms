#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (73.85%)
 * Total Accepted:    36.6K
 * Total Submissions: 49.5K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 *
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 *
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 */

class Solution {
  const string keys =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  unordered_map<string, string> longToShort = {{"", ""}};
  unordered_map<string, string> shortToLong = {{"", ""}};
  int i = 0;
  string prev = "";

public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (longToShort.find(longUrl) != longToShort.end()) {
      return longToShort[longUrl];
    }
    string curr = prev;
    if (curr.empty()) {
      curr += keys[0];
    } else {
      if (i == keys.size() - 1) {
        curr += keys[0];
      } else {
        curr[curr.size() - 1] = keys[i];
      }
    }
    longToShort[longUrl] = curr;
    shortToLong[curr] = longUrl;
    prev = curr;
    i = (i + 1) % keys.size();

    return curr;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    if (shortToLong.find(shortUrl) == shortToLong.end()) {
      return "";
    } else {
      return shortToLong[shortUrl];
    }
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
#ifdef DEBUG
int main() {
  Solution solution;
  cout << solution.encode("a") << endl;
  cout << solution.encode("b") << endl;
  cout << solution.encode("b") << endl;
  cout << solution.encode("d") << endl;
}
#endif
