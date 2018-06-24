#include<stack>
#include<vector>
using namespace std;
/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (47.48%)
 * Total Accepted:    241.9K
 * Total Submissions: 509.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
	    stack<TreeNode *> s;
	    s.push(root);
	    vector<int> res;
	    while (!s.empty()) {
		    auto curr = s.top();
		    s.pop();
		    if (curr != nullptr) {
		    res.push_back(curr->val);
		    s.push(curr->right);
		    s.push(curr->left);
		    }
	    }
	    return res;
    }

    vector<int> preorderTraversal2(TreeNode* root) {
	    vector<int> res;
	    preorderTraversalRecursive(root, res);
	    return res;
    }

    void preorderTraversalRecursive(TreeNode *root, vector<int> &res) {
	    if (root != nullptr) {
		    res.push_back(root->val);
		    preorderTraversalRecursive(root->left, res);
		    preorderTraversalRecursive(root->right, res);
	    }
    }
};
