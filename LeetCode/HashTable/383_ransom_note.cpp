/*
 * @Author: junhuizhou
 * @Date: 2021-06-10 14:03:26
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-10 14:15:31
 * @Description: header
 * @FilePath: \LeetCode\HashTable\383_ransom_note.cpp
 */

// 判断第一个字符串能否由第二个字符串里面的字符构成
// 不考虑顺序，比的是字母出现的次数

#include <string>

using std::string;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int record[26] = {0};
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            record[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.size(); ++i)
        {
            record[magazine[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (record[i] > 0)
                return false;
        }

        return true;
    }
};