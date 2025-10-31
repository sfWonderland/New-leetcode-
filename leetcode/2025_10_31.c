////1738. 找出第 K 大的异或坐标值
//
//void down(int* nums, int n, int i)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] < nums[j])
//            j++;
//        if (nums[j] >= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void up(int* nums, int n, int i)
//{
//    int x = nums[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    nums[i] = x;
//}
//int kthLargestValue(int** matrix, int matrixSize, int* matrixColSize, int k)
//{
//    int** sum = (int**)malloc(sizeof(int*) * (matrixSize + 1));
//    sum[0] = (int*)calloc(sizeof(int), matrixColSize[0] + 1);
//    int* heap = (int*)malloc(sizeof(int) * k);
//    int idx = 0;
//    for (int i = 0; i < matrixSize; i++)
//    {
//        sum[i + 1] = (int*)malloc(sizeof(int) * (matrixColSize[i] + 1));
//        sum[i + 1][0] = 0;
//        for (int j = 0; j < matrixColSize[i]; j++)
//        {
//            sum[i + 1][j + 1] = sum[i + 1][j] ^ sum[i][j + 1] ^ sum[i][j] ^ matrix[i][j];
//            if (idx < k)
//            {
//                heap[idx++] = sum[i + 1][j + 1];
//                up(heap, idx, idx - 1);
//            }
//            else if (heap[0] < sum[i + 1][j + 1])
//            {
//                heap[0] = sum[i + 1][j + 1];
//                down(heap, k, 0);
//            }
//        }
//    }
//    return heap[0];
//}
//
////3212. 统计 X 和 Y 频数相等的子矩阵数量
//
//int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize)
//{
//    int*** sum = (int***)malloc(sizeof(int**) * 2);
//    sum[0] = (int**)malloc(sizeof(int*) * (gridSize + 1));   //X 
//    sum[1] = (int**)malloc(sizeof(int*) * (gridSize + 1));   //Y
//    sum[0][0] = (int*)calloc(sizeof(int), gridColSize[0] + 1);
//    sum[1][0] = (int*)calloc(sizeof(int), gridColSize[0] + 1);
//    int ans = 0;
//    for (int i = 0; i < gridSize; i++)
//    {
//        sum[0][i + 1] = (int*)malloc(sizeof(int) * (gridColSize[0] + 1));
//        sum[1][i + 1] = (int*)malloc(sizeof(int) * (gridColSize[0] + 1));
//        sum[0][i + 1][0] = sum[1][i + 1][0] = 0;
//        for (int j = 0; j < gridColSize[i]; j++)
//        {
//            sum[0][i + 1][j + 1] = sum[0][i + 1][j] + sum[0][i][j + 1] - sum[0][i][j];
//            sum[1][i + 1][j + 1] = sum[1][i + 1][j] + sum[1][i][j + 1] - sum[1][i][j];
//            if (grid[i][j] != '.')
//            {
//                sum[grid[i][j] & 1][i + 1][j + 1]++;
//            }
//            if (sum[0][i + 1][j + 1] && sum[0][i + 1][j + 1] == sum[1][i + 1][j + 1])
//                ans++;
//        }
//    }
//    return ans;
//}
//
//int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize)
//{
//    int** cnt = (int**)malloc(sizeof(int*) * 2);
//    cnt[0] = (int*)calloc(sizeof(int), gridColSize[0]);
//    cnt[1] = (int*)calloc(sizeof(int), gridColSize[0]);
//    int ans = 0;
//    for (int i = 0; i < gridSize; i++)
//    {
//        int sum0 = 0, sum1 = 0;
//        for (int j = 0; j < gridColSize[i]; j++)
//        {
//            if (grid[i][j] != '.')
//            {
//                cnt[grid[i][j] & 1][j]++;
//            }
//            sum0 += cnt[0][j];
//            sum1 += cnt[1][j];
//            if (sum0 && sum0 == sum1)
//                ans++;
//        }
//    }
//    return ans;
//}
//
////1292. 元素和小于等于阈值的正方形的最大边长
//
//int maxSideLength(int** mat, int matSize, int* matColSize, int threshold)
//{
//    int** sum = (int**)malloc(sizeof(int*) * (matSize + 1));
//    sum[0] = (int*)calloc(sizeof(int), matColSize[0] + 1);
//    int ans = 0;
//    for (int i = 0; i < matSize; i++)
//    {
//        sum[i + 1] = (int*)malloc(sizeof(int) * (matColSize[i] + 1));
//        sum[i + 1][0] = 0;
//        for (int j = 0; j < matColSize[0]; j++)
//        {
//            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
//            int x2 = i, y2 = j, x1 = i - ans, y1 = j - ans;
//            while (x1 >= 0 && y1 >= 0 && sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1] - sum[x2 + 1][y1] + sum[x1][y1] <= threshold)
//            {
//                if (x2 - x1 + 1 > ans)
//                    ans = x2 - x1 + 1;
//
//                x1--; y1--;
//            }
//        }
//    }
//    return ans;
//}
//
////71. 简化路径
//
//char* simplifyPath(char* path)
//{
//    int n = strlen(path);
//    char** st = (char**)malloc(sizeof(char*) * n);
//    int top = 0, len = 0;
//    char* s = (char*)malloc(sizeof(char) * (n + 1));
//    s[0] = '\0';
//    for (int i = 0; i <= n; i++)
//    {
//        if (path[i] != '/' && path[i])
//            s[len++] = path[i];
//        else
//        {
//            s[len] = '\0';
//            int x = len;
//            len = 0;
//            if (strcmp(s, ".") == 0 || strcmp(s, "") == 0)
//                continue;
//            if (strcmp(s, "..") == 0)
//            {
//                if (top > 0)
//                    free(st[--top]);
//            }
//            else
//            {
//                st[top] = (char*)malloc(sizeof(char) * (x + 1));
//                strcpy(st[top], s);
//                top++;
//            }
//        }
//    }
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    ans[0] = '/';
//    ans[1] = '\0';
//    for (int i = 0; i < top; i++)
//    {
//        if (i > 0)
//            strcat(ans, "/");
//        strcat(ans, st[i]);
//    }
//    return ans;
//}
//
