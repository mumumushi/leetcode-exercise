/**
 * Given n non-negative integers a1, a2, ..., an , where each represents 
 * a point at coordinate (i, ai). n vertical lines are drawn such that 
 * the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
 * which together with x-axis forms a container, such that the container 
 * contains the most water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
 * In this case, the max area of water (blue section) the container can 
 * contain is 49.
 * 
 * Example:
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //暴力N^2的解法
        /*int maxArea = 0;
        int area = 0;
        for (int i=0; i < height.size()-1; i++)
            for (int j=i+1; j <height.size(); j++) {
                area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                if (area > maxArea)
                    maxArea = area;
            }
        return maxArea;*/
        //解题思路，在（j-i）变小的情况下，需要确保low变高了
        int maxArea = 0;    
        int area = 0;
        int i = 0;
        int j = height.size() - 1;
        int low = 0;
        while(i < j) {
            if (height[i]<height[j]) {
                low = height[i];
                area = (j-i) * low;
                if (area > maxArea)
                    maxArea = area;
                while (i<j && height[i]<=low)
                    i++;
            }    
            else {
                low = height[j];
                area = (j-i) * low;
                if (area > maxArea)
                    maxArea = area;
                while (i<j && height[j]<=low)
                    j--;
            }
        }
        return maxArea;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution().maxArea(height) << endl;
    return 0;
}