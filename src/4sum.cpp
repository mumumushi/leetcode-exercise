/**
 * Given an array nums of n integers and an integer target, 
 * are there elements a, b, c, and d in nums such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans = {};
        if (nums.size() < 4)    return ans;

        sort(nums.begin(), nums.end());
        ans.push_back(nums);

        return ans;
    }
};

int main() {
    int target = 0;
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ans = Solution().fourSum(nums, target);
    for (auto i = ans.begin(); i != ans.end(); i++) {
        for (auto j = (*i).begin(); j != (*i).end(); j++)
            cout << *j << " ";
        cout << endl;
    }
    return 0;
}