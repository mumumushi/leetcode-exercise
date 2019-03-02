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
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)    return 0;
        int min = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++){
            int a = i + 1;
            int b = nums.size() - 1;
            while (a < b) {
                int sum = nums[i] + nums[a] + nums[b];
                if (abs(sum - target) < abs(min - target))
                    min = sum;
                else if (sum > target)
                    b--;
                else if (sum < target)
                    a++;
                else 
                    return target;
            }
        }
        return min;
        /*int closest = 0;
        if (nums.size() < 3)    return closest;
        sort(nums.begin(), nums.end());
        
        int min_diff = INT32_MAX;
        int a,b,c,cur_diff,pre_diff;
        for (auto i = nums.begin(); i != nums.end()-2; i++) {
            a = *i;
            if (i != nums.begin() && a == *(i-1))    continue;
            for (auto j = i+1; j != nums.end()-1; j++) {
                b = *j;
                if (j != i+1 && b == *(j-1))    continue;
                pre_diff = INT32_MAX;
                for(auto k = j+1; k != nums.end(); k++) {
                    c = *k;
                    cur_diff = abs(a+b+c-target);
                    if      (cur_diff > pre_diff)    break;
                    else if (cur_diff < min_diff) {
                        closest = a + b + c; 
                        min_diff = cur_diff;
                        pre_diff = cur_diff;
                    } else {
                        pre_diff = cur_diff;
                    }
                }
            }
        }
        return closest;*/
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