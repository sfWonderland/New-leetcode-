////LCR 035. 最小时间差
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findMinDifference(char** timePoints, int timePointsSize)
//{
//    int n = timePointsSize;
//    int time[n];
//    for (int i = 0; i < n; i++)
//    {
//        int h = timePoints[i][0] * 10 + timePoints[i][1] - 528; // - 11 * '0' 
//        int min = timePoints[i][3] * 10 + timePoints[i][4] - 528; // - 11 * '0'
//        time[i] = h * 60 + min;
//    }
//    qsort(time, n, sizeof(int), cmp);
//    int ans = 1440 + time[0] - time[n - 1];
//    for (int i = 1; i < n; i++)
//    {
//        ans = fmin(ans, time[i] - time[i - 1]);
//    }
//    return ans;
//}
//
////LCR 037. 行星碰撞    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
//{
//    int n = asteroidsSize;
//    int* st = (int*)malloc(sizeof(int) * (n + 1));
//    int size = -1;
//    st[++size] = -1; // 哨兵
//    for (int i = 0; i < asteroidsSize; i++)
//    {
//        if (asteroids[i] > 0)
//        {
//            st[++size] = asteroids[i];
//            continue;
//        }
//        while (st[size] > 0 && st[size] + asteroids[i] < 0)
//        {
//            size--;
//        }
//        if (st[size] + asteroids[i] < 0)
//            st[++size] = asteroids[i];
//        else if (st[size] + asteroids[i] == 0)
//            size--;
//    }
//    *returnSize = size;
//    return st + 1;
//}
//
////LCR 039. 柱状图中最大的矩形
//
//int largestRectangleArea(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    int st[n + 1];
//    int top = -1;
//    st[++top] = -1;
//    int ans = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        int h = i < n ? heights[i] : -1;
//        while (top > 0 && h <= heights[st[top]])
//        {
//            int j = st[top--];
//            int left = st[top];
//            ans = fmax(ans, heights[j] * (i - left - 1));
//        }
//        st[++top] = i;
//    }
//    return ans;
//}
//
////LCR 040. 最大矩形
//
//int largestRectangleArea(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    int st[n + 1];
//    int top = -1;
//    st[++top] = -1;
//    int res = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        int h = i < n ? heights[i] : -1;
//        while (top > 0 && h <= heights[st[top]])
//        {
//            int j = st[top--];
//            int left = st[top];
//            res = fmax(res, heights[j] * (i - left - 1));
//        }
//        st[++top] = i;
//    }
//    return res;
//}
//int maximalRectangle(char** matrix, int matrixSize)
//{
//    if (matrixSize == 0)
//        return 0;
//    int m = matrixSize, n = strlen(matrix[0]);
//    int heights[n];
//    memset(heights, 0, sizeof(heights));
//    int ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            heights[j] = matrix[i][j] - '0' ? heights[j] + 1 : 0;
//        }
//        ans = fmax(ans, largestRectangleArea(heights, n));
//    }
//    return ans;
//}
//
