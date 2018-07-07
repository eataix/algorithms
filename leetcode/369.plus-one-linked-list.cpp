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
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
  ListNode *plusOne(ListNode *head) {
    ListNode *prev = nullptr;
    auto curr = head;
    while (curr != nullptr) {
      auto oldNext = curr->next;
      curr->next = prev;
      prev = curr;
      curr = oldNext;
    }

    auto revHead = prev;
    prev = nullptr;
    int carry = 1;
    while (revHead != nullptr) {
      auto oldNext = revHead->next;
      int sum = carry + revHead->val;
      carry = sum / 10;
      revHead->val = sum % 10;
      revHead->next = prev;
      prev = revHead;
      revHead = oldNext;
    }

    auto newHead = head;
    if (carry > 0) {
      newHead = new ListNode(carry);
      newHead->next = head;
    }

    return newHead;
  }
};
