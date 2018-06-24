#include <algorithm>
using namespace std;
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
  /**
   * @param root: the given BST
   * @param target: the given target
   * @return: the value in the BST that is closest to the target
   */
  int closestValue(TreeNode *root, double target) {
    int closestV = root->val;
    double closestDiff = static_cast<double>(root->val) - target;

    TreeNode *curr = root;

    while (curr != nullptr) {
      double currDiff = static_cast<double>(curr->val) - target;

      if (abs(currDiff) <= abs(closestDiff)) {
        closestV = curr->val;
        closestDiff = currDiff;
      }

      if (currDiff == 0) {
        return curr->val;
      } else if (currDiff < 0) {
        curr = curr->right;
      } else {
        curr = curr->left;
      }
    }

    return closestV;
  }
};
