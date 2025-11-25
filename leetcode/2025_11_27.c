////3381. 长度可被 K 整除的子数组的最大元素和
//
//long long maxSubarraySum(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    long long sum[n + 1];
//    sum[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum[i + 1] = sum[i] + nums[i];
//    }
//    long long min_s[k];
//    for (int i = 0; i < k; i++)
//    {
//        min_s[i] = LLONG_MAX / 2;
//    }
//    long long ans = LLONG_MIN;
//    for (int i = 0; i <= n; i++)
//    {
//        int j = i % k;
//        ans = fmax(ans, sum[i] - min_s[j]);
//        min_s[j] = fmin(min_s[j], sum[i]);
//    }
//    return ans;
//}
//
//long long maxSubarraySum(int* nums, int numsSize, int k)
//{
//    long long min_s[k];
//    for (int i = 0; i < k; i++)
//    {
//        min_s[i] = LLONG_MAX / 2;
//    }
//    //这里前缀和的下标从 ?1 开始，也就是定义 s[?1]=0。由于 ?1 与 k?1 模 k 同余，所以初始化 minS[k?1]=0。
//    min_s[k - 1] = 0;
//    long long ans = LLONG_MIN, sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        int j = i % k;
//        ans = fmax(ans, sum - min_s[j]);
//        min_s[j] = fmin(min_s[j], sum);
//    }
//    return ans;
//}
//
////1297. 子串的最大出现次数
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
////越短越合法， 故只找最短子串
//int maxFreq(char* s, int maxLetters, int minSize, int maxSize)
//{
//    int alpha[26] = { 0 };
//    int cnt = 0;
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; s[i]; ++i)
//    {
//        int in = s[i] - 'a';
//        if (alpha[in] == 0)
//            ++cnt;
//        ++alpha[in];
//
//        int left = i - minSize + 1;
//        if (left < 0)
//            continue;
//
//        if (cnt <= maxLetters)
//        {
//            char* subS = (char*)malloc(sizeof(char) * (minSize + 1));
//            for (int j = left; j <= i; j++)
//            {
//                subS[j - left] = s[j];
//            }
//            subS[i - left + 1] = '\0';
//            HASH_FIND_STR(hash, subS, pEntry);
//            if (pEntry == NULL)
//            {
//                pEntry = (HashItem*)malloc(sizeof(HashItem));
//                pEntry->key = subS;
//                pEntry->val = 1;
//                HASH_ADD_STR(hash, key, pEntry);
//            }
//            else
//                pEntry->val++;
//        }
//
//        int out = s[left] - 'a';
//        alpha[out]--;
//        if (alpha[out] == 0)
//            cnt--;
//    }
//    int ans = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, pEntry, tmp)
//    {
//        ans = fmax(ans, pEntry->val);
//        free(pEntry);
//    }
//    return ans;
//}
//
////3577. 统计计算机解锁顺序排列数
//
//const int mod = 1e9 + 7;
//int countPermutations(int* complexity, int complexitySize)
//{
//    int ans = 1;
//    for (int i = 1; i < complexitySize; i++)
//    {
//        if (complexity[i] <= complexity[0])
//            return 0;
//
//        ans = 1ll * ans * i % mod;
//    }
//    return ans;
//}
//
////3282. 到达数组末尾的最大得分
//
//long long findMaximumScore(int* nums, int numsSize)
//{
//    long long ans = 0;
//    int max = 0;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        max = fmax(nums[i], max);
//        ans += max;
//    }
//    return ans;
//}
//
