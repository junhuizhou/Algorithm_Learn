/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 13:49:06
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 14:42:39
 * @Description: header
 * @FilePath: \LeetCode\Array\704_binary_search.cpp
 */

#include <vector>
using std::vector;

// 升序整形数组，二分查找，返回位置

class Solution {
public:
    // 二分法第一种写法：target在区间[left, right]
    // while (left <= right)
    // if (nums[middle] > target) right = middle - 1;
    int Search1(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
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

        return  -1;
    }

    // 二分法第二种写法：target在区间[left, right)
    // int right = nums.size(); 
    // while (left < right)
    // if (nums[middle] > target) right = middle;
    int Search2(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target)
            {
                right = middle;
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

        return -1;
    }
};
