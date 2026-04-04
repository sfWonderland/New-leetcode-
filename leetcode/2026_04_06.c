////3597. 分割字符串
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//char** partitionString(char* s, int* returnSize)
//{
//    int n = strlen(s);
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    int ansSize = 0;
//    char* tmp = (char*)calloc(sizeof(char), n + 1);
//    int k = 0;
//    HashItem* cnt = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        tmp[k++] = s[i];
//        HASH_FIND_STR(cnt, tmp, p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            ans[ansSize] = (char*)malloc(sizeof(char) * (k + 1));
//            strcpy(ans[ansSize], tmp);
//            p->key = ans[ansSize++];
//            HASH_ADD_STR(cnt, key, p);
//            memset(tmp, 0, sizeof(char) * (n / 2 + 1));
//            k = 0;
//        }
//    }
//    HashItem* temp = NULL;
//    HASH_ITER(hh, cnt, p, temp)
//    {
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    free(tmp);
//    *returnSize = ansSize;
//    return ans;
//}
//
////3889. 镜像频次距离    
//
//int mirrorFrequency(char* s)
//{
//    int cnt1[10] = { 0 }, cnt2[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] > '9')
//        {
//            cnt2[s[i] - 'a']++;
//        }
//        else
//        {
//            cnt1[s[i] - '0']++;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < 5; i++)
//    {
//        ans += abs(cnt1[i] - cnt1[9 - i]);
//    }
//    for (int i = 0; i < 13; i++)
//    {
//        ans += abs(cnt2[i] - cnt2[25 - i]);
//    }
//    return ans;
//}
//
////3890. 可由多种立方和构造的整数
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
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* findGoodIntegers(int n, int* returnSize)
//{
//    int m = pow(n - 1, 1.0 / 3);
//    // printf("%d\n", m);
//    HashItem* cnt = NULL;
//    HashItem* p = NULL;
//    int capacity = 8;
//    int* ans = (int*)malloc(sizeof(int) * capacity);
//    int ansSize = 0;
//    int arr[m + 2];
//    for (int i = 1; i < m + 2; i++)
//    {
//        arr[i] = i * i * i;
//    }
//    for (int i = 1; i <= m; i++)
//    {
//        for (int j = i + 1; j <= m + 1 && arr[j] <= n - arr[i]; j++)
//        {
//            int sum = arr[i] + arr[j];
//            HASH_FIND_INT(cnt, &sum, p);
//            if (p == NULL)
//            {
//                p = (HashItem*)malloc(sizeof(HashItem));
//                p->key = sum;
//                p->val = 0;
//                HASH_ADD_INT(cnt, key, p);
//            }
//            p->val++;
//            if (p->val == 2)
//            {
//                ans[ansSize++] = sum;
//                if (ansSize >= capacity)
//                {
//                    capacity *= 2;
//                    ans = (int*)realloc(ans, sizeof(int) * capacity);
//                }
//            }
//        }
//    }
//    qsort(ans, ansSize, sizeof(int), cmp);
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        //printf("%d ", p -> key);
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////3891. 最大化特殊下标数目的最少增加次数
//
//long long minIncrease(int* nums, int numsSize)
//{
//    long long suf = 0;
//    int n = numsSize;
//    for (int i = n - 2; i > 0; i -= 2)
//    {
//        suf += fmax(fmax(nums[i - 1], nums[i + 1]) + 1 - nums[i], 0);
//    }
//    if (n & 1)
//        return suf;
//
//    long long ans = suf, pre = 0;
//    for (int i = 1; i < n - 1; i += 2)
//    {
//        pre += fmax(fmax(nums[i - 1], nums[i + 1]) + 1 - nums[i], 0);
//        suf -= fmax(fmax(nums[i], nums[i + 2]) + 1 - nums[i + 1], 0);
//        ans = fmin(ans, pre + suf);
//    }
//    return ans;
//}
//
