#include <cstddef>
using namespace std;
/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.44%)
 * Total Accepted:    155.1K
 * Total Submissions: 463.9K
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
#endif

class Solution
{
  public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = middleNode(head);
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->next == middle)
            {
                ptr->next = NULL;
            }
        }
        ListNode *reversedHalf = reverse(middle);

        while (head != NULL && reversedHalf != NULL)
        {
            if (head->val != reversedHalf->val)
            {
                return false;
            }
            head = head->next;
            reversedHalf = reversedHalf->next;
        }

        return head == NULL && reversedHalf == NULL;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *
    middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        if (head != NULL)
        {
            while (fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};
