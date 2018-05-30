#ifdef DEBUG
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int val) {
    this->val = val;
    this->next = nullptr;
  }
};
#endif

class Solution {
public:
  /**
   * @param head: n
   * @return: The new head of reversed linked list.
   */
  ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *oldNext = curr->next;
      curr->next = prev;
      prev = curr;
      curr = oldNext;
    }

    return prev;
  }
};
