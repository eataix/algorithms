#include <string>
/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (29.86%)
 * Total Accepted:    131K
 * Total Submissions: 438.8K
 * Testcase Example:  '[]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution
{
  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode *head = new ListNode{-1};
    ListNode *curr = head;
    while (l1 != nullptr && l2 != nullptr)
    {
      if (l1->val <= l2->val)
      {
        curr->next = l1;
        l1 = l1->next;
      }
      else
      {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    if (l1 != nullptr)
    {
      curr->next = l1;
    }
    if (l2 != nullptr)
    {
      curr->next = l2;
    }
    return head->next;
  }

public:
  ListNode *sortList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    return merge(sortList(head), sortList(slow));
  }
};
