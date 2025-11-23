////1015. 可被 K 整除的最小整数
//
//int smallestRepunitDivByK(int k)
//{
//    if (k % 2 == 0 || k % 5 == 0)
//        return -1;
//    int x = 1 % k;
//    for (int i = 1; ; i++)
//    {
//        if (x == 0)
//            return i;
//
//        x = (10 * x + 1) % k;
//    }
//    return -1;
//}
//
////2080. 区间内查询数字的频率
//
//int lowerBound(int* nums, int n, int x)
//{
//    int l = 0, r = n - 1;
//    while (l <= r)
//    {
//        int mid = l + (r - l) / 2;
//        if (nums[mid] < x)
//            l = mid + 1;
//        else
//            r = mid - 1;
//    }
//    return l;
//}
//
//typedef struct
//{
//    int key;
//    int* val;
//    int size;
//    int capacity;
//    UT_hash_handle hh;
//}HashItem;
//
//typedef struct
//{
//    HashItem* nums;
//} RangeFreqQuery;
//
//
//RangeFreqQuery* rangeFreqQueryCreate(int* arr, int arrSize)
//{
//    RangeFreqQuery* obj = (RangeFreqQuery*)malloc(sizeof(RangeFreqQuery));
//    obj->nums = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < arrSize; i++)
//    {
//        HASH_FIND_INT(obj->nums, &arr[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = arr[i];
//            pEntry->capacity = 64;
//            pEntry->val = (int*)malloc(sizeof(int) * pEntry->capacity);
//            pEntry->size = 0;
//            HASH_ADD_INT(obj->nums, key, pEntry);
//        }
//        if (pEntry->size >= pEntry->capacity)
//        {
//            pEntry->capacity *= 2;
//            pEntry->val = (int*)realloc(pEntry->val, pEntry->capacity * sizeof(int));
//        }
//        pEntry->val[pEntry->size++] = i;
//    }
//    return obj;
//}
//
//int rangeFreqQueryQuery(RangeFreqQuery* obj, int left, int right, int value)
//{
//    HashItem* pEntry = NULL;
//    HASH_FIND_INT(obj->nums, &value, pEntry);
//    if (pEntry == NULL)
//        return 0;
//    return lowerBound(pEntry->val, pEntry->size, right + 1) - lowerBound(pEntry->val, pEntry->size, left);
//}
//
//void rangeFreqQueryFree(RangeFreqQuery* obj)
//{
//    HashItem* pEntry = NULL;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, obj -> nums, pEntry, tmp)
//    {
//        free(pEntry);
//    }
//    free(obj);
//}
//
///**
// * Your RangeFreqQuery struct will be instantiated and called as such:
// * RangeFreqQuery* obj = rangeFreqQueryCreate(arr, arrSize);
// * int param_1 = rangeFreqQueryQuery(obj, left, right, value);
//
// * rangeFreqQueryFree(obj);
//*/
//
////3488. 距离最小相等元素查询
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int lowerBound(int* nums, int n, int x)
//{
//    int l = 0, r = n - 1;
//    while (l <= r)
//    {
//        int mid = l + (r - l) / 2;
//        if (nums[mid] < x)
//            l = mid + 1;
//        else
//            r = mid - 1;
//    }
//    return l;
//}
//
//typedef struct
//{
//    int key;
//    int* val;
//    int size;
//    int capacity;
//    UT_hash_handle hh;
//}HashItem;
//
//int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize)
//{
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(hash, &nums[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = nums[i];
//            pEntry->capacity = 64;
//            pEntry->val = (int*)malloc(sizeof(int) * pEntry->capacity);
//            pEntry->size = 0;
//            HASH_ADD_INT(hash, key, pEntry);
//        }
//        if (pEntry->size >= pEntry->capacity)
//        {
//            pEntry->capacity *= 2;
//            pEntry->val = (int*)realloc(pEntry->val, pEntry->capacity * sizeof(int));
//        }
//        pEntry->val[pEntry->size++] = i;
//    }
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int x = nums[queries[i]];
//        HASH_FIND_INT(hash, &x, pEntry);
//        // printf("%d | ", x);
//        // for(int i = 0; i < pEntry -> size; i++)
//        // {
//        //     printf("%d ", pEntry -> val[i]);
//        // }
//        int r = lowerBound(pEntry->val, pEntry->size, queries[i] + 1);
//        int l = lowerBound(pEntry->val, pEntry->size, queries[i]) - 1;
//        // printf(" | %d %d ", l, r);
//        // printf("\n");
//        int a = r < pEntry->size ? fmin(pEntry->val[r] - queries[i], queries[i] + numsSize - pEntry->val[0]) : numsSize - queries[i] + pEntry->val[0];
//        int b = l >= 0 ? fmin(queries[i] - pEntry->val[l], pEntry->val[l] + numsSize - queries[i]) : queries[i] + numsSize - pEntry->val[pEntry->size - 1];
//        if (fmin(a, b) == numsSize)
//            ans[i] = -1;
//        else
//        {
//            ans[i] = a > b ? b : a;
//        }
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////3634. 使数组平衡的最少移除数目
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minRemoval(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = numsSize, j = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        for (j = fmax(i + 1, j); j < numsSize; j++)
//        {
//            if (1ll * nums[j] > 1ll * k * x)
//                break;
//        }
//        ans = fmin(numsSize - j + i, ans);
//    }
//    return ans;
//}
//
