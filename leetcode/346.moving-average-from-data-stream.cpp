#include <iostream>
#include <queue>
using namespace std;
/*
 * [346] Moving Average from Data Stream
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/description/
 *
 * algorithms
 * Easy (60.81%)
 * Total Accepted:    41.9K
 * Total Submissions: 68.8K
 * Testcase Example:
 * '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'
 *
 * Given a stream of integers and a window size, calculate the moving average
 * of all integers in the sliding window.
 *
 * For example,
 *
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 *
 *
 */
class MovingAverage {
  int _size;
  long long _running_total;
  queue<int> q;

public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    _size = size;
    _running_total = 0LL;
  }

  double next(int val) {
    if (q.size() == _size) {
      int f = q.front();
      q.pop();
      _running_total -= f;
    }

    _running_total += val;
    q.push(val);
    return static_cast<double>(_running_total) / q.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

#ifdef DEBUG
int main() {
  MovingAverage m{3};
  cout << m.next(1) << endl;
  cout << m.next(10) << endl;
  cout << m.next(3) << endl;
  cout << m.next(5) << endl;
}
#endif
