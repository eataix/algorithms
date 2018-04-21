/*
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (44.78%)
 * Total Accepted:    92.5K
 * Total Submissions: 206.5K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 *
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
 *
 *
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
 *
 * https://www.cnblogs.com/grandyang/p/5138936.html
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
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *curr = head;
    ListNode *tail = curr;
    ListNode *next = curr->next;
    ListNode *even_head = next;

    while (curr != nullptr && next != nullptr) {
      curr = curr->next = next->next;
      if (curr != nullptr) {
        tail = curr;
      }
      next = next->next = next->next == nullptr ? nullptr : next->next->next;
    }
    tail->next = even_head;

    return head;
  }
};
