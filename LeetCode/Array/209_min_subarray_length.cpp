/*
 * @Author: junhuizhou
 * @Date: 2021-05-13 13:32:35
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-13 13:52:57
 * @Description: header
 * @FilePath: \LeetCode\Array\209_min_subarray_length.cpp
 */

// 寻找元素和大于等于target的最短子数组，返回其长度

#include <vector>
using std::vector;

class Solution {
public:
    // 滑动窗口
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int result = INT32_MAX;
        int sum = 0;
        int left = 0;
        int sublength = 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                sublength = right - left + 1;
                result = result < sublength ? result : sublength;
                sum -= nums[left++];
            }
        }

        return result==INT32_MAX ? 0 : result;
    }
};