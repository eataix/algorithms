class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        int c = 0;
        int candidate = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (c == 0) {
                candidate = nums[i];
            }
            
            if (nums[i] == candidate) {
                c += 1;
            } else {
                c-= 1;
            }
        }
        
        return candidate;
    }
};
