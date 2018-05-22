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
    while (root != nullptr) {
      if (abs(target - res) >= abs(root->val - target)) {
        res = root->val;
      }
      root = target < root->val ? root->left : root->right;
    }
    return res;
  }
};
