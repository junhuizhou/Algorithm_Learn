/*
 * @Author: junhuizhou
 * @Date: 2021-06-10 13:37:21
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-10 13:48:33
 * @Description: header
 * @FilePath: \LeetCode\HashTable\242_valid_anagram.cpp
 */

// 判断两字符串是否为字母相同异位词

#include <string>

using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int record[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i)
        {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (record[i] != 0)
                return false;
        }

        return true;
    }
};