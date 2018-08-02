#include <cmath>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/*
 * [272] Closest Binary Search Tree Value II
 *
 * https://leetcode.com/problems/closest-binary-search-tree-value-ii/description/
 *
 * algorithms
 * Hard (40.87%)
 * Total Accepted:    25.4K
 * Total Submissions: 62.1K
 * Testcase Example:  '[4,2,5,1,3]\n3.714286\n2'
 *
 * Given a non-empty binary search tree and a target value, find k values in
 * the BST that are closest to the target.
 *
 * Note:
 *
 *
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that
 * are closest to the target.
 *
 *
 * Example:
 *
 *
 * Input: root = [4,2,5,1,3], target = 3.714286, and k = 2
 *
 * ⁠   4
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \
 * 1   3
 *
 * Output: [4,3]
 *
 * Follow up:
 * Assume that the BST is balanced, could you solve it in less than O(n)
 * runtime (where n = total nodes)?
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef DEBUG
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {

public:
  /**
   * 两个栈，pre和suc，其中pre存小于目标值的数，suc存大于目标值的数，开始初始化pre和suc的时候，要分别将最接近目标值的稍小值和稍大值压入pre和suc，然后我们循环k次，每次比较pre和suc的栈顶元素，看谁更接近目标值，将其存入结果res中，然后更新取出元素的栈，依次类推直至取完k个数返回即可
   */
  vector<int> closestKValues(TreeNode *root, double target, int k) {
    vector<int> res;
    stack<TreeNode *> pre, suc;
    while (root) {
      if (root->val <= target) {
        pre.push(root);
        root = root->right;
      } else {
        suc.push(root);
        root = root->left;
      }
    }
    while (k-- > 0) {
      if (suc.empty() ||
          (!pre.empty() && target - pre.top()->val < suc.top()->val - target)) {
        res.push_back(pre.top()->val);
        getPredecessor(pre);
      } else {
        res.push_back(suc.top()->val);
        getSuccessor(suc);
      }
    }
    return res;
  }
  void getPredecessor(stack<TreeNode *> &pre) {
    TreeNode *t = pre.top();
    pre.pop();
    if (t->left) {
      pre.push(t->left);
      while (pre.top()->right)
        pre.push(pre.top()->right);
    }
  }
  void getSuccessor(stack<TreeNode *> &suc) {
    TreeNode *t = suc.top();
    suc.pop();
    if (t->right) {
      suc.push(t->right);
      while (suc.top()->left)
        suc.push(suc.top()->left);
    }
  }

  /**
   * 堆里保存的一个差值diff和节点值的pair，我们中序遍历二叉树(也可以用其他遍历方法)，然后对于每个节点值都计算一下和目标值之差的绝对值，由于最大堆的性质，diff大的自动拍到最前面，我们维护k个pair，如果超过了k个，就把堆前面大的pair删掉，最后留下的k个pair，我们将pair中的节点值取出存入res中返回即可
   */
  vector<int> closestKValues3(TreeNode *root, double target, int k) {
    vector<int> res;
    priority_queue<pair<double, int>> q;
    inorder(root, target, k, q);
    while (!q.empty()) {
      res.push_back(q.top().second);
      q.pop();
    }
    return res;
  }
  void inorder(TreeNode *root, double target, int k,
               priority_queue<pair<double, int>> &q) {
    if (!root)
      return;
    inorder(root->left, target, k, q);
    q.push({abs(root->val - target), root->val});
    if (q.size() > k)
      q.pop();
    inorder(root->right, target, k, q);
  }

  /**
   * 接在中序遍历的过程中完成比较，当遍历到一个节点时，如果此时结果数组不到k个，我们直接将此节点值加入res中，如果该节点值和目标值的差值的绝对值小于res的首元素和目标值差值的绝对值，说明当前值更靠近目标值，则将首元素删除，末尾加上当前节点值，反之的话说明当前值比res中所有的值都更偏离目标值，由于中序遍历的特性，之后的值会更加的遍历，所以此时直接返回最终结果即可
   */
  vector<int> closestKValues2(TreeNode *root, double target, int k) {
    vector<int> res;
    inorder(root, target, k, res);
    return res;
  }

  void inorder(TreeNode *root, double target, int k, vector<int> &res) {
    if (!root)
      return;
    inorder(root->left, target, k, res);
    if (res.size() < k)
      res.push_back(root->val);
    else if (abs(root->val - target) < abs(res[0] - target)) {
      res.erase(res.begin());
      res.push_back(root->val);
    } else
      return;
    inorder(root->right, target, k, res);
  }
};
