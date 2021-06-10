/*
 * @Author: junhuizhou
 * @Date: 2021-06-10 15:35:00
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-10 16:15:58
 * @Description: header
 * @FilePath: \LeetCode\HashTable\350_intersection_2.cpp
 */

// 返回两数组的交集
// 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        
        unordered_map<int, int> mapCnt;
        for (int num : nums1)
        {
            mapCnt[num]++;
        }

        vector<int> result;
        for (int num : nums2)
        {
            if (mapCnt.count(num))
            {
                result.push_back(num);
                mapCnt[num]--;
                if (mapCnt[num] == 0)
                {
                    mapCnt.erase(num);
                }
            }
        }

        return result;
    }
};