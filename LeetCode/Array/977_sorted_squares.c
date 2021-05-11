/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 15:10:37
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 15:27:27
 * @Description: header
 * @FilePath: \LeetCode\Array\977_sorted_squares.c
 */

// 非递减数组的平方再排序

// 双指针，左右指针
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int* result = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    
    int left = 0;
    int right = numsSize - 1;
    int pos = right;
    while (left <= right)
    {
        if (-nums[left] > nums[right])
        {
            result[pos] = nums[left] * nums[left];
            left++;
        }
        else
        {
            result[pos] = nums[right] * nums[right];
            right--;
        }
        pos--;
    }

    return result;
}