////100959. 统计残差前缀
//
//int residuePrefixes(char* s)
//{
//    bool alpha[26] = { 0 };
//    int diff = 0, ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (alpha[s[i] - 'a'] == false)
//        {
//            alpha[s[i] - 'a'] = true;
//            diff++;
//        }
//
//        if (diff >= 3)
//            break;
//
//        if ((i + 1) % 3 == diff)
//            ans++;
//    }
//    return ans;
//}
//
////3804. 中心子数组的数量    
//
//int centeredSubarrays(int* nums, int numsSize)
//{
//    int min = 100001, max = -100001;
//    int pre[numsSize + 1];
//    pre[0] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(max, nums[i]);
//        min = fmin(min, nums[i]);
//        pre[i + 1] = pre[i] + nums[i];
//    }
//    bool cnt[max - min + 1];
//    memset(cnt, 0, sizeof(bool) * (max - min + 1));
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i; j < numsSize; j++)
//        {
//            cnt[nums[j] - min] = true;
//            int sum = pre[j + 1] - pre[i];
//            if (sum <= max && sum >= min && cnt[sum - min])
//            {
//                ans++;
//            }
//        }
//        memset(cnt, 0, sizeof(bool) * (max - min + 1));
//    }
//    return ans;
//}
//
////3805. 统计凯撒加密对数目
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//long long countPairs(char** words, int wordsSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    int n = wordsSize, m = strlen(words[0]);
//    for (int i = 0; i < n; i++)
//    {
//        int diff = words[i][0] - 'a';
//        if (diff)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                words[i][j] = (words[i][j] - 'a' - diff + 26) % 26 + 'a';
//            }
//        }
//        HASH_FIND_STR(cnt, words[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = words[i];
//            pEntry->val = 0;
//            HASH_ADD_STR(cnt, key, pEntry);
//        }
//        pEntry->val++;
//    }
//    HashItem* tmp = NULL;
//    long long ans = 0;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        ans += 1ll * pEntry->val * (pEntry->val - 1) / 2;
//        free(pEntry);
//    }
//    return ans;
//}
//
////2374. 边积分最高的节点
//
//int edgeScore(int* edges, int edgesSize)
//{
//    int n = edgesSize;
//    long long sum[n];
//    memset(sum, 0, sizeof(long long) * n);
//    long long max = 0;
//    int idx = -1;
//    for (int i = 0; i < edgesSize; i++)
//    {
//        sum[edges[i]] += i;
//        if (sum[edges[i]] > max)
//        {
//            max = sum[edges[i]];
//            idx = edges[i];
//        }
//        else if (sum[edges[i]] == max && edges[i] < idx)
//            idx = edges[i];
//    }
//    return idx;
//}
//
