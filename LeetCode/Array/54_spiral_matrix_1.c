/*
 * @Author: junhuizhou
 * @Date: 2021-05-13 17:07:29
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-29 11:33:38
 * @Description: header
 * @FilePath: \LeetCode\Array\54_spiral_matrix_1.c
 */

// 按顺时针螺旋顺序返回mxn数组的元素

#include "stddef.h"

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if (matrixSize == 0 || matrixColSize[0] == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int* result = malloc(sizeof(int)*rows*cols);
    *returnSize = 0;
    int minrowcol = rows < cols ? rows : cols;
    int loop = minrowcol >> 1;
    int offset = 1;
    int startx = 0;
    int starty = 0;

    while (loop--)
    {
        int i = startx;
        int j = starty;
        
        for (; j < starty + cols - offset; ++j) { result[(*returnSize)++] = matrix[i][j]; }
        for (; i < startx + rows - offset; ++i) { result[(*returnSize)++] = matrix[i][j]; }
        for (; j > starty; --j) { result[(*returnSize)++] = matrix[i][j]; }
        for (; i > startx; --i) { result[(*returnSize)++] = matrix[i][j]; }

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
                result[(*returnSize)++] = matrix[startx][j];
        }
        else
        {
            for (int i = startx; i <= startx + rows - offset; ++i)
                result[(*returnSize)++] = matrix[i][starty];
        }
    }

    return result;
}