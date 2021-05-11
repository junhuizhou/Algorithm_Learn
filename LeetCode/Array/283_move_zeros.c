/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 14:11:56
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 14:27:30
 * @Description: header
 * @FilePath: \LeetCode\Array\283_move_zeros.c
 */

// 将0移到数组末尾

// 双指针
void moveZeroes(int* nums, int numsSize)
{
    int slowindex = 0;
    for (int fastindex = 0; fastindex < numsSize; ++fastindex)
    {
        if (nums[fastindex] != 0)
        {
            nums[slowindex++] = nums[fastindex];
        }
    }
    int zerocnt = numsSize - slowindex;
    while (zerocnt--)
    {
        nums[slowindex++] = 0;
    }
}