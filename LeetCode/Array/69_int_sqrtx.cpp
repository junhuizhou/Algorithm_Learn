/*
 * @Author: junhuizhou
 * @Date: 2021-05-06 19:40:09
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-06 21:28:57
 * @Description: header
 * @FilePath: \LeetCode\Array\69_int_sqrtx.cpp
 */

// 返回平方根的整数部分

#include <math.h>
class Solution {
public:
    // 二分法
    int mySqrt1(int x)
    {
        int ans = 0;
        int left = 0;
        int right = x;
        while (left <= right)
        {
            int middle = left + ((right - left) >> 1);
            if ((long long)middle*middle <= x)
            {
                ans = middle;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        return ans;
    }

    // 牛顿迭代法, f = sqrtx, F = (f*f - x) ->0, dF = 2f; fnext = f - F/dF = (f + x/f)/2;
    int mySqrt2(int x)
    {
        if (x == 0)
            return 0;
        double f = x;
        while (true)
        {
            double fnext = 0.5 * (f + x/f);
            if (fabs(fnext - f) < 1e-6)
            {
                break;
            }
            f = fnext;
        }

        return (int)f;
    }
};
