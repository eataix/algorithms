/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (39.51%)
 * Total Accepted:    217.7K
 * Total Submissions: 550.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Note:
 *
 *
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
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
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *newHead = head->next;
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    while (curr != nullptr && (next = curr->next) != nullptr) {
      ListNode *newCurr = next->next;
      if (prev != nullptr) {
        prev->next = next;
      }
      curr->next = next->next;

      next->next = curr;
      prev = curr;
      curr = newCurr;
    }

    return newHead;
  }
};
