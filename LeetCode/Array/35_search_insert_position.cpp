/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 14:47:59
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 16:47:13
 * @Description: header
 * @FilePath: \LeetCode\Array\35_search_insert_position.cpp
 */

#include <vector>
using std::vector;

// 升序数组，查找target位置，若无则返回target按顺序插入的位置

class Solution {
public:
    // target在[left, right]区间
    // 如果一直没找到，则终止状态为[right, left]即right = left - 1
    // 插入值在数组前面, left = 0;
    // 插入值在数组后面，left = n - 1;
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        
        return left;
    }
};