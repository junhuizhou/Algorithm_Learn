/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 13:32:45
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 14:42:27
 * @Description: header
 * @FilePath: \LeetCode\Array\704_binary_search.c
 */

// 升序整形数组，二分查找，返回位置

// 二分查找法一：target在[left, right]
int Search1(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int middle = left + ((right - left) >> 1);
        if (nums[middle] > target)
        {
            right = middle - 1;
        }
        else if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

// 二分查找法二：target在[left, right)
int Search2(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize;
    while (left < right)
    {
        int middle = left + ((right - left) >> 1);
        if (nums[middle] > target)
        {
            right = middle;
        }
        else if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}
