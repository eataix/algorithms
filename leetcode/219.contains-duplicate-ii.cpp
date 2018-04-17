#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (32.86%)
 * Total Accepted:    141.9K
 * Total Submissions: 431.8K
 * Testcase Example:  '[]\n0'
 *
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 *
 */
class Solution
{
  public:
    bool containsNearbyDuplicate(const vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
        {
            return false;
        }

        int i = 0; // index of the earliest element in the set
        set<int> dictionary;
        dictionary.insert(nums[0]);
        for (int j = 1; j < nums.size(); ++j)
        {
            if (j - i > k)
            {
                dictionary.erase(nums[i++]);
            }

            if (dictionary.find(nums[j]) != dictionary.cend())
            {
                return true;
            }
            else
            {
                dictionary.insert(nums[j]);
            }
        }
        return false;
    }
};

#ifdef DEBUG
int main()
{
    Solution sol;
    vector<int> v{1, 2, 3, 4, 5, 1, 2};
    cout << sol.containsNearbyDuplicate(v, 1) << endl;
    cout << sol.containsNearbyDuplicate(v, 2) << endl;
    cout << sol.containsNearbyDuplicate(v, 3) << endl;
    cout << sol.containsNearbyDuplicate(v, 4) << endl;
    cout << sol.containsNearbyDuplicate(v, 5) << endl;
}
#endif