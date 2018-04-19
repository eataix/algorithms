/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.82%)
 * Total Accepted:    153.3K
 * Total Submissions: 593.6K
 * Testcase Example:  '{}'
 *
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 *
 *
 * Return a deep copy of the list.
 *
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#ifdef DEBUG
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};
#endif

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    RandomListNode *curr = head;

    while (curr != nullptr) {
      RandomListNode *newCurr = new RandomListNode(curr->label);
      newCurr->next = curr->next;
      curr->next = newCurr;
      curr = newCurr->next;
    }

    curr = head;
    while (curr != nullptr) {
      if (curr->random != nullptr) {
        curr->next->random = curr->random->next;
      }
      curr = curr->next->next;
    }

    RandomListNode *newHead = head->next;
    curr = head;
    while (curr != nullptr) {
      RandomListNode *currCopy = curr->next;
      curr->next = currCopy->next;
      if (currCopy->next != nullptr) {
        currCopy->next = currCopy->next->next;
      }
      curr = curr->next;
    }

    return newHead;
  }
};

#ifdef DEBUG
int main() {
  RandomListNode n1(1);
  RandomListNode n2(2);
  RandomListNode n3(3);
  n1.next = &n2;
  n1.random = &n3;
  n2.next = &n3;
  n2.random = nullptr;
  n3.next = nullptr;
  n3.random = nullptr;
  Solution sol;
  sol.copyRandomList(&n1);
}
#endif
