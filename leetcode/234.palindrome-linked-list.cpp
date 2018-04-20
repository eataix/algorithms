#include <iostream>
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
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

void printLinkedList(ListNode *head) {
  if (head == nullptr) {
    cout << "Empty" << endl;
  }

  ListNode *h = head;
  while (h != nullptr) {
    cout << h->val;
    if (h->next != nullptr) {
      cout << "->";
    }
    h = h->next;
  }
  cout << endl;
}

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *second_half, *prev_of_slow_ptr = head;
    ListNode *mid_node = NULL;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      prev_of_slow_ptr = slow;
      slow = slow->next;
    }
    if (fast != nullptr) {
      mid_node = slow;
      slow = slow->next;
    }

    second_half = slow;
    prev_of_slow_ptr->next = nullptr;

    printLinkedList(head);
    printLinkedList(second_half);
    second_half = reverse(second_half);

    bool m = matchLinkedLists(head, second_half);
    reverse(second_half);
    if (mid_node != nullptr) {
      prev_of_slow_ptr->next = mid_node;
      mid_node->next = second_half;
    } else {
      prev_of_slow_ptr->next = second_half;
    }

    return m;
  }

  bool matchLinkedLists(ListNode *l1, ListNode *l2) {
    ListNode *h1 = l1;
    ListNode *h2 = l2;

    while (h1 != nullptr && h2 != nullptr) {
      if (h1->val != h2->val) {
#ifdef DEBUG
        cout << "Not matched" << endl;
#endif
        return false;
      } else {
        h1 = h1->next;
        h2 = h2->next;
      }
    }

#ifdef DEBUG
    if (h1 != nullptr) {
      cout << "h1: " << h1->val << endl;
    }

    if (h2 != nullptr) {
      cout << "h2: " << h2->val << endl;
    }
#endif

    return h1 == nullptr && h2 == nullptr;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != nullptr) {
      ListNode *oldNext = curr->next;
      curr->next = prev;
      prev = curr;
      curr = oldNext;
    }
    return prev;
  }
};

#ifdef DEBUG
int main() {
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(3);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(1);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = nullptr;

  Solution sol;
  cout << sol.isPalindrome(l1) << endl;
}
#endif
