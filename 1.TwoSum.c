/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 

Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int temp = 0;
    int index1 = 0;
		int index2 = 0;
    int *res = NULL;
		int *temp_array = NULL;
		int key = 0;
		int i,j = 0;

		temp_array = (int*)malloc(sizeof(int)*numsSize);
    
    res = (int*)malloc(sizeof(int)*2);
    if(NULL == res || NULL == temp_array)
    {
        return NULL;
    }
    
		memcpy(temp_array,nums,numsSize*sizeof(int));
    if(NULL == nums || numsSize<=0)
    {
        return NULL;
    }
    
    //sort
    for(i=1;i<numsSize;i++)
    {
        key = nums[i];
        for(j=i-1;j>=0;j--)
        {
            if(nums[j]>key)
            {
                nums[j+1]=nums[j];
            }
            else
            {
                break;
            }
        }
        nums[j+1]=key;
    }
    
		int left = 0;
		int right = numsSize-1;
		int flag = 0;
    while(left<right)
		{
        if(nums[left]+nums[right]==target)
        {
						for(int k = 0;k<numsSize;k++)
						{
								if(temp_array[k]==nums[left] && 0==flag)
								{
									index1=k+1;
									flag=1;
									continue;
								}
								if(temp_array[k]==nums[right])
								{
									index2=k+1;
								}
						}
	            break;
	      }
				else if(nums[left]+nums[right]>target)
				{
					right--;
				}
				else
				{
					left++;
				}
    }
    
    if(left == right)
		{
			return NULL;
		}
		res[0]=(index1>index2?index2:index1);
    res[1]= (index1>index2?index1:index2);
    
    return res;
    
    
}