#include <stack>
using namespace std;
/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (31.19%)
 * Total Accepted:    182.4K
 * Total Submissions: 584.8K
 * Testcase Example:
 * '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 *
 *
 * pop() -- Removes the element on top of the stack.
 *
 *
 * top() -- Get the top element.
 *
 *
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 */
class MinStack {
  stack<int> _dataS;
  stack<int> _minS;

public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    _dataS.push(x);
    if (_minS.empty() || x <= _minS.top()) {
      _minS.push(x);
    }
  }

  void pop() {
    if (!_minS.empty() && _dataS.top() == _minS.top()) {
      _minS.pop();
    }
    _dataS.pop();
  }

  int top() { return _dataS.top(); }

  int getMin() { return _minS.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
