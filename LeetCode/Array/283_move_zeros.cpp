/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 14:12:08
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 14:29:58
 * @Description: header
 * @FilePath: \LeetCode\Array\283_move_zeros.cpp
 */

// 将0移到数组末尾

#include <vector>
using std::vector;

class Solution {
public:
    // 双指针
    void moveZeroes(vector<int>& nums) 
    {
        int slowindex = 0;
        for (int fastindex = 0; fastindex < nums.size(); ++fastindex)
        {
            if (nums[fastindex] != 0)
            {
                nums[slowindex++] = nums[fastindex];
            }
        }
        int zerocnt = nums.size() - slowindex;
        while (zerocnt--)
        {
            nums[slowindex++] = 0;
        }
    }
};