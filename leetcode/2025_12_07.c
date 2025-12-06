////3769. 二进制反射排序
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//uint32_t reverse(uint32_t n)
//{
//    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
//    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
//    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
//    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
//    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
//    return n;
//}
//int cmp(const void* e1, const void* e2)
//{
//    int a = reverse(*(int*)e1) >> __builtin_clz(*(int*)e1);
//    int b = reverse(*(int*)e2) >> __builtin_clz(*(int*)e2);
//    return a == b ? *(int*)e1 - *(int*)e2 : a - b;
//}
//int* sortByReflection(int* nums, int numsSize, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    *returnSize = numsSize;
//    return nums;
//}
//
////3770. 可表示为连续质数和的最大质数
//
//int largestPrime(int n)
//{
//    if (n == 1)
//        return 0;
//
//    bool* isPrime = (bool*)malloc(sizeof(bool) * (n + 1));
//    isPrime[0] = isPrime[1] = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        isPrime[i] = 1;
//    }
//    for (int i = 2; i * i <= n; i++)
//    {
//        if (isPrime[i])
//        {
//            for (int j = i * i; j <= n; j += i)
//            {
//                isPrime[j] = 0;
//            }
//        }
//    }
//    int sum = 0, ans = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        if (!isPrime[i])
//            continue;
//        sum += i;
//        if (sum <= n && isPrime[sum])
//            ans = sum;
//        if (sum > n)
//            return ans;
//    }
//    return ans;
//}
//
////3771. 探索地牢的得分
//
//long long totalScore(int hp, int* damage, int damageSize, int* requirement, int requirementSize)
//{
//    int n = damageSize;
//    int* sum = (int*)malloc(sizeof(int) * (n + 1));
//    sum[0] = 0;
//    long long ans = 0;
//
//    int binary_search(int left, int right, int x)
//    {
//        while (left < right)
//        {
//            int mid = (left + right) / 2;
//            if (x > sum[mid])
//                left = mid + 1;
//            else
//                right = mid;
//        }
//        return left;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        sum[i + 1] = damage[i] + sum[i];
//        int low = sum[i + 1] + requirement[i] - hp;
//        int j = binary_search(0, i + 1, low);
//        //printf("%d ", left);
//        ans += i - j + 1;
//    }
//    return ans;
//}
//
////2707. 字符串中的额外字符
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//int minExtraChar(char* s, char** dictionary, int dictionarySize)
//{
//    HashItem* words = NULL;
//    HashItem* pEntry = NULL;
//    int max_l = 0;
//    for (int i = 0; i < dictionarySize; i++)
//    {
//        pEntry = (HashItem*)malloc(sizeof(HashItem));
//        pEntry->key = dictionary[i];
//        max_l = fmax(max_l, strlen(dictionary[i]));
//        HASH_ADD_STR(words, key, pEntry);
//    }
//    int n = strlen(s);
//    int* res = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        res[i] = -1;
//    }
//    int dfs(int i)
//    {
//        if (i < 0)
//            return 0;
//
//        if (res[i] != -1)
//            return res[i];
//
//        res[i] = dfs(i - 1) + 1;
//        for (int j = 0; j <= i; j++)
//        {
//            char* sub = (char*)malloc(sizeof(char) * (i - j + 2));
//            strncpy(sub, s + j, i - j + 1);
//            sub[i - j + 1] = '\0';
//            // if(i == n - 1)
//            // printf("%d %d %s\n", j, i, sub);
//            HASH_FIND_STR(words, sub, pEntry);
//            if (pEntry)
//            {
//                res[i] = fmin(res[i], dfs(j - 1));
//            }
//        }
//        return res[i];
//    }
//    return dfs(n - 1);
//}
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//int minExtraChar(char* s, char** dictionary, int dictionarySize)
//{
//    HashItem* words = NULL;
//    HashItem* pEntry = NULL;
//    int max_l = 0;
//    for (int i = 0; i < dictionarySize; i++)
//    {
//        pEntry = (HashItem*)malloc(sizeof(HashItem));
//        pEntry->key = dictionary[i];
//        max_l = fmax(max_l, strlen(dictionary[i]));
//        HASH_ADD_STR(words, key, pEntry);
//    }
//    int n = strlen(s);
//    int f[n + 1];
//    f[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int res = f[i] + 1;
//        for (int j = 0; j <= i; j++)
//        {
//            char* sub = (char*)malloc(sizeof(char) * (i - j + 2));
//            strncpy(sub, s + j, i - j + 1);
//            sub[i - j + 1] = '\0';
//            HASH_FIND_STR(words, sub, pEntry);
//            if (pEntry)
//                res = fmin(res, f[j]);
//        }
//        f[i + 1] = res;
//    }
//    return f[n];
//}
//
