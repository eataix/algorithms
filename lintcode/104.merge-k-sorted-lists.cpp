#include <queue>
#include <vector>
using namespace std;
#ifdef DEBUG
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int val) {
    this->val = val;
    this->next = NULL;
  }
};
#endif
class Solution {
public:
  /**
   * @param lists: a list of ListNode
   * @return: The head of one sorted list.
   */
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](const ListNode *l1, const ListNode *l2) {
      return l1->val > l2->val;
    };

    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq{cmp};

    for (auto list : lists) {
      if (list != nullptr) {
        pq.push(list);
      }
    }

    ListNode dummy(-1);
    ListNode *curr = &dummy;
    while (!pq.empty()) {
      auto l = pq.top();
      pq.pop();
      curr->next = l;
      if (l->next) {
        pq.push(l->next);
      }
      curr = l;
    }
    return dummy.next;
  }
};
