/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 15:30:49
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 23:20:31
 * @Description: header
 * @FilePath: \LeetCode\Array\844_backspace_compare.cpp
 */

// 比较含退格backspace的字符串是否相等

// 不用双指针了，感觉很恶心，还是暴力点好，感觉效率差不多
// 先重建字符串，然后比较

#include <string>
using std::string;

class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        return BuildNewStr(s) == BuildNewStr(t);
    }

    string BuildNewStr(string str)
    {
        string result;
        for (char ch : str)
        {
            if (ch != '#')
            {
                result.push_back(ch);
            }
            else if (!result.empty())
            {
                result.pop_back();
            }
        }

        return result;
    }
};