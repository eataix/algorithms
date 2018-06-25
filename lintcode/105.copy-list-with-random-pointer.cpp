/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  /**
   * @param head: The head of linked list with a random pointer.
   * @return: A new head of a deep copy of the list.
   */
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
      return head;
    }

    RandomListNode *curr = head;
    while (curr) {
      RandomListNode *newCurr = new RandomListNode(curr->label);
      newCurr->next = curr->next;
      curr->next = newCurr;
      curr = curr->next->next;
    }

    curr = head;
    while (curr) {
      if (curr->random) {
        curr->next->random = curr->random->next;
      }
      curr = curr->next->next;
    }

    RandomListNode *newHead = head->next;
    curr = head;
    while (curr) {
      RandomListNode *newCurr = curr->next;
      curr->next = newCurr->next;

      if (newCurr->next) {
        newCurr->next = newCurr->next->next;
      }
      curr = curr->next;
    }
    return newHead;
  }
};
