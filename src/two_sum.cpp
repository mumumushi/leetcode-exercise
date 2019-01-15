/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 *  Given nums = [2, 7, 11, 15], target = 9,
 *  Because nums[0] + nums[1] = 2 + 7 = 9,
 *  return [0, 1].
*/
#include<stdio.h>
#include<stdlib.h>
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* sum = (int*)malloc(2 * sizeof(int));
	for (int i = 0; i < numsSize; i++)
		for(int j = i+1; j < numsSize; j++)
			if (*(nums + j) == target - *(nums + i))
			{
				sum[0] = i;
				sum[1] = j;
                return sum;
			}
	return sum;
}

int main(void)
{
    int num[] = {2, 7, 11, 15};
    int* ans = 0;
    ans = twoSum(num, 4, 18);
    printf("%d %d", *ans, *(ans+1));
    return 0;
}
