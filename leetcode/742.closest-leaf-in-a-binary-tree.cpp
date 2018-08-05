#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * [743] Closest Leaf in a Binary Tree
 *
 * https://leetcode.com/problems/closest-leaf-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (34.41%)
 * Total Accepted:    4.1K
 * Total Submissions: 11.8K
 * Testcase Example:  '[1,3,2]\n1'
 *
 * Given a binary tree where every node has a unique value, and a target key k,
 * find the value of the nearest leaf node to target k in the tree.
 *
 * Here, nearest to a leaf means the least number of edges travelled on the
 * binary tree to reach any leaf of the tree.  Also, a node is called a leaf if
 * it has no children.
 *
 * In the following examples, the input tree is represented in flattened form
 * row by row.
 * The actual root tree given will be a TreeNode object.
 *
 * Example 1:
 *
 * Input:
 * root = [1, 3, 2], k = 1
 * Diagram of binary tree:
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 *
 * Output: 2 (or 3)
 *
 * Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
 *
 *
 * Example 2:
 *
 * Input:
 * root = [1], k = 1
 * Output: 1
 *
 * Explanation: The nearest leaf node is the root node itself.
 *
 *
 *
 *
 * Example 3:
 *
 * Input:
 * root = [1,2,3,4,null,null,null,5,null,6], k = 2
 * Diagram of binary tree:
 * ⁠            1
 * ⁠           / \
 * ⁠          2   3
 * ⁠         /
 * ⁠        4
 * ⁠       /
 * ⁠      5
 * ⁠     /
 * ⁠    6
 *
 * Output: 3
 * Explanation: The leaf node with value 3 (and not the leaf node with value 6)
 * is nearest to the node with value 2.
 *
 *
 *
 * Note:
 *
 * root represents a binary tree with at least 1 node and at most 1000 nodes.
 * Every node has a unique node.val in range [1, 1000].
 * There exists some node in the given binary tree for which node.val == k.
 *
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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
  TreeNode *dfs(TreeNode *root, int k,
                unordered_map<TreeNode *, TreeNode *> &parents) {
    if (root == nullptr || root->val == k) {
      return root;
    }

    if (root->left != nullptr) {
      parents[root->left] = root;
      auto left = dfs(root->left, k, parents);
      if (left != nullptr) {
        return left;
      }
    }

    if (root->right != nullptr) {
      parents[root->right] = root;
      auto right = dfs(root->right, k, parents);
      if (right != nullptr) {
        return right;
      }
    }

    return nullptr;
  }

public:
  int findClosestLeaf(TreeNode *root, int k) {
    unordered_map<TreeNode *, TreeNode *> parents;
    auto node = dfs(root, k, parents);

    unordered_set<TreeNode *> visited;
    queue<TreeNode *> q;
    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      // A leaf
      if (curr->left == nullptr && curr->right == nullptr) {
        return curr->val;
      }

      if (curr->left != nullptr && !visited.count(curr->left)) {
        visited.insert(curr->left);
        q.push(curr->left);
      }

      if (curr->right != nullptr && !visited.count(curr->right)) {
        visited.insert(curr->right);
        q.push(curr->right);
      }

      if (parents.count(curr) && !visited.count(parents[curr])) {
        visited.insert(parents[curr]);
        q.push(parents[curr]);
      }
    }
    return -1;
  }
};
