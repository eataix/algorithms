#include<string>
using namespace std;
/*
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (40.20%)
 * Total Accepted:    46.2K
 * Total Submissions: 115K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
	    string s1;
	    string s2;

	    toString(s, s1);
	    toString(t, s2);

	    return s1.find(s2) != string::npos;
    }

    void toString(TreeNode* node, string &str) {
	    if (node == nullptr) {
		    str += "X";
	    } else {
		    str += node->val;
		    str += " ";
	    toString(node->left, str);
	    toString(node->right, str);
	    }
    }

    bool isSubtree2(TreeNode* s, TreeNode* t) {
	    if (t == nullptr) {
		    return true;
	    }
	    if (s ==nullptr) {
		    return false;
	    }

	    if (s->val == t->val && matchTree(s, t)) {
		    return true;
	    }

	    return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool matchTree(TreeNode *s, TreeNode*t) {
	    if (s == nullptr && t == nullptr) {
		    return true;
	    } else if (s == nullptr || t == nullptr) {
		    return false;
	    } else if (s->val != t->val ) {
		    return false;
	    } else {
		    return matchTree(s->left, t->left) && matchTree(s->right, t->right);
	    }
    }
};
