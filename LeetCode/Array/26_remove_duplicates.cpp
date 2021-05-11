/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 13:48:21
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 14:02:41
 * @Description: header
 * @FilePath: \LeetCode\Array\26_remove_duplicates.cpp
 */

// 移除有序（例如升序）数组中的重复元素，返回新数组元素个数

#include <vector>
using std::vector;

class Solution {
public:
    // 双指针
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;

        int slowindex = 0;
        for (int fastindex = 1; fastindex < nums.size(); ++fastindex)
        {
            if (nums[slowindex] != nums[fastindex])
            {
                nums[++slowindex] = nums[fastindex];
            }
        }

        return slowindex + 1;
    }
};