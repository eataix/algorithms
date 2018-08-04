#include <stack>
using namespace std;
/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (46.84%)
 * Total Accepted:    56.4K
 * Total Submissions: 120.4K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<ListNode *> s1;
    stack<ListNode *> s2;

    auto h1 = l1;
    while (h1) {
      s1.push(h1);
      h1 = h1->next;
    }

    auto h2 = l2;
    while (h2) {
      s2.push(h2);
      h2 = h2->next;
    }

    int sum = 0;
    auto curr = new ListNode(0);
    while (!s1.empty() || !s2.empty()) {
      if (!s1.empty()) {
        sum += s1.top()->val;
        s1.pop();
      }

      if (!s2.empty()) {
        sum += s2.top()->val;
        s2.pop();
      }

      curr->val = sum % 10;
      auto prev = new ListNode(sum / 10);
      prev->next = curr;
      curr = prev;
      sum /= 10;
    }

    return curr->val == 0 ? curr->next : curr;
  }
};
