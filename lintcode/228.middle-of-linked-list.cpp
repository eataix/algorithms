/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
  /*
   * @param head: the head of linked list.
   * @return: a middle node of the linked list
   */
  ListNode *middleNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    auto fast = head->next;
    auto slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }
};