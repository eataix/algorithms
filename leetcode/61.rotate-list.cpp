/*
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (25.02%)
 * Total Accepted:    149.1K
 * Total Submissions: 594.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 *
 *
 * Example 2:
 *
 *
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }

    int len = 0;
    auto curr = head;
    while (curr != nullptr) {
      curr = curr->next;
    }
    k %= len;

    if (k == 0) {
      return head;
    }

    auto slow = head;
    auto fast = head;
    for (int i = 0; i < k; ++i) {
      fast = fast->next;
    }

    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    auto newHead = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return newHead;
  }
};
