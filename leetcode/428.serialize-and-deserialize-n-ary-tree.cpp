#include <sstream>
#include <vector>
using namespace std;
/*
 * [765] Serialize and Deserialize N-ary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/description/
 *
 * algorithms
 * Hard (29.19%)
 * Total Accepted:    343
 * Total Submissions: 1.2K
 * Testcase Example:
 * '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize an N-ary tree. An N-ary
 * tree is a rooted tree in which each node has no more than N children. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that an N-ary tree can be serialized to a
 * string and this string can be deserialized to the original tree structure.
 *
 * For example, you may serialize the following 3-ary tree
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so
 * please be creative and come up with different approaches yourself.
 *
 *
 *
 * Note:
 *
 *
 * N is in the range of  [1, 1000]
 * Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 *
 *
 *
 */
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#ifdef DEBUG
class Node {
public:
  int val;
  vector<Node *> children;
  Node() {}
  Node(int _val, vector<Node *> _children);
};

#endif
class Codec {
  void preorder(Node *node, string &s) {
    if (node == nullptr) {
      return;
    }

    s += " " + to_string(node->val) + " " + to_string(node->children.size());
    for (auto child : node->children) {
      preorder(child, s);
    }
  }

  Node *decode(stringstream &ss) {
    auto root = new Node();
    int numChildren;
    ss >> root->val >> numChildren;

    for (int i = 0; i < numChildren; ++i) {
      root->children.push_back(decode(ss));
    }

    return root;
  }

public:
  // Encodes a tree to a single string.
  string serialize(Node *root) {
    string s;
    preorder(root, s);
    return s;
  }

  // Decodes your encoded data to tree.
  Node *deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    stringstream ss(data);
    return decode(ss);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
