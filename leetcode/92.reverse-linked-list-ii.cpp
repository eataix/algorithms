/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (32.06%)
 * Total Accepted:    149.2K
 * Total Submissions: 464.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    auto dummy = new ListNode{-1};
    dummy->next = head;
    auto prev = dummy;
    for (int i = 0; i < m - 1; ++i) {
      prev = prev->next;
    }
    auto curr = prev->next;
    for (int i = 0; i < n - m; ++i) {
      auto oldNext = curr->next;
      curr->next = oldNext->next;
      oldNext->next = prev->next;
      prev->next = oldNext;
    }
    return dummy->next;
  }
};
