/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (46.74%)
 * Total Accepted:    338.7K
 * Total Submissions: 724.7K
 * Testcase Example:  '[]'
 *
 * Reverse a singly linked list.
 *
 * click to show more hints.
 *
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
  ListNode *reverseList(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr) {
      ListNode *newNext = curr->next;
      curr->next = prev;
      prev = curr;
      curr = newNext;
    }
    return prev;
  }

  ListNode *reverseList2(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *first = head;
    ListNode *rest = head->next;

    if (rest == nullptr) {
      return first;
    }

    ListNode *newHead = reverseList2(rest);
    first->next->next = first;
    first->next = nullptr;

    return newHead;
  }
};
