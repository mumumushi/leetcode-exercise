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
        cout << nums1.size() << " " << nums2.size() << endl;
        //大概思路就是先判断中间的一位或者两位的下标应该在融合的数组的哪里
        //然后两个向量从头开始比较计数，记到上面找到的下标上
        int m = (nums1.size()+nums2.size()-1) / 2;
        if ((nums1.size()+nums2.size()-1)%2 == 1) {
            //还要去一个m+1
        }
        int i = 0, j = 0;
        int l = 0;
        while(l < m) {
            if      (nums1[i] < nums2[j])     i++;
            else if (nums1[i] >= nums2[j])    j++;
            l++;
        }
        return m;
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