////1504. 统计全 1 子矩形
//
//int numSubmat(int** mat, int matSize, int* matColSize)
//{
//    int m = matSize, n = matColSize[0];
//    int ans = 0;
//    for (int top = 0; top < m; top++) //枚举上边界
//    {
//        int* arr = (int*)calloc(sizeof(int), n);
//        for (int bottom = top; bottom < m; bottom++) //枚举下边界
//        {
//            int h = bottom - top + 1; //高
//            // 2348. 全 h 子数组的数目
//            int last = -1;
//            for (int j = 0; j < n; j++)
//            {
//                arr[j] += mat[bottom][j];
//                if (arr[j] != h)
//                    last = j; // 记录上一个非 h 元素的位置
//                else
//                    ans += j - last;
//            }
//        }
//    }
//    return ans;
//}
//
//int numSubmat(int** mat, int matSize, int* matColSize)
//{
//    int m = matSize, n = matColSize[0];
//    int* height = (int*)calloc(sizeof(int), n);
//    int ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            height[j] = mat[i][j] ? height[j] + 1 : 0;
//        }
//        int* right = (int*)malloc(sizeof(int) * (n + 1));
//        int* fs = (int*)malloc(sizeof(int) * (n + 1));
//        int* hs = (int*)malloc(sizeof(int) * (n + 1));
//        int top = -1;
//        right[++top] = -1; fs[top] = 0; hs[top] = -1;
//        for (int j = 0; j < n; j++)
//        {
//            int h = height[j];
//            while (hs[top] >= h)
//                top--;
//
//            int left = right[top];
//            int f = fs[top];
//            f += (j - left) * h;
//            ans += f;
//            right[++top] = j; fs[top] = f, hs[top] = h;
//        }
//    }
//    return ans;
//}
//
////42. 接雨水
//
//int trap(int* height, int heightSize)
//{
//    int n = heightSize;
//    int* stack = (int*)malloc(sizeof(int) * n);
//    int top = -1, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int x = height[i];
//        while (top >= 0 && x >= height[stack[top]])
//        {
//            int y = height[stack[top]];
//            top--;
//            if (top < 0)
//                break;
//            int left = stack[top];
//            ans += (fmin(height[left], x) - y) * (i - left - 1);
//        }
//        stack[++top] = i;
//    }
//    return ans;
//}
//
////84. 柱状图中最大的矩形
//
//int largestRectangleArea(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    int* stack = (int*)malloc(sizeof(int) * n);
//    int* left = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        int h = heights[i];
//        while (top >= 0 && h < heights[stack[top]])
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
//        int h = heights[i];
//        while (top >= 0 && h <= heights[stack[top]])
//        {
//            top--;
//        }
//        right[i] = top < 0 ? n : stack[top];
//        stack[++top] = i;
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans = fmax(ans, heights[i] * (right[i] - left[i] - 1));
//    }
//    return ans;
//}
//
//int largestRectangleArea(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    int* stack = (int*)malloc(sizeof(int) * n);
//    int* left = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        int h = heights[i];
//        while (top >= 0 && h < heights[stack[top]])
//        {
//            top--;
//        }
//        left[i] = top < 0 ? -1 : stack[top];
//        stack[++top] = i;
//    }
//    int* right = (int*)malloc(sizeof(int) * n);
//    top = -1;
//    int ans = 0;
//    for (int i = n - 1; i > -1; i--)
//    {
//        int h = heights[i];
//        while (top >= 0 && h <= heights[stack[top]])
//        {
//            top--;
//        }
//        right[i] = top < 0 ? n : stack[top];
//        stack[++top] = i;
//
//        ans = fmax(ans, heights[i] * (right[i] - left[i] - 1));
//    }
//    return ans;
//}
//
//int largestRectangleArea(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    int* stack = (int*)malloc(sizeof(int) * n);
//    int* left = (int*)malloc(sizeof(int) * n);
//    int* right = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        int h = heights[i];
//        while (top >= 0 && h < heights[stack[top]])
//        {
//            right[stack[top--]] = i;
//        }
//        left[i] = top < 0 ? -1 : stack[top];
//        stack[++top] = i;
//    }
//    for (int i = 0; i <= top; i++)
//        right[stack[i]] = n;
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans = fmax(ans, heights[i] * (right[i] - left[i] - 1));
//    }
//    return ans;
//}
//
//int largestRectangleArea(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    int* stack = (int*)malloc(sizeof(int) * (n + 1));
//    int top = -1, ans = 0;
//    stack[++top] = -1;
//    for (int right = 0; right <= n; right++)
//    {
//        int h = right < n ? heights[right] : -1;
//        while (top > 0 && h <= heights[stack[top]])
//        {
//            int i = stack[top--];
//            int left = stack[top];
//            ans = fmax(ans, heights[i] * (right - left - 1));
//        }
//        stack[++top] = right;
//    }
//    return ans;
//}
//
////85. 最大矩形
//
//int largestRectangleArea(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    int* stack = (int*)malloc(sizeof(int) * (n + 1));
//    int top = -1, ans = 0;
//    stack[++top] = -1;
//    for (int right = 0; right <= n; right++)
//    {
//        int h = right < n ? heights[right] : -1;
//        while (top > 0 && h <= heights[stack[top]])
//        {
//            int i = stack[top--];
//            int left = stack[top];
//            ans = fmax(ans, heights[i] * (right - left - 1));
//        }
//        stack[++top] = right;
//    }
//    return ans;
//}
//int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    int* arr = (int*)calloc(n, sizeof(int));
//    int ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            arr[j] = matrix[i][j] - '0' ? arr[j] + 1 : 0;
//        }
//        ans = fmax(ans, largestRectangleArea(arr, n));
//    }
//    return ans;
//}
//
