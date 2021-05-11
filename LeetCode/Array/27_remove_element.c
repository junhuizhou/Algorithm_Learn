/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 13:34:31
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 13:43:31
 * @Description: header
 * @FilePath: \LeetCode\Array\27_remove_element.c
 */

// 移除数组中值为val的数，返回新数组元素个数

// 双指针法
int removeElement(int* nums, int numsSize, int val)
{
    int slowindex = 0;
    for (int fastindex = 0; fastindex < numsSize; ++fastindex)
    {
        if (nums[fastindex] != val)
        {
            nums[slowindex++] = nums[fastindex];
        }
    }

    return slowindex;
}