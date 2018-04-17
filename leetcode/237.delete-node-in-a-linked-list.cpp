#include <cstddef>
using namespace std;
/*
 * [237] Delete Node in a Linked List
 *
 * https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 *
 * algorithms
 * Easy (47.24%)
 * Total Accepted:    203.2K
 * Total Submissions: 430.1K
 * Testcase Example:  '[0,1]\nnode at index 0 (node.val = 0)'
 *
 *
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 *
 *
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third
 * node with value 3, the linked list should become 1 -> 2 -> 4 after calling
 * your function.
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
  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
