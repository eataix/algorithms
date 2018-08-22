/*
 * [369] Plus One Linked List
 *
 * https://leetcode.com/problems/plus-one-linked-list/description/
 *
 * algorithms
 * Medium (54.95%)
 * Total Accepted:    24.4K
 * Total Submissions: 44.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-negative integer represented as non-empty a singly linked list
 * of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 *
 * Example:
 *
 * Input:
 * 1->2->3
 *
 * Output:
 * 1->2->4
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
  ListNode *plusOne(ListNode *head) {
    auto dummy = new ListNode(0);
    dummy->next = head;

    auto nonNine = dummy;

    auto curr = head;
    while (curr != nullptr) {
      if (curr->val != 9) {
        nonNine = curr;
      }
      curr = curr->next;
    }

    nonNine->val += 1;

    curr = nonNine->next;
    while (curr != nullptr) {
      curr->val = 0;
      curr = curr->next;
    }

    return dummy->val == 0 ? dummy->next : dummy;
  }
};
