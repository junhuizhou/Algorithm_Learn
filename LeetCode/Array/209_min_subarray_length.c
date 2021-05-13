/*
 * @Author: junhuizhou
 * @Date: 2021-05-13 13:32:35
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-13 14:00:55
 * @Description: header
 * @FilePath: \LeetCode\Array\209_min_subarray_length.c
 */

// 寻找元素和大于等于target的最短子数组，返回其长度

#include "limits.h"

// 滑动窗口
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int result = INT_MAX;
    int sum = 0;
    int sublength = 0;
    int left = 0;
    for (int right = 0; right < numsSize; ++right)
    {
        sum += nums[right];
        while (sum >= target)
        {
            sublength = right - left + 1;
            result = result < sublength ? result : sublength;
            sum -= nums[left++];
        }
    }

    return result==INT_MAX ? 0 : result;
}