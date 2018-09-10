/*
 * [850] Insert into a Cyclic Sorted List
 *
 * https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/description/
 *
 * algorithms
 * Medium (20.17%)
 * Total Accepted:    2.5K
 * Total Submissions: 12.3K
 * Testcase Example:
 * '{"$id":"1","next":{"$id":"2","next":{"$id":"3","next":{"$ref":"1"},"val":3},"val":3},"val":3}\n0'
 *
 * Given a node from a cyclic linked list which is sorted in ascending order,
 * write a function to insert a value into the list such that it remains a
 * cyclic sorted list. The given node can be a reference to any single node in
 * the list, and may not be necessarily the smallest value in the cyclic list.
 *
 * If there are multiple suitable places for insertion, you may choose any
 * place to insert the new value. After the insertion, the cyclic list should
 * remain sorted.
 *
 * If the list is empty (i.e., given node is null), you should create a new
 * single cyclic list and return the reference to that single node. Otherwise,
 * you should return the original given node.
 *
 * The following example may help you understand the problem better:
 *
 *
 *
 *
 *
 * In the figure above, there is a cyclic sorted list of three elements. You
 * are given a reference to the node with value 3, and we need to insert 2 into
 * the list.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * The new node should insert between node 1 and node 3. After the insertion,
 * the list should look like this, and we should still return node 3.
 *
 *
 *
 *
 *
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

#ifdef DEBUG
class Node {
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val, Node *_next) {
    val = _val;
    next = _next;
  }
};
#endif

class Solution {
public:
  Node *insert(Node *head, int insertVal) {
    if (head == nullptr) {
      head = new Node(insertVal, nullptr);
      head->next = head;
      return head;
    }

    Node *prev = head;
    Node *next = head->next;
    while (!(prev->val <= insertVal && insertVal <= next->val) &&
           !(prev->val > next->val && insertVal < next->val) &&
           !(prev->val > next->val && insertVal > prev->val)) {
      prev = prev->next;
      next = next->next;
      if (prev == head)
        break;
    }

    prev->next = new Node(insertVal, next);

    return head;
  }
};
