#ifdef DEBUG
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode *parent;
};
#endif

class Solution {
public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    if (p == nullptr) {
      return nullptr;
    }
    if (p->right != nullptr) {
      return leftMostChild(p->right);
    } else {
      TreeNode *next = nullptr;
      while (root != nullptr) {
        if (p->val < root->val) {
          next = root;
          root = root->left;
        } else if (p->val > root->val) {
          root = root->right;
        } else {
          break;
        }
      }
      return next;
    }
  }

#ifdef DEBUG
  TreeNode *inorderSuccessor(TreeNode *p) {
    if (p == nullptr) {
      return nullptr;
    }
    if (p->right != nullptr) {
      return leftMostChild(p->right);
    } else {
      TreeNode *curr = p;
      TreeNode *parent = curr->parent;
      while (parent != nullptr && parent->left != curr) {
        curr = parent;
        parent = parent->parent;
      }
      return curr;
    }
  }
#endif

  TreeNode *leftMostChild(TreeNode *p) {
    TreeNode *curr = p;
    while (curr->left != nullptr) {
      curr = curr->left;
    }
    return curr;
  }
};
