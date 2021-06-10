/*
 * @Author: junhuizhou
 * @Date: 2021-06-10 14:16:33
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-06-10 14:19:07
 * @Description: header
 * @FilePath: \LeetCode\HashTable\383_ransom_note.c
 */

// 判断第一个字符串能否由第二个字符串里面的字符构成
// 不考虑顺序，比的是字母出现的次数

#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine)
{
    int record[26] = {0};
    int notelength = strlen(ransomNote);
    int maglength = strlen(magazine);

    for (int i = 0; i < notelength; ++i)
    {
        record[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < maglength; ++i)
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