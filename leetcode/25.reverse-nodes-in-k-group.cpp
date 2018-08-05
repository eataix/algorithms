/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (32.67%)
 * Total Accepted:    135.5K
 * Total Submissions: 414.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
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
  ListNode *reverse(ListNode *head, ListNode *tail) {
    auto prev = tail;
    while (head != tail) {
      auto oldNext = head->next;
      head->next = prev;
      prev = head;
      head = oldNext;
    }
    return prev;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    auto curr = head;
    for (int i = 0; i < k; ++i) {
      if (curr == nullptr) {
        return head;
      }
      curr = curr->next;
    }

    auto newHead = reverse(head, curr);
    head->next = reverseKGroup(curr, k);
    return newHead;
  }
};
