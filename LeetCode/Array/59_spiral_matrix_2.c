/*
 * @Author: junhuizhou
 * @Date: 2021-05-13 15:45:19
 * @LastEditor: junhuizhou
 * @LastEditTime: 2021-05-13 17:02:47
 * @Description: header
 * @FilePath: \LeetCode\Array\59_spiral_matrix_2.c
 */

// nxn螺旋矩阵

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    int** result = malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        result[i] = malloc(sizeof(int) * n);
        memset(result[i], 0, sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int loop = n / 2;
    int middle = n / 2;
    int startx = 0;
    int starty = 0;
    int offset = 1;
    int number = 0;
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