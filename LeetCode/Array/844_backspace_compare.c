/*
 * @Author: junhuizhou
 * @Date: 2021-05-11 15:30:29
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-11 23:13:49
 * @Description: header
 * @FilePath: \LeetCode\Array\844_backspace_compare.c
 */

// 比较含退格backspace的字符串是否相等

// 不用双指针了，感觉很恶心，还是暴力点好，感觉效率差不多
// 先重建字符串，然后比较

char* BuildNewStr(char* str)
{
    int len = strlen(str);
    int pos = 0;
    char* result = malloc(sizeof(char) * (len+1));
    for (int i = 0; i < len; ++i)
    {
        if (str[i] != '#')
        {
            result[pos++] = str[i];
        }
        else if (pos > 0)
        {
            pos--;
        }
    }
    result[pos] = '\0';
    return result;
}

bool backspaceCompare(char * s, char * t)
{
    return strcmp(BuildNewStr(s), BuildNewStr(t)) == 0;
}