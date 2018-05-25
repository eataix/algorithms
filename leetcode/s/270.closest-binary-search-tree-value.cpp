#include <algorithm>
#include <cmath>
using namespace std;

#ifdef DEBUG
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
public:
  int closestValue(TreeNode *root, double target) {
    int res = root->val;
    while (root) {
      if (abs(static_cast<double>(root->val) - target) <=
          abs(static_cast<double>(res) - target)) {
        res = root->val;
      }

      if (target < root->val) {
        root = root->left;
      } else {
        root = root->right;
      }
    }

    return res;
  }
};
