/*
 * @Author: junhuizhou
 * @Date: 2021-06-10 15:34:44
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-10 15:53:49
 * @Description: header
 * @FilePath: \LeetCode\HashTable\349_intersection_1.cpp
 */

// 返回两数组的交集
// 出现多次的交集不再计数

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> resultSet;
        unordered_set<int> numsSet(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            if (numsSet.find(num) != numsSet.end())
                resultSet.insert(num);
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};