#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#ifdef DEBUG
class Interval {
public:
  int start, end;
  Interval(int start, int end) : start{start}, end{end} {}
};
#endif

class Solution {
public:
  /**
   * @param intervals: an array of meeting time intervals
   * @return: the minimum number of conference rooms required
   */
  int minMeetingRooms(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const Interval &i1, const Interval &i2) {
           return i1.start < i2.start;
         });

    auto cmp = [](const Interval &i1, const Interval &i2) {
      return i1.end > i2.end;
    };

    priority_queue<Interval, vector<Interval>, decltype(cmp)> q{cmp};
    for (auto &i : intervals) {
      cout << i.start << " " << i.end << endl;
      if (!q.empty() && q.top().end <= i.start) {
        q.pop();
      }
      q.push(i);
    }
    return q.size();
  }
};

#ifdef DEBUG
int main() {
  Interval i1{0, 30};
  Interval i2{5, 10};
  Interval i3{15, 20};

  vector<Interval> intervals{i1, i2, i3};

  Solution sol;
  cout << sol.minMeetingRooms(intervals) << endl;
}
#endif
