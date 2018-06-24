#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  /**
   * @param source : A string
   * @param target: A string
   * @return: A string denote the minimum window, return "" if there is no such
   * a string
   */
  string minWindow(string &source, string &target) {
    unordered_map<char, int> needed;
    unordered_map<char, int> contained;

    for (char ch : target) {
      needed[ch] += 1;
      contained[ch] = 0;
    }

    int numNeeded = target.size();

    int minStart = -1;
    int minLen = source.size() + 1;
    int count = 0;

    for (int start = 0, end = 0; end < source.size(); end += 1) {
      char currChar = source[end];
      if (needed.count(currChar)) {
        contained[currChar] += 1;

        if (contained[currChar] <= needed[currChar]) {
          count += 1;
        }

        while (count == numNeeded) {
          int len = end - start + 1;

          if (len < minLen) {
            minStart = start;
            minLen = len;
          }

          if (needed.count(source[start])) {
            contained[source[start]] -= 1;
            if (contained[source[start]] < needed[source[start]]) {
              count -= 1;
            }
          }
          start += 1;
        }
      }
    }

    return minStart == -1 ? "" : source.substr(minStart, minLen);
  }
};
