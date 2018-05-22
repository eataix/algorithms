#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#ifdef DEBUG
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
#endif

class Solution {
public:
  int minMeetingRooms(vector<Interval> &intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) { return a.start < b.start; });

    priority_queue<int, vector<int>, greater<int>> q;
    for (const auto &i : intervals) {
      if (!q.empty() && q.top() <= i.start) {
        q.pop();
      }
      q.push(i.end);
    }
    return q.size();
  }
};
