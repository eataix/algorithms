/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.58%)
 * Total Accepted:    146K
 * Total Submissions: 477.4K
 * Testcase Example:  '[]\nno cycle'
 *
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 *
 *
 * Note: Do not modify the linked list.
 *
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#ifdef DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#endif

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        break;
      }
    }

    if (slow == nullptr || fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }

    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};
