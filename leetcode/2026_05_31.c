//// 3945. 计算数字频率得分
//
//int digitFrequencyScore(int n)
//{
//    int ans = 0;
//    while (n)
//    {
//        ans += n % 10;
//        n /= 10;
//    }
//    return ans;
//}
//
//// 3946. 购买最多物品数目 I   
//
//int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget)
//{
//    int n = budget, m = itemsSize;
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    int min_price = INT_MAX;
//    for (int i = 0; i < m; i++)
//    {
//        int factor = items[i][0], price = items[i][1];
//        min_price = min_price > price ? price : min_price;
//        int cnt = 0;
//        for (int j = 0; j < m; j++)
//        {
//            cnt += (items[j][0] % factor == 0);
//        }
//
//        for (int k = n; k >= price; k--)
//        {
//            f[k] = fmax(f[k], f[k - price] + cnt);
//        }
//    }
//
//    int ans = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        ans = fmax(ans, f[i] + (n - i) / min_price);
//    }
//    return ans;
//}
//
//int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget)
//{
//    int n = budget, m = itemsSize;
//    int min_price = INT_MAX, max_factor = 0;
//    for (int i = 0; i < m; i++)
//    {
//        max_factor = fmax(max_factor, items[i][0]);
//        min_price = fmin(min_price, items[i][1]);
//    }
//    int factors[max_factor + 1];
//    memset(factors, 0, sizeof(factors));
//    for (int i = 0; i < m; i++)
//    {
//        factors[items[i][0]]++;
//    }
//    int multi_factors[max_factor + 1];
//    memset(multi_factors, 0, sizeof(multi_factors));
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    int sum_price = 0;
//    for (int i = 0; i < m; i++)
//    {
//        int factor = items[i][0], price = items[i][1];
//        if (multi_factors[factor] == 0)
//        {
//            for (int j = factor; j <= max_factor; j += factor)
//            {
//                multi_factors[factor] += factors[j];
//            }
//        }
//        sum_price = fmin(sum_price + price, n);
//        for (int j = sum_price; j >= price; j--)
//        {
//            f[j] = fmax(f[j], f[j - price] + multi_factors[factor]);
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        ans = fmax(ans, f[i] + (n - i) / min_price);
//        // printf("%d| %d %d %d\n", i, f[i], (n - i) / min_price, ans);
//    }
//    return ans;
//}
//
//// 3947. 购买最多物品数目 II
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget)
//{
//    int n = budget, m = itemsSize;
//    int min_price = INT_MAX, max_factor = 0;
//    for (int i = 0; i < m; i++)
//    {
//        max_factor = fmax(max_factor, items[i][0]);
//        min_price = fmin(min_price, items[i][1]);
//    }
//    int factors[max_factor + 1];
//    memset(factors, 0, sizeof(factors));
//    for (int i = 0; i < m; i++)
//    {
//        factors[items[i][0]]++;
//    }
//    int multi_factors[max_factor + 1];
//    memset(multi_factors, 0, sizeof(multi_factors));
//    int** f = (int**)malloc(sizeof(int*) * m);
//    int sum_price = 0, k = 0;
//    for (int i = 0; i < m; i++)
//    {
//        int factor = items[i][0], price = items[i][1];
//        if (price >= min_price * 2)
//            continue;
//        if (multi_factors[factor] == 0)
//        {
//            for (int j = factor; j <= max_factor; j += factor)
//            {
//                multi_factors[factor] += factors[j];
//            }
//        }
//
//        if (multi_factors[factor] > 1)
//        {
//            f[k] = (int*)malloc(sizeof(int) * 2);
//            f[k][0] = price;
//            f[k++][1] = multi_factors[factor] - 1;
//        }
//    }
//    qsort(f, k, sizeof(int*), cmp);
//    int ans = 0;
//    for (int i = 0; i < k; i++)
//    {
//        if (n < f[i][0])
//            break;
//
//        int cnt = fmin(f[i][1], budget / f[i][0]);
//        budget -= cnt * f[i][0];
//        ans += 2 * cnt;
//        free(f[i]);
//    }
//    free(f);
//    return ans + budget / min_price;
//}
//
//// 3948. 字典序最大的 MEX 数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void reverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left++] = nums[right];
//        nums[right--] = tmp;
//    }
//}
//int* maximumMEX(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize;
//    int** pos = (int**)malloc(sizeof(int*) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    int* top = (int*)calloc(sizeof(int), n);
//    for (int i = 0; i < n; i++)
//    {
//        int j = nums[i];
//        if (j >= n)
//            continue;
//        if (top[j] == 0)
//        {
//            capacity[j] = 8;
//            pos[j] = (int*)malloc(sizeof(int) * capacity[j]);
//        }
//        pos[j][top[j]++] = i;
//        if (top[j] >= capacity[j])
//        {
//            capacity[j] *= 2;
//            pos[j] = (int*)realloc(pos[j], sizeof(int) * capacity[j]);
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (top[i] == 0)
//            continue;
//        reverse(pos[i], 0, top[i] - 1);
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int k = 0, i = 0;
//    while (i < n)
//    {
//        int start = i;
//        int mex = 0;
//        while (mex < n)
//        {
//            while (top[mex] > 0 && pos[mex][top[mex] - 1] < start)
//                top[mex]--;
//            if (top[mex] == 0)
//                break;
//
//            i = fmax(i, pos[mex][top[mex] - 1]);
//            mex++;
//        }
//        ans[k++] = mex;
//        i++;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (top[i])
//            free(pos[i]);
//    }
//    free(pos);
//    free(top);
//    free(capacity);
//    *returnSize = k;
//    return ans;
//}
//
