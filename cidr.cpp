#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int toIP(const string &host) {
  istringstream is{host};
  string s1;
  getline(is, s1, '.');
  string s2;
  getline(is, s2, '.');
  string s3;
  getline(is, s3, '.');
  string s4;
  getline(is, s4, '.');
  int res = (stoi(s1) << 24) + (stoi(s2) << 16) + (stoi(s3) << 8) + stoi(s4);
  return res;
}

string cidrToString(pair<int, int> cidr) {
  return to_string((cidr.first >> 24) & 255) + "." +
         to_string((cidr.first >> 16) & 255) + "." +
         to_string((cidr.first >> 8) & 255) + "." +
         to_string(cidr.first & 255) + "/" + to_string(cidr.second);
}

pair<int, int> parse(const string &s) {
  int pos = s.find("/");
  string host = s.substr(0, pos);
  string prefix = s.substr(pos + 1);
  cout << host << " " << prefix << endl;
  return {toIP(host), stoi(prefix)};
}

int bitsToCompare(int prefix) {
  unsigned int res = ((1 << (prefix - 1)) - 1) << (32 - prefix + 1);
  // unsigned int res =~((1 << (32 - prefix + 2)) - 1);
  std::bitset<32> y(res);
  return res;
}

vector<string> mergeCIDR(const vector<string> &cidrs) {
  map<int, vector<pair<int, int>>> m;

  for (auto const &cidr : cidrs) {
    auto parsed = parse(cidr);
    m[parsed.second].push_back(parsed);
  }

  vector<string> res;
  for (auto it = m.crbegin(); it != m.crend(); ++it) {
    auto kv = *it;
    auto prefix = kv.first;
    auto cidrsWithPrefix = kv.second;
    vector<bool> canMerge(cidrsWithPrefix.size(), false);

    sort(cidrsWithPrefix.begin(), cidrsWithPrefix.end());
    for (int i = 0; i < cidrsWithPrefix.size() - 1; ++i) {
      int j = i + 1;

      auto cidr1 = cidrsWithPrefix[i];
      auto cidr2 = cidrsWithPrefix[j];

      if ((cidr1.first & cidr2.first & bitsToCompare(prefix)) ==
          (cidr1.first & bitsToCompare(prefix))) {
        auto merged =
            make_pair(cidr1.first & bitsToCompare(prefix), prefix - 1);
        m[merged.second].push_back(merged);
        canMerge[i] = true;
        canMerge[i] = true;
      }
    }

    for (int i = 0; i < cidrsWithPrefix.size() - 1; ++i) {
      if (!canMerge[i]) {
        res.push_back(cidrToString(cidrsWithPrefix[i]));
      }
    }
  }
  return res;
}

int main() {
  auto res = mergeCIDR({"10.10.1.0/24", "10.10.2.0/24", "10.10.0.0/23"});
  for (auto const &r : res) {
    cout << r << endl;
  }
}
