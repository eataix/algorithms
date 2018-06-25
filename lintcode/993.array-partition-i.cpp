class Solution {
public:
    /**
     * @param nums: an array
     * @return: the sum of min(ai, bi) for all i from 1 to n
     */
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for (int i = 0; i < nums.size() / 2; ++i) {
            sum += nums[2 * i];
        }
        
        return sum;
    }
};
