/*
 * @Author: junhuizhou
 * @Date: 2021-05-13 14:03:12
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-13 15:09:14
 * @Description: header
 * @FilePath: \LeetCode\Array\904_fruit_baskets.cpp
 */

#include <vector>
using std::vector;

class Solution {
public:
    // 滑动窗口
    // TODO: fruit种类较多时，需要更合理的设计，有些题解用unordered_map
    int totalFruit(vector<int>& tree) 
    {
        int result = 0;
        int sum = 0;
        int left = 0;
        int fruit1 = tree[0];
        int fruit2 = tree[0];
        for (int right = 0; right < tree.size(); ++right)
        {
            if (tree[right] == fruit1 || tree[right] == fruit2) 
            {
                sum++;
            }
            else if (fruit1 == fruit2)
            {
                fruit2 = tree[right];
                sum++;
            }
            else
            {
                left = right - 1;
                while (left > 0 && tree[left]==tree[left-1])
                {
                    left--;
                }
                sum = right - left + 1;
                if (fruit1 == tree[left]) fruit2 = tree[right];
                else fruit1 = tree[right];
            }
            result = result > sum ? result : sum;
        }

        return result;
    }
};