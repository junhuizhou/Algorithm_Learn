/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 13:34:15
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 13:40:41
 * @Description: header
 * @FilePath: \LeetCode\Array\27_remove_element.cpp
 */

// 移除数组中值为val的数，返回新数组元素个数

#include <vector>
using std::vector;

class Solution {
public:
    // 双指针法
    int removeElement(vector<int>& nums, int val) 
    {
        int slowindex = 0;
        for (int fastindex = 0; fastindex < nums.size(); ++fastindex)
        {
            if (nums[fastindex] != val)
            {
                nums[slowindex++] = nums[fastindex];
            }
        }

        return slowindex;
    }
};