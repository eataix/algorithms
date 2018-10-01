#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> heights(N);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minQ;
  priority_queue<pair<int, int>> maxQ;
  for (int i = 0; i < N; ++i) {
    cin >> heights[i];
    minQ.push({heights[i], i});
    maxQ.push({heights[i], i});
  }

  vector<pair<int, int>> moves;
  while (K-- > 0) {
    if (minQ.empty() || maxQ.empty()) {
    }
    auto minPair = minQ.top();
    minQ.pop();
    auto maxPair = maxQ.top();
    maxQ.pop();
    moves.push_back({maxPair.second, minPair.second});

    minQ.push({minPair.first - 1, minPair.second});
    maxQ.push({maxPair.first - 1, maxPair.second});
  }
}