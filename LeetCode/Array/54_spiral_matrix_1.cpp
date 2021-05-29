/*
 * @Author: junhuizhou
 * @Date: 2021-05-13 17:07:42
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-29 11:23:11
 * @Description: header
 * @FilePath: \LeetCode\Array\54_spiral_matrix_1.cpp
 */

// 按顺时针螺旋顺序返回mxn数组的元素

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralresult(vector<vector<int>>& matrix) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) 
        {
            return {};
        }
        
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int minrowcol = rows < cols ? rows : cols;
        int loop = minrowcol >> 1;
        int offset = 1;
        int startx = 0;
        int starty = 0;

        while (loop--)
        {
            int i = startx;
            int j = starty;
            
            for (; j < starty + cols - offset; ++j) { result.push_back(matrix[i][j]); }
            for (; i < startx + rows - offset; ++i) { result.push_back(matrix[i][j]); }
            for (; j > starty; --j) { result.push_back(matrix[i][j]); }
            for (; i > startx; --i) { result.push_back(matrix[i][j]); }

            startx++;
            starty++;
            offset += 2;
        }

        // 行列中小的奇数时，中间有剩
        if (minrowcol & 1)
        {
            if (cols >= rows)
            {
                for (int j = starty; j <= starty + cols - offset; ++j)
                    result.push_back(matrix[startx][j]);
            }
            else
            {
                for (int i = startx; i <= startx + rows - offset; ++i)
                    result.push_back(matrix[i][starty]);
            }
        }

        return result;
    }
};