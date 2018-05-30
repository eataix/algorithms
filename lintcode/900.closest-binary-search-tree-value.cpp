#include <algorithm>
#include <limits>
using namespace std;
#ifdef DEBUG
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = nullptr;
  }
};
#endif

class Solution {
public:
  /**
   * @param root: the given BST
   * @param target: the given target
   * @return: the value in the BST that is closest to the target
   */
  int closestValue(TreeNode *root, double target) {
    int bestV{0};
    double bestD{numeric_limits<double>::max()};

    while (root) {
      double d{abs(static_cast<double>(root->val) - target)};
      if (d == 0) {
        return root->val;
      }
      if (d <= bestD) {
        bestD = d;
        bestV = root->val;
      }
      if (target > root->val) {
        root = root->right;
      } else if (target < root->val) {
        root = root->left;
      }
    }
    return bestV;
  }
};
