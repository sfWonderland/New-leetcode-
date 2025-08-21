////853. 车队
//
//typedef struct
//{
//    int pos;
//    double time;
//}cars;
//int cmp(const void* e1, const void* e2)
//{
//    int a = (*(cars*)e1).pos;
//    int b = (*(cars*)e2).pos;
//    return b - a;
//}
//int carFleet(int target, int* position, int positionSize, int* speed, int speedSize)
//{
//    int m = positionSize;
//    cars* group = (cars*)malloc(sizeof(cars) * m);
//    for (int i = 0; i < m; i++)
//    {
//        group[i].pos = position[i];
//        group[i].time = 1.0 * (target - position[i]) / speed[i];
//    }
//    qsort(group, m, sizeof(cars), cmp);
//    double* st = (double*)malloc(sizeof(double) * m);
//    int top = -1;
//    for (int i = 0; i < m; i++)
//    {
//        if (top >= 0 && group[i].time <= st[top])
//            continue;
//
//        st[++top] = group[i].time;
//    }
//    return top + 1;
//}
//
////221. 最大正方形
//
//int largestSize(int* heights, int n)
//{
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    int ans = 0;
//    st[++top] = -1;
//    for (int i = 0; i < n; i++)
//    {
//        int h = heights[i];
//        while (top > 0 && heights[st[top]] >= h)
//        {
//            int j = st[top--];
//            int left = st[top];
//            ans = fmax(ans, fmin(heights[j], i - left - 1));
//        }
//        st[++top] = i;
//    }
//    free(st);
//    return ans;
//}
//int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    int* heights = (int*)calloc(sizeof(int), n + 1);
//    int ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            heights[j] = matrix[i][j] - '0' ? heights[j] + 1 : 0;
//        }
//        ans = fmax(ans, largestSize(heights, n + 1));
//    }
//    free(heights);
//    return ans * ans;
//}
//
////962. 最大宽度坡
//
//int maxWidthRamp(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (top >= 0 && nums[i] >= nums[st[top]])
//            continue;
//
//        st[++top] = i;
//    }
//    int ans = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        while (top >= 0 && nums[st[top]] <= nums[i])
//        {
//            int pos = st[top--];
//            ans = fmax(ans, i - pos);
//        }
//    }
//    return ans;
//}
//
////1793. 好子数组的最大分数
//
//int maximumScore(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int* stack = (int*)malloc(sizeof(int) * n);
//    int* left = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        int h = nums[i];
//        while (top >= 0 && h < nums[stack[top]])
//        {
//            top--;
//        }
//        left[i] = top < 0 ? -1 : stack[top];
//        stack[++top] = i;
//    }
//    int* right = (int*)malloc(sizeof(int) * n);
//    top = -1;
//    for (int i = n - 1; i > -1; i--)
//    {
//        int h = nums[i];
//        while (top >= 0 && h <= nums[stack[top]])
//        {
//            top--;
//        }
//        right[i] = top < 0 ? n : stack[top];
//        stack[++top] = i;
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (left[i] < k && k < right[i])
//            ans = fmax(ans, nums[i] * (right[i] - left[i] - 1));
//    }
//    return ans;
//}
//
