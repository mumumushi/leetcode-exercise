/**
 * Given an array nums of n integers and an integer target, 
 * find three integers in nums such that the sum is closest 
 * to target. Return the sum of the three integers. You may 
 * assume that each input would have exactly one solution.
 * 
 * Example:
 *   Given array nums = [-1, 2, 1, -4], and target = 1.
 *   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 0;
        return closest;
    }
};

int main() {
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    cout << Solution().threeSumClosest(nums, target) << endl;
    return 0;
}