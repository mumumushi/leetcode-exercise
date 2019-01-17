/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * FIXME:Example 2在本地运行结果正确，在leetcode上结果不对
 * 战略性放弃先。。
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
        
        //参考官方的题解，思路是寻找一个合适的i,得到j,使得长度为m,n的nums1,nums2刚好被中位分开
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {    //确保 m <= n
            vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m+n+1)/2;
        while(iMin <= iMax) {
            int i = (iMin+iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j-1] > nums1[i])
                iMin = i + 1;   //i太小了
            else if (i > iMin && nums1[i-1] > nums2[j])
                iMax = i - 1;   //i太大
            else {              //i刚好
                int maxLeft = 0;
                if (i == 0)         maxLeft = nums2[j-1];
                else if (j == 0)    maxLeft = nums1[i-1];
                else                maxLeft = (nums1[i-1]>nums2[j-1]) ? nums1[i-1] : nums2[j-1];

                if ((m+n) % 2 == 1)  return maxLeft;

                int minRight = 0;
                if (i == m)         minRight = nums2[j];
                else if (j == n)    minRight = nums1[i];
                else                minRight = (nums1[i]<nums2[j]) ? nums1[i] : nums2[j];

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;


        /*自己的失败尝试
        if (nums1.empty() || nums2.empty()) {
            if (nums1.empty())  nums1.swap(nums2);      //把非空的vector换到nums1
 
            if (nums1.size()%2 == 0) {
                double ans = nums1[(nums1.size()-1)/2] + nums1[(nums1.size()-1)/2 +1];
                return ans / 2;
            } else 
                return nums1[(nums1.size()-1)/2];

        } else {
            int mid = (nums1.size()+nums2.size()-1) / 2 + 1;
            bool flag_even = ((nums1.size()+nums2.size()-1)%2 == 1) ? true : false; 
        
            int i = 0, j = 0;
            int l = 0;
            while(++l < mid) {
                if      (nums1[i] < nums2[j])     i++;
                else if (nums1[i] >= nums2[j])    j++;
            }
            if (flag_even) {
                double ans = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
                //FIXME:一个数组整体都比另一个小，会有越界
                ans = (ans+((nums1[i] < nums2[j]) ? nums1[i] : nums2[j])) / 2;
                return ans;
            } else {
                return (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
            }
        }*/
        
    }
};

int main(void) {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    double ans = Solution().findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
    return 0;
}