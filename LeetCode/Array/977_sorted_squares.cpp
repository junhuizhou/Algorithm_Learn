/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 15:10:24
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 15:23:29
 * @Description: header
 * @FilePath: \LeetCode\Array\977_sorted_squares.cpp
 */

// 非递减数组的平方再排序

#include <vector>
using std::vector;

class Solution {
public:
    // 双指针，左右指针
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
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
};