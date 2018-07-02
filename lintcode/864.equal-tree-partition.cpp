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
   * @param root: a TreeNode
   * @return: return a boolean
   */
  bool checkEqualTree(TreeNode *root) {
    vector<int> sums;

    int valueOfRoot = calculate(root, sums);
    sums.pop_back();
    if (valueOfRoot % 2 == 0) {
      for (int i : sums) {
        if (i == valueOfRoot / 2) {
          return true;
        }
      }
    }

    return false;
  }

  int calculate(TreeNode *root, vector<int> &sums) {
    if (root == nullptr) {
      return 0;
    }
    int val =
        calculate(root->left, sums) + root->val + calculate(root->right, sums);
    sums.push_back(val);

    return val;
  }
};
