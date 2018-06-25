/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
  /**
   * @param l1: ListNode l1 is the head of the linked list
   * @param l2: ListNode l2 is the head of the linked list
   * @return: ListNode head of linked list
   */
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);

    ListNode *curr = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        curr->next = l1;
        l1 = l1->next;
        curr = curr->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
        curr = curr->next;
      }
    }

    if (l1 != nullptr) {
      curr->next = l1;
    }
    if (l2 != nullptr) {
      curr->next = l2;
    }

    return dummy.next;
  }
};
