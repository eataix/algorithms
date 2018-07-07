#include <stack>
using namespace std;
/*
 * [716] Max Stack
 *
 * https://leetcode.com/problems/max-stack/description/
 *
 * algorithms
 * Hard (36.95%)
 * Total Accepted:    5.9K
 * Total Submissions: 15.9K
 * Testcase Example:
 * '["MaxStack","push","push","push","top","popMax","top","peekMax","pop","top"]\n[[],[5],[1],[5],[],[],[],[],[],[]]'
 *
 * Design a max stack that supports push, pop, top, peekMax and popMax.
 *
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Remove the element on top of the stack and return it.
 * top() -- Get the element on the top.
 * peekMax() -- Retrieve the maximum element in the stack.
 * popMax() -- Retrieve the maximum element in the stack, and remove it. If you
 * find more than one maximum elements, only remove the top-most one.
 *
 *
 *
 * Example 1:
 *
 * MaxStack stack = new MaxStack();
 * stack.push(5);
 * stack.push(1);
 * stack.push(5);
 * stack.top(); -> 5
 * stack.popMax(); -> 5
 * stack.top(); -> 1
 * stack.peekMax(); -> 5
 * stack.pop(); -> 1
 * stack.top(); -> 5
 *
 *
 *
 * Note:
 *
 * -1e7
 * Number of operations won't exceed 10000.
 * The last four operations won't be called when stack is empty.
 *
 *
 */
class MaxStack {
  stack<int> dataS;
  stack<int> maxS;

public:
  /** initialize your data structure here. */
  MaxStack() {}

  void push(int x) {
    if (maxS.empty() || maxS.top() <= x) {
      maxS.push(x);
    }
    dataS.push(x);
  }

  int pop() {
    if (!maxS.empty() && maxS.top() == dataS.top()) {
      maxS.pop();
    }

    auto res = dataS.top();
    dataS.pop();
    return res;
  }

  int top() { return dataS.top(); }

  int peekMax() { return maxS.top(); }

  int popMax() {
    auto mx = maxS.top();
    stack<int> s;

    while (dataS.top() != mx) {
      s.push(dataS.top());
      dataS.pop();
    }

    dataS.pop();
    maxS.pop();

    while (!s.empty()) {
      push(s.top());
      s.pop();
    }

    return mx;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
