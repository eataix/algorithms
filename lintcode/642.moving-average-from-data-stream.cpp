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
 * double param = obj.next(val);
 */
