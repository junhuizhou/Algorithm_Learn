/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 14:48:18
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 16:50:25
 * @Description: header
 * @FilePath: \LeetCode\Array\35_search_insert_position.c
 */

// 升序数组，查找target位置，若无则返回target按顺序插入的位置

// target在[left, right]区间
// 如果一直没找到，则终止状态为[right, left]即right = left - 1
// 插入值在数组前面, left = 0;
// 插入值在数组后面，left = n - 1;
int searchInsert(int* nums, int numsSize, int target)
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

    return left;
}