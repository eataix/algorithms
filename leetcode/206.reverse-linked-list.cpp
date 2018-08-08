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

    auto curr = head;
    ListNode *prev = nullptr;

    while (curr != nullptr) {
      auto oldNext = curr->next;
      curr->next = prev;
      prev = curr;
      curr = oldNext;
    }

    return prev;
  }
};
