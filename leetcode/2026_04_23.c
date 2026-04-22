//// 2602. 使数组元素全部相等的最少操作次数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int lower_bound(int* nums, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] >= x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//long long* minOperations(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long sum[numsSize + 1];
//    sum[0] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum[i + 1] = sum[i] + nums[i];
//    }
//    long long* ans = (long long*)malloc(sizeof(long long) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int x = queries[i];
//        long long j = lower_bound(nums, numsSize, x);
//        long long left = j * x - sum[j];
//        long long right = sum[numsSize] - sum[j] - (numsSize - j) * x;
//        // printf("%lld %lld %lld\n", j, left, right);
//        ans[i] = left + right;
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
//// 2615. 等值距离和   
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//long long* distance(int* nums, int numsSize, int* returnSize)
//{
//    HashItem* pos = NULL;
//    HashItem* p = NULL;
//    int** arr = (int**)malloc(sizeof(int*) * numsSize);
//    long long** pre = (long long**)malloc(sizeof(long long*) * (numsSize + 1));
//    int* capacity = (int*)malloc(sizeof(int) * numsSize);
//    int* len = (int*)malloc(sizeof(int) * numsSize);
//    int idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(pos, &nums[i], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = nums[i];
//            p->val = idx;
//            HASH_ADD_INT(pos, key, p);
//
//            capacity[idx] = 8;
//            arr[idx] = (int*)malloc(sizeof(int) * capacity[idx]);
//            pre[idx] = (long long*)malloc(sizeof(long long) * (capacity[idx] + 1));
//            len[idx] = 0;
//            pre[idx++][0] = 0;
//        }
//        int k = p->val;
//        arr[k][len[k]] = i;
//        pre[k][len[k] + 1] = i + pre[k][len[k]];
//        len[k]++;
//        if (len[k] >= capacity[k])
//        {
//            capacity[k] *= 2;
//            arr[k] = (int*)realloc(arr[k], sizeof(int) * capacity[k]);
//            pre[k] = (long long*)realloc(pre[k], sizeof(long long) * (capacity[k] + 1));
//        }
//    }
//
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, pos, p, tmp)
//    {
//        HASH_DEL(pos, p);
//        free(p);
//    }
//
//    long long* ans = (long long*)malloc(sizeof(long long) * numsSize);
//    for (int i = 0; i < idx; i++)
//    {
//        for (int j = 0; j < len[i]; j++)
//        {
//            long long x = arr[i][j];
//            long long* sum = pre[i];
//            int* nums1 = arr[i];
//            int n = len[i];
//            long long left = j * x - sum[j];
//            long long right = sum[n] - (n - j) * x - sum[j];
//            ans[x] = left + right;
//        }
//        free(arr[i]);
//        free(pre[i]);
//    }
//    free(len);
//    free(capacity);
//    free(arr);
//    free(pre);
//    *returnSize = numsSize;
//    return ans;
//}
//
//// LCR 070. 有序数组中的单一元素
//
//int singleNonDuplicate(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans ^= nums[i];
//    }
//    return ans;
//}
//
//// LCR 073. 爱吃香蕉的狒狒
//
//int check(int* piles, int n, int x)
//{
//    int res = 0;
//    for (int i = 0; i < n; i++)
//    {
//        res += (piles[i] + x - 1) / x;
//    }
//    return res;
//}
//int minEatingSpeed(int* piles, int pilesSize, int h)
//{
//    int max = 0;
//    for (int i = 0; i < pilesSize; i++)
//    {
//        if (max < piles[i])
//            max = piles[i];
//    }
//    if (pilesSize == h)
//        return max;
//
//    int left = 1, right = max;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (check(piles, pilesSize, mid) <= h)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
