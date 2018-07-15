#include<unordered_map>
using namespace std;
/*
 * [170] Two Sum III - Data structure design
 *
 * https://leetcode.com/problems/two-sum-iii-data-structure-design/description/
 *
 * algorithms
 * Easy (26.93%)
 * Total Accepted:    39.7K
 * Total Submissions: 147.3K
 * Testcase Example:  '["TwoSum","add","add","add","find","find"]\n[[],[1],[3],[5],[4],[7]]'
 *
 * Design and implement a TwoSum class. It should support the following
 * operations: add and find.
 * 
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the
 * value.
 * 
 * Example 1:
 * 
 * 
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 * 
 * 
 * Example 2:
 * 
 * 
 * add(3); add(1); add(2);
 * find(3) -> true
 * find(6) -> false
 * 
 */
class TwoSum {
  unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
      m[number] += 1;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
      for (auto a : m) {
        int t = value - a.first;
        if ((t != a.first && m.count(t)) || (t == a.first && a.second > 1)) {
          return true;
        }
      }
      return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
