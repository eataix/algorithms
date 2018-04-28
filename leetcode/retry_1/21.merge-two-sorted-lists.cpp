/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (41.14%)
 * Total Accepted:    336.1K
 * Total Submissions: 817K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    }
    ListNode *dummy = new ListNode(-1);

    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *h = dummy;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val <= p2->val) {
        h->next = p1;
        h = h->next;
        p1 = p1->next;
      } else {
        h->next = p2;
        h = h->next;
        p2 = p2->next;
      }
    }

    if (p1 != nullptr) {
      h->next = p1;
    } else {
      h->next = p2;
    }

    return dummy->next;
  }
};
