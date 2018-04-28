/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.63%)
 * Total Accepted:    477.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int v1 = l1 == nullptr ? 0 : l1->val;
      int v2 = l2 == nullptr ? 0 : l2->val;
      int sum = v1 + v2 + carry;

      ListNode *curr = new ListNode(sum % 10);
      prev->next = curr;
      prev = curr;

      if (l1 != nullptr) {
        l1 = l1->next;
      }

      if (l2 != nullptr) {
        l2 = l2->next;
      }

      carry = sum / 10;
    }

    return dummy->next;
  }
};
