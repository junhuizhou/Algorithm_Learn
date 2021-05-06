/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 16:55:58
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 19:36:39
 * @Description: header
 * @FilePath: \LeetCode\Array\34_find_first_last.c
 */

// 升序数组，二分查找target的最初和最终位置（即数字有重复）

// 寻找最左位置，即nums[middle]==target 与 nums[middle] > target同样处理
// 寻找最右位置，即nums[middle]==target 与 nums[middle] < target同样处理

int BinarySearch(int* nums, int numsSize, int target, int findleft)
{
    int ans = 0;
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int middle = left + ((right - left) >> 1);
        if (findleft)
        {
            if (nums[middle] >= target)
            {
                ans = middle;
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
        }
        else
        {
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] <= target)
            {
                ans = middle;
                left = middle + 1;
            }
        }
    }

    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* result = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int leftindex = BinarySearch(nums, numsSize, target, 1);
    int rightindex = BinarySearch(nums, numsSize, target, 0);
    if (leftindex <= rightindex 
        && rightindex < numsSize
        && nums[leftindex] == target
        && nums[rightindex] == target)
    {
        result[0] = leftindex;
        result[1] = rightindex;
        return result;
    }
    result[0] = result[1] = -1;
    return result;
}
