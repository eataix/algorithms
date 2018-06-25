/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
  /*
   * @param node: the node in the list should be deletedt
   * @return: nothing
   */
  void deleteNode(ListNode *node) {
    if (node == nullptr) {
      return;
    } else if (node->next == nullptr) {
      // ???
    } else {
      node->val = node->next->val;
      node->next = node->next->next;
    }
  }
};
