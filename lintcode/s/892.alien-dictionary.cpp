class Solution {
public:
  /**
   * @param words: a list of words
   * @return: a string which is correct order
   */
  string alienOrder(vector<string> &words) {
    unordered_set<char> nodes;
    unordered_map<char, unordered_set<char>> edges;
    unordered_map<char, int> indgree;

    for (auto const word : words) {
      nodes.insert(cbegin(word), cend(word));
    }

    for (char node : nodes) {
      edges[node];
      indgree[node] = 0;
    }

    for (int i = 0; i < words.size() - 1; ++i) {
      string str1 = words[i];
      string str2 = words[i + 1];
      bool flag = false;
      for (int j = 0; j < min(str1.size(), str2.size()); ++j) {
        if (str1[j] != str2[j]) {

          edges[str1[j]].insert(str2[j]);

          flag = true;
          break;
        }
      }

      if (!flag && str1.size() > str2.size()) {
        return "";
      }
    }

    priority_queue<char, vector<char>, greater<char>> q;

    for (char node : nodes) {
      for (char child : edges[node]) {
        indgree[child] += 1;
      }
    }

    for (char ch : nodes) {
      if (indgree[ch] == 0) {
        q.push(ch);
      }
    }
    string res;
    while (!q.empty()) {
      char ch = q.top();
      res += ch;
      q.pop();
      for (char child : edges[ch]) {
        if ((--indgree[child]) == 0) {
          q.push(child);
        }
      }
    }
    return res.size() == nodes.size() ? res : "";
  }
};
