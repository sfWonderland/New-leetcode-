////2975. 移除栅栏得到的正方形田地的最大面积
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int* getEdges(int* nums, int numsSize, int n, int* edgesSize)
//{
//    int arrSize = numsSize + 2;
//    int* arr = (int*)malloc(sizeof(int) * arrSize);
//    arr[0] = 1;
//    memcpy(arr + 1, nums, sizeof(int) * numsSize);
//    arr[arrSize - 1] = n;
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int MaxEdgeSize = (arrSize) * (arrSize - 1) / 2;
//    int* edges = (int*)malloc(sizeof(int) * MaxEdgeSize);
//    int k = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        for (int j = i + 1; j < arrSize; j++)
//        {
//            edges[k++] = arr[i] - arr[j];
//        }
//    }
//    free(arr);
//    qsort(edges, k, sizeof(int), cmp);
//    int idx = 1;
//    for (int i = 1; i < k; i++)
//    {
//        if (edges[i] != edges[i - 1])
//            edges[idx++] = edges[i];
//    }
//    *edgesSize = idx;
//    return edges;
//}
//const int MOD = 1e9 + 7;
//int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize)
//{
//    int hEdgesSize = 0, vEdgesSize = 0;
//    int* hEdges = getEdges(hFences, hFencesSize, m, &hEdgesSize);
//    int* vEdges = getEdges(vFences, vFencesSize, n, &vEdgesSize);
//    int i = 0, j = 0;
//    while (i < hEdgesSize && j < vEdgesSize)
//    {
//        if (hEdges[i] == vEdges[j])
//            return 1ll * hEdges[i] * hEdges[i] % MOD;
//        else if (hEdges[i] < vEdges[j])
//            j++;
//        else
//            i++;
//    }
//    return -1;
//}
//
////1785. 构成特定和需要添加的最少元素    
//
//int minElements(int* nums, int numsSize, int limit, int goal)
//{
//    long long sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    long long dist = fabs(sum - goal);
//    return (dist + limit - 1) / limit;
//}
//
////1535. 找出数组游戏的赢家
//
//int getWinner(int* arr, int arrSize, int k)
//{
//    int max = arr[0], win = -1;
//    for (int i = 0; i < arrSize; i++)
//    {
//        if (arr[i] > max)
//        {
//            win = 0;
//            max = arr[i];
//        }
//        win++;
//        if (win == k)
//            break;
//    }
//    return max;
//}
//
////1375. 二进制字符串前缀一致的次数
//
//int numTimesAllBlue(int* flips, int flipsSize)
//{
//    int max = 0, ans = 0;
//    for (int i = 0; i < flipsSize; i++)
//    {
//        max = fmax(max, flips[i]);
//        if (max == i + 1)
//            ans++;
//    }
//    return ans;
//}
//
