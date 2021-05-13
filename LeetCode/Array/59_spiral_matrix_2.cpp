/*
 * @Author: junhuizhou
 * @Date: 2021-05-13 15:45:05
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-13 16:40:26
 * @Description: header
 * @FilePath: \LeetCode\Array\59_spiral_matrix_2.cpp
 */

// nxn螺旋矩阵

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int loop = n / 2;
        int middle = n / 2;
        int number = 0;
        int offset = 1;
        int startx = 0;
        int starty = 0;
        while (loop--)
        {
            int i = startx;
            int j = starty;
            
            for (; j < starty + n - offset; ++j) {result[i][j] = ++number;}
            for (; i < startx + n - offset; ++i) {result[i][j] = ++number;}
            for (; j > starty; --j) {result[i][j] = ++number;}
            for (; i > startx; --i) {result[i][j] = ++number;}
            
            startx++;
            starty++;
            offset += 2;
        }

        if (n&1)
        {
            result[middle][middle] = ++number;
        }

        return result;
    }
};