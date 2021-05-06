/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 20:46:12
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 21:48:45
 * @Description: header
 * @FilePath: \LeetCode\Array\367_perfect_square.c
 */

// 判断是否为完美平方数，eg: 1,4,9,16,25...
// 不能使用sqrt

// 二分法

#define bool int
#define true 1
#define false 0

bool isPerfectSquare1(int num)
{
    if (num == 0 || num == 1)
        return true;

    int left = 2;
    int right = num / 2;
    while (left <= right)
    {
        long long middle = left + ((right - left) >> 1);
        long long guess = middle * middle;
        if (guess > num)
        {
            right = middle - 1;
        }
        else if (guess < num)
        {
            left = middle + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}

// 牛顿迭代法, f = sqrtx, F = (f*f - x) ->0, dF = 2f; fnext = f - F/dF = (f + x/f)/2;
bool isPerfectSquare2(int num)
{
    if (num == 0 || num == 1)
        return true;
    
    long f = num / 2;
    while (f*f > num)
    {
        f = (f + num/f) / 2;
    }

    return  num == f*f;
}
