#include <unordered_set>
using namespace std;
/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (40.28%)
 * Total Accepted:    234.1K
 * Total Submissions: 581.3K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * Example 1:
 *
 *
 * Input: 1->1->2
 * Output: 1->2
 *
 *
 * Example 2:
 *
 *
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
  ListNode *deleteDuplicates2(ListNode *head) {
    unordered_set<int> seen;
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr) {
      if (seen.find(curr->val) != seen.cend()) {
        prev->next = curr->next;
      } else {
        seen.insert(curr->val);
        prev = curr;
      }
      curr = curr->next;
    }

    return head;
  }

  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *deleteDuplicates(ListNode * head) {
      if (head == nullptr || head->next == nullptr) {
        return head;
      }
      auto prev = head;
      ListNode *curr = prev;
      while ((curr = curr->next) != nullptr) {
        if (curr->val != prev->val) {
          prev->next = curr;
          prev = prev->next;
        }
      }
      prev->next = nullptr;
      return head;
    }
  }

  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *runner = curr;
      while (runner->next != nullptr) {
        if (runner->next->val == curr->val) {
          runner->next = runner->next->next;
        } else {
          runner = runner->next;
        }
      }
      curr = curr->next;
    }
    return head;
  }
};
