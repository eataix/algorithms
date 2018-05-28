#include <iostream>
using namespace std;
/*
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (27.05%)
 * Total Accepted:    113.5K
 * Total Submissions: 419.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example 1:
 *
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 *
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
  void reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr ||
        head->next->next == nullptr) {
      return;
    }

    // Step 1: Find the midpoint of the linked list as "slow".
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *mid = slow;

    // The start of the second part will be the node _after_ the mid.
    ListNode *midHead = slow->next;
    mid->next = nullptr;

    // Step 2: Reverse the linked list started at "midHead"
    ListNode *prev = nullptr;
    ListNode *curr = midHead;
    while (curr != nullptr) {
      ListNode *oldNext = curr->next;
      curr->next = prev;
      prev = curr;
      curr = oldNext;
    }

    // Step 3: Merge
    ListNode *p1 = head;
    ListNode *p2 = prev;
    while (p2 != nullptr) {
      cout << "p1: " << p1->val << "   p2: " << p2->val << endl;

      ListNode *oldNext = p1->next;
      p1->next = p2;
      p2 = p2->next;
      p1->next->next = oldNext;
      p1 = oldNext;
    }

#ifdef DEBUG
    while (head != nullptr) {
      cout << head->val;
      head = head->next;
      if (head != nullptr) {
        cout << " -> ";
      }
    }
#endif
    cout << endl;
  }
};

#ifdef DEBUG
int main() {
  ListNode v1{1};
  ListNode v2{2};
  ListNode v3{3};
  ListNode v4{4};
  ListNode v5{5};

  v1.next = &v2;
  v2.next = &v3;
  v3.next = &v4;
  v4.next = &v5;

  Solution sol;
  sol.reorderList(&v1);
}
#endif
