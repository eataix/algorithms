#include <cstddef>
using namespace std;
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *l = head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                l->next = l1;
                l1 = l1->next;
            }
            else
            {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }

        if (l1 != NULL)
        {
            l->next = l1;
        }
        if (l2 != NULL)
        {
            l->next = l2;
        }

        return head->next;
    }
};
