/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (33.57%)
 * Total Accepted:    122.7K
 * Total Submissions: 365.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example:
 *
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
  ListNode *partition(ListNode *head, int x) {
    ListNode dummy1{-1};
    ListNode dummy2{-1};
    ListNode *p1 = &dummy1;
    ListNode *p2 = &dummy2;

    ListNode *curr = head;
    while (curr != nullptr) {
      if (curr->val < x) {
        p1->next = curr;
        p1 = p1->next;
      } else {
        p2->next = curr;
        p2 = p2->next;
      }
      curr = curr->next;
    }
    p2->next = nullptr;
    p1->next = dummy2.next;
    return dummy1.next;
  }
};
