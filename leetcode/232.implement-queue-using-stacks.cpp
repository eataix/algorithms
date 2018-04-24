#include <stack>
using namespace std;
/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (38.15%)
 * Total Accepted:    105.9K
 * Total Submissions: 277.3K
 * Testcase Example:  '["MyQueue","empty"]\n[[],[]]'
 *
 *
 * Implement the following operations of a queue using stacks.
 *
 *
 * push(x) -- Push element x to the back of queue.
 *
 *
 * pop() -- Removes the element from in front of queue.
 *
 *
 * peek() -- Get the front element.
 *
 *
 * empty() -- Return whether the queue is empty.
 *
 *
 * Notes:
 *
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 *
 */
class MyQueue {
  stack<int> oldStack;
  stack<int> newStack;

public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { newStack.push(x); }

  void shiftStacks() {
    if (oldStack.empty()) {
      while (!newStack.empty()) {
        oldStack.push(newStack.top());
        newStack.pop();
      }
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    shiftStacks();
    int v = oldStack.top();
    oldStack.pop();
    return v;
  }

  /** Get the front element. */
  int peek() {
    shiftStacks();
    return oldStack.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return oldStack.empty() && newStack.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
