/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 16:55:42
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 19:36:57
 * @Description: header
 * @FilePath: \LeetCode\Array\34_find_first_last.cpp
 */

#include <vector>
using std::vector;

// 升序数组，二分查找target的最初和最终位置（即数字有重复）

// 寻找最左位置，即nums[middle]==target 与 nums[middle] > target同样处理
// 寻找最右位置，即nums[middle]==target 与 nums[middle] < target同样处理

class Solution {
public:
    int BinarySearch(vector<int>& nums, int target, bool findleft)
    {
        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + ((right - left) >> 1);
            if (findleft)
            {
                if (nums[middle] >= target)
                {
                    ans = middle;
                    right = middle - 1;
                }
                else if (nums[middle] < target)
                {
                    left = middle + 1;
                }
            }
            else
            {
                if (nums[middle] > target)
                {
                    right = middle - 1;
                }
                else if (nums[middle] <= target)
                {
                    ans = middle;
                    left = middle + 1;
                }
            }
            
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int leftindex = BinarySearch(nums, target, true);
        int rightindex = BinarySearch(nums, target, false);
        if (leftindex <= rightindex 
            && rightindex < nums.size() 
            && nums[leftindex] == target 
            && nums[rightindex] == target)
        {
            return vector<int> {leftindex, rightindex};
        }
        return vector<int> {-1, -1};
    }
};
