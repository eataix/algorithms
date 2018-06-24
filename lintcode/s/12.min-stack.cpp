class MinStack {
  stack<int> minStack;
  stack<int> dataStack;

public:
  MinStack() {
    // do intialization if necessary
  }

  /*
   * @param number: An integer
   * @return: nothing
   */
  void push(int number) {
    if (minStack.empty() || number <= minStack.top()) {
      minStack.push(number);
    }

    dataStack.push(number);
  }

  /*
   * @return: An integer
   */
  int pop() {
    if (dataStack.top() == minStack.top()) {
      minStack.pop();
    }
    int res = dataStack.top();

    dataStack.pop();
    return res;
  }

  /*
   * @return: An integer
   */
  int min() { return minStack.top(); }
};
