#include <sstream>
using namespace std;
/*
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (35.40%)
 * Total Accepted:    107.2K
 * Total Submissions: 302.4K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Example: 
 *
 *
 * You may serialize the following tree:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 *
 * as "[1,2,3,null,null,4,5]"
 *
 *
 * Clarification: Just the same as how LeetCode OJ serializes a binary tree.
 * You do not necessarily need to follow this format, so please be creative and
 * come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your
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
  void serialize(Node *root, ostringstream &out) {
    if (root == nullptr) {
      out << "# ";
      return;
    }

    out << root->val << " ";
    out << root->children.size() << " ";

    for (auto const &c : root->children) {
      serialize(c, out);
    }
  }

public:
  // Encodes a tree to a single string.
  string serialize(Node *root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  Node *deserialize(istringstream &in) {
    string str;
    in >> str;
    if (str == "#") {
      return nullptr;
    }

    int val = stoi(str);
    int numC;
    in >> numC;
    auto newNode = new Node();
    newNode->val = val;
    for (int i = 0; i < numC; ++i) {
      newNode->children.push_back(deserialize(in));
    }

    return newNode;
  }

  // Decodes your encoded data to tree.
  Node *deserialize(string data) {
    istringstream in{data};
    return deserialize(in);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
