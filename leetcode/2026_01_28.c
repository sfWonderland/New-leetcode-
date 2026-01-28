////3015. 按距离统计房屋对数目 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
//int* countOfPairs(int n, int x, int y, int* returnSize)
//{
//    int grid[n][3];
//    int len[n];
//    memset(len, 0, sizeof(len));
//    for (int i = 0; i < n - 1; i++)
//    {
//        grid[i][len[i]++] = i + 1;
//        grid[i + 1][len[i + 1]++] = i;
//    }
//    if (x != y)
//    {
//        grid[x - 1][len[x - 1]++] = y - 1;
//        grid[y - 1][len[y - 1]++] = x - 1;
//    }
//
//    int* ans = (int*)calloc(sizeof(int), n);
//
//    void bfs(int first)
//    {
//        int queue[n];
//        bool vis[n];
//        memset(vis, 0, sizeof(vis));
//        int front = 0, rear = 0, k = 0;
//        queue[rear++] = first;
//        vis[first] = true;
//
//        while (front < rear)
//        {
//            int start = front;
//            front = rear;
//            for (int i = start; i < front; i++)
//            {
//                int x = queue[i];
//                for (int j = 0; j < len[x]; j++)
//                {
//                    int y = grid[x][j];
//                    if (!vis[y])
//                    {
//                        vis[y] = true;
//                        queue[rear++] = y;
//                    }
//                }
//            }
//            ans[k++] += rear - front;
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        bfs(i);
//    }
//
//    *returnSize = n;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* countOfPairs(int n, int x, int y, int* returnSize)
//{
//    int* ans = (int*)calloc(sizeof(int), n);
//    for (int i = 1; i < n + 1; i++)
//    {
//        for (int j = i + 1; j < n + 1; j++)
//        {
//            int dist1 = j - i; // 直接从 i 到 j;
//            int dist2 = abs(i - x) + 1 + abs(j - y); // 从 i 到 x 到 y 再到 j;
//            int dist3 = abs(j - x) + 1 + abs(i - y); // 从 i 到 y 到 x 再到 j;
//            int min = fmin(dist1, fmin(dist2, dist3));
//            ans[min - 1] += 2;
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////3622. 判断整除性    
//
//bool checkDivisibility(int n)
//{
//    int mul = 1, sum = 0, tmp = n;
//    while (tmp)
//    {
//        sum += tmp % 10;
//        mul *= tmp % 10;
//        tmp /= 10;
//    }
//    return n % (sum + mul) == 0;
//}
//
////2903. 找出满足差值条件的下标 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    *returnSize = 2;
//    ans[0] = ans[1] = -1;
//    for (int i = 0; i < numsSize - indexDifference; i++)
//    {
//        for (int j = indexDifference + i; j < numsSize; j++)
//        {
//            if (abs(nums[i] - nums[j]) >= valueDifference)
//            {
//                ans[0] = i; ans[1] = j;
//                return ans;
//            }
//        }
//    }
//    return ans;
//}
//
////3083. 字符串及其反转中是否存在同一子字符串
//
//bool isSubstringPresent(char* s)
//{
//    int n = strlen(s);
//    char* s1 = (char*)malloc(sizeof(char) * (n + 1));
//    s1[n] = '\0';
//    for (int i = 0; i < n; i++)
//    {
//        s1[n - 1 - i] = s[i];
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        char tmp = s[i + 2];
//        s[i + 2] = '\0';
//        char* sub = strstr(s1, s + i);
//        if (sub) return true;
//        s[i + 2] = tmp;
//    }
//    return false;
//}
//
