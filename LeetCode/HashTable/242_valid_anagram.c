/*
 * @Author: junhuizhou
 * @Date: 2021-06-10 13:51:08
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-10 13:56:55
 * @Description: header
 * @FilePath: \LeetCode\HashTable\242_valid_anagram.c
 */

// 判断两字符串是否为字母相同异位词

#include <stdbool.h>

bool isAnagram(char * s, char * t)
{
    int record[26] = {0};
    int slen = strlen(s);
    int tlen = strlen(t);
    
    if (slen != tlen) return false;
    for (int i = 0; i < slen; ++i)
    {
        record[s[i] - 'a']++;
    }
    for (int i = 0; i < tlen; ++i)
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