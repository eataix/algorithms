#include <sstream>
using namespace std;
/*
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (43.02%)
 * Total Accepted:    28.6K
 * Total Submissions: 66.6K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree
 * structure.
 *
 *
 * The encoded string should be as compact as possible.
 *
 *
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
  void serialize(TreeNode *root, ostringstream &os) {
    if (root == nullptr) {
      os << "# ";
    } else {
      os << root->val << " ";
      serialize(root->left, os);
      serialize(root->right, os);
    }
  }

  TreeNode *deserialize(istringstream &is) {
    string val;
    is >> val;
    if (val == "#") {
      return nullptr;
    }

    auto node = new TreeNode(stoi(val));
    node->left = deserialize(is);
    node->right = deserialize(is);
    return node;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    ostringstream os;
    serialize(root, os);
    return os.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    istringstream is(data);
    return deserialize(is);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
