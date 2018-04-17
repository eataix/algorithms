/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(-1);
    ListNode *l = head;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        l->next = l1;
        l1 = l1->next;
      } else {
        l->next = l2;
        l2 = l2->next;
      }
      l = l->next;
    }

    if (l1 != nullptr) {
      l->next = l1;
    }
    if (l2 != nullptr) {
      l->next = l2;
    }

    return head->next;
  }
};
