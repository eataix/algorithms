#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
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
public:
  /** initialize your data structure here. */
  stack<int> internalStack;
  stack<long long> dataStack;

  MinStack() {}

  void push(int x) {
    if (internalStack.empty() || internalStack.top() >= x) {
      internalStack.push(x);
    }
    dataStack.push(x);
  }

  void pop() {
    if (internalStack.top() == dataStack.top()) {
      internalStack.pop();
    }
    dataStack.pop();
  }

  int top() { return dataStack.top(); }

  int getMin() { return internalStack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

#ifdef DEBUG
int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl;
  minStack.pop();
  cout << minStack.top() << endl;
  cout << minStack.getMin() << endl;
}
#endif