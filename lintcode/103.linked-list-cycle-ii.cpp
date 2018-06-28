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
   * @param head: The first node of linked list.
   * @return: The node where the cycle begins. if there is no cycle, return null
   */
  ListNode *detectCycle(ListNode *head) {
    bool hasCycle = false;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (slow == fast) {
        hasCycle = true;
        break;
      }
    }

    if (!hasCycle) {
      return false;
    }

    slow = head;

    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};
