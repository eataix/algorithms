#include <cmath>
#include <iostream>
#include <stddef.h>
using namespace std;
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

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return addTwoNumbers(l1, l2, 0);
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
    if (l1 == NULL && l2 == NULL) {
      return carry == 0 ? NULL : new ListNode(carry);
    }

    ListNode *newl1 = l1 == NULL ? NULL : l1->next;
    ListNode *newl2 = l2 == NULL ? NULL : l2->next;
    int i1 = l1 == NULL ? 0 : l1->val;
    int i2 = l2 == NULL ? 0 : l2->val;

    int newValue = i1 + i2 + carry;
    ListNode *res = new ListNode(newValue % 10);
    res->next = addTwoNumbers(newl1, newl2, newValue / 10);
    return res;
  }
};
