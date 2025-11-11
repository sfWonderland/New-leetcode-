////898. 子数组按位或操作
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int subarrayBitwiseORs(int* arr, int arrSize)
//{
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    int ans = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        HASH_FIND_INT(hash, &arr[i], pEntry);
//        if (pEntry == NULL)
//        {
//            ans++;
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = arr[i];
//            HASH_ADD_INT(hash, key, pEntry);
//        }
//        for (int j = i - 1; j >= 0; j--)
//        {
//            if ((arr[j] | arr[i]) == arr[j])
//                break;
//
//            arr[j] |= arr[i];
//            HASH_FIND_INT(hash, &arr[j], pEntry);
//            if (pEntry == NULL)
//            {
//                ans++;
//                pEntry = (HashItem*)malloc(sizeof(HashItem));
//                pEntry->key = arr[j];
//                HASH_ADD_INT(hash, key, pEntry);
//            }
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, pEntry, tmp)
//    {
//        free(pEntry);
//    }
//    return ans;
//}
//
////2447. 最大公因数等于 K 的子数组数目
//
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//int subarrayGCD(int* nums, int numsSize, int k)
//{
//    int ans = 0, cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt += (nums[i] == k);
//        for (int j = i - 1; j >= 0; j--)
//        {
//            int m = gcd(nums[i], nums[j]);
//            if (m == nums[j])
//                break;
//
//            cnt -= (nums[j] == k);
//            nums[j] = m;
//            cnt += (nums[j] == k);
//        }
//        ans += cnt;
//    }
//    return ans;
//}
//
////2580. 统计将重叠区间合并成组的方案数
//
//const int mod = 1e9 + 7;
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int countWays(int** ranges, int rangesSize, int* rangesColSize)
//{
//    qsort(ranges, rangesSize, sizeof(int*), cmp);
//    int ans = 1, max_r = -1;
//    for (int i = 0; i < rangesSize; i++)
//    {
//        if (ranges[i][0] > max_r)
//        {
//            ans = ans * 2 % mod;
//        }
//        max_r = fmax(max_r, ranges[i][1]);
//    }
//    return ans;
//}
//
////435. 无重叠区间
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[1] - (*(int**)e2)[1];
//}
//int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
//{
//    if (intervalsSize == 0)
//        return 0;
//    qsort(intervals, intervalsSize, sizeof(int*), cmp);
//    int right = intervals[0][1];
//    int ans = 1;
//    for (int i = 1; i < intervalsSize; i++)
//    {
//        if (intervals[i][0] >= right)
//        {
//            ans++;
//            right = intervals[i][1];
//        }
//    }
//    return intervalsSize - ans;
//}
//
