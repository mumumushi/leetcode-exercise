/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * 未完
 * Example 1:
 *  nums1 = [1, 3]
 *  nums2 = [2]
 *  The median is 2.0
 * 
 * Example 2:
 *  nums1 = [1, 2]
 *  nums2 = [3, 4]
 *  The median is (2 + 3)/2 = 2.5
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (nums1.size()+nums2.size()-1) / 2 + 1;
        bool flag_even = false; 
        if ((nums1.size()+nums2.size()-1)%2 == 1)   flag_even = true;
        
        int i = 0, j = 0;
        int l = 0;
        while(++l < m) {
            if      (nums1[i] < nums2[j])     i++;
            else if (nums1[i] >= nums2[j])    j++;
        }
        if (flag_even) {
            //想办法提取两个值出来
            double ans = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
            return (ans+((nums1[i] < nums2[j]) ? nums1[i] : nums2[j])) / 2;
        } else {
            return (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
        }
    }
};

int main(void) {
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {2, 4};
    Solution s;
    double ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
    return 0;
}