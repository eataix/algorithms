#include <algorithm>
#include <cmath>
#include <cstddef>
using namespace std;
/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.85%)
 * Total Accepted:    185.9K
 * Total Submissions: 602.8K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗
 * B:     b1 → b2 → b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 *
 *
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = 0;
        ListNode *ptrA = headA;
        while (ptrA != NULL)
        {
            lenA += 1;
            ptrA = ptrA->next;
        }

        int lenB = 0;
        ListNode *ptrB = headB;
        while (ptrB != NULL)
        {
            lenB += 1;
            ptrB = ptrB->next;
        }

        ListNode *longer;
        ListNode *shorter;
        if (lenA > lenB)
        {
            longer = headA;
            shorter = headB;
        }
        else
        {
            longer = headB;
            shorter = headA;
        }

        int diff = abs(lenA - lenB);

        for (int i = 0; i < diff; ++i)
        {
            longer = longer->next;
        }

        while (longer != NULL && shorter != NULL && longer != shorter)
        {
            longer = longer->next;
            shorter = shorter->next;
        }

        if (longer == shorter)
        {
            return longer;
        }
        else
        {
            return NULL;
        }
    }
};
