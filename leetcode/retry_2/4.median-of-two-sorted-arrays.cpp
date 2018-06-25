#include<iostream>
#include<vector>
using namespace std;
/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (23.05%)
 * Total Accepted:    250.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
	vector<int> mergeUntil(const vector<int> &nums1, const vector<int> &nums2, int count) {
	    vector<int> tmp;
	    int i = 0; int j = 0;

	    while (i < nums1.size() && j < nums2.size()) {
		    if (nums1[i] < nums2[j]) {
			    tmp.push_back(nums1[i]);
			    i += 1;
		    } else {
			    tmp.push_back(nums2[j]);
			    j += 1;
		    }

		    if (tmp.size() == count) {
			    return tmp;
		    }
	    }

	    while (i< nums1.size()) {

			    tmp.push_back(nums1[i]);
		    if (tmp.size() == count) {
			    return tmp;
		    }
			    i += 1;
	    }
	    while (j < nums2.size()) {
			    tmp.push_back(nums2[j]);
		    if (tmp.size() == count) {
			    return tmp;
		    }
			    j += 1;
	    }
	    return tmp;
	}
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
	    int n = nums1.size();
	    int m = nums2.size();

	    int cnt1;
	    int cnt2;
	    if ((n + m) % 2 == 0) {
		    cnt1 = (n + m) / 2;
		    cnt2 = (n + m) / 2 + 1;
	    } else {
		    cnt1  = (n + m + 1) / 2;
		    cnt2  = (n + m + 1) / 2;
	    }
	    
	    auto res = mergeUntil(nums1, nums2, cnt2);
#ifdef DEBUG
	    for (int r : res) {
		    cout << r << " ";
	    }
	    cout << endl;
#endif

	    double v1 = static_cast<double>(res[cnt1 -1]);
	    double v2 = static_cast<double>(res[cnt2 -1]);
#ifdef DEBUG
	    cout << cnt1<< " " << cnt2 << endl;
	    cout << v1 << " " << v2 << endl;
#endif

	    return v1 + (v2 - v1) / 2;
    }
};


#ifdef DEBUG
int main() {
	Solution sol;
	sol.findMedianSortedArrays({1,3}, {2});
}
#endif
