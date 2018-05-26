#include <queue>
#include <vector>
using namespace std;
#ifdef DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#endif

class Solution {
public:
  ListNode *mergeKLists(const vector<ListNode *> &lists) {
    ListNode dummy{-1};
    auto cmp = [](const ListNode *a, ListNode *b) { return a->val > b->val; };

    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);

    for (const auto &list : lists) {
      if (list != nullptr) {
        q.push(list);
      }
    }

    ListNode *prev = &dummy;
    while (!q.empty()) {
      ListNode *curr = q.top();
      q.pop();
      prev->next = curr;
      prev = curr;
      if (curr->next != nullptr) {
        q.push(curr->next);
      }
    }

    return dummy.next;
  }
};
