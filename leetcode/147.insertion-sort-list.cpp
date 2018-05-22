/*
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (33.91%)
 * Total Accepted:    119.1K
 * Total Submissions: 351.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 *
 *
 *
 *
 *
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 *
 *
 *
 *
 *
 * Algorithm of Insertion Sort:
 *
 *
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
  ListNode *insertionSortList(ListNode *head) {
    ListNode *dummy = new ListNode(-1);
    while (head != nullptr) {
      ListNode *curr = head;
      ListNode *p = dummy;
      head = head->next;
      while (p->next != nullptr && p->next->val <= curr->val) {
        p = p->next;
      }
      curr->next = p->next;
      p->next = curr;
    }
    return dummy->next;
  }
};
