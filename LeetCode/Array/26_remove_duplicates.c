/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 13:48:34
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 14:09:49
 * @Description: header
 * @FilePath: \LeetCode\Array\26_remove_duplicates.c
 */

// 移除有序（例如升序）数组中的重复元素，返回新数组元素个数

// 双指针
int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    
    int slowindex = 0;
    for (int fastindex = 1; fastindex < numsSize; ++fastindex)
    {
        if (nums[fastindex] != nums[slowindex])
        {
            nums[++slowindex] = nums[fastindex];
        }
    }

    return slowindex + 1;
}