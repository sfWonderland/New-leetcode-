////1338. 数组大小减半
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int minSetSize(int* arr, int arrSize)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int* cnt = (int*)malloc(sizeof(int) * arrSize);
//    int idx = 0;
//    cnt[idx] = 1;
//    for (int i = 1; i < arrSize; i++)
//    {
//        if (arr[i] == arr[i - 1])
//            cnt[idx]++;
//        else
//            cnt[++idx] = 1;
//    }
//    qsort(cnt, idx + 1, sizeof(int), cmp);
//    int k = arrSize / 2;
//    int i = 0;
//    while (arrSize > k)
//    {
//        arrSize -= cnt[i++];
//    }
//
//    return i;
//}
//
////3627. 中位数之和的最大值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long maximumMedianSum(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int left = 0, right = numsSize - 1;
//    long long ans = 0;
//    while (left < right)
//    {
//        ans = ans + nums[right - 1];
//        right -= 2;
//        left++;
//    }
//    return ans;
//}
//
////3462. 提取至多 K 个元素的最大总和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maxSum(int** grid, int gridSize, int* gridColSize, int* limits, int limitsSize, int k)
//{
//    for (int i = 0; i < gridSize; i++)
//    {
//        qsort(grid[i], gridColSize[i], sizeof(int), cmp);
//    }
//    long long ans = 0;
//    int idx[gridSize];
//    memset(idx, 0, sizeof(idx));
//    while (k > 0)
//    {
//        int max = 0, pos = gridSize;
//        for (int i = 0; i < gridSize; i++)
//        {
//            if (limits[i] == 0)
//                continue;
//            if (max < grid[i][idx[i]])
//            {
//                max = grid[i][idx[i]];
//                pos = i;
//            }
//        }
//        if (pos == gridSize)
//            break;
//        limits[pos]--;
//        idx[pos]++;
//        ans = ans + max;
//        k--;
//        //printf("%d %d %d %ld\n", pos, limits[pos], k, ans);
//    }
//    return ans;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maxSum(int** grid, int gridSize, int* gridColSize, int* limits, int limitsSize, int k)
//{
//    for (int i = 0; i < gridSize; i++)
//    {
//        qsort(grid[i], gridColSize[i], sizeof(int), cmp);
//    }
//    int sum = 0;
//    for (int i = 0; i < limitsSize; i++)
//    {
//        sum += limits[i];
//    }
//    int* arr = (int*)malloc(sizeof(int) * sum);
//    int idx = 0;
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < limits[i]; j++)
//        {
//            arr[idx++] = grid[i][j];
//        }
//    }
//    qsort(arr, idx, sizeof(int), cmp);
//    long long ans = 0;
//    while (k > 0)
//    {
//        ans += arr[--k];
//    }
//    return ans;
//}
//
////3576. 数组元素相等转换
//
//bool check(int* nums, int n, int k, int target)
//{
//    int mul = 1;
//    for (int i = 0; i < n; i++)
//    {
//        if (nums[i] * mul == target)
//        {
//            mul = 1;
//            continue;
//        }
//
//        if (k == 0 || i + 1 == n)
//            return false;
//
//        mul = -1;
//        k--;
//    }
//    return true;
//}
//bool canMakeEqual(int* nums, int numsSize, int k)
//{
//
//    return check(nums, numsSize, k, 1) || check(nums, numsSize, k, -1);
//}
//
