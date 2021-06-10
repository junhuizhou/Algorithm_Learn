/*
 * @Author: junhuizhou
 * @Date: 2021-06-10 14:23:58
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-10 14:52:29
 * @Description: header
 * @FilePath: \LeetCode\HashTable\49_group_anagrams.cpp
 */

// 字母异位词分组
// 所有输入均为小写字母，不考虑答案输出顺序

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::sort;

class Solution {
public:
    // 对字符串内部的字母进行排序来调整字符串，调整之后的作为哈希表的键
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mapAnagrams;
        for (string& str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mapAnagrams[key].emplace_back(str);
        }

        vector<vector<string>> result;
        for (auto it = mapAnagrams.begin(); it != mapAnagrams.end(); ++it)
        {
            result.emplace_back(it->second);
        }

        return result;
    }
};