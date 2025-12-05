////2369. 检查数组是否存在有效划分
//
//bool validPartition(int* nums, int numsSize)
//{
//    int n = numsSize;
//    bool f[n + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 1; i < n; i++)
//    {
//        if (f[i - 1] && nums[i - 1] == nums[i]
//            || i > 1 && f[i - 2] && ((nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i]) ||
//                (nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i])))
//            f[i + 1] = 1;
//    }
//    return f[n];
//}
//
////139. 单词拆分
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//bool wordBreak(char* s, char** wordDict, int wordDictSize)
//{
//    HashItem* words = NULL;
//    HashItem* pEntry = NULL;
//    int max_l = 0;
//    for (int i = 0; i < wordDictSize; i++)
//    {
//        max_l = fmax(max_l, strlen(wordDict[i]));
//        pEntry = (HashItem*)malloc(sizeof(HashItem));
//        pEntry->key = wordDict[i];
//        HASH_ADD_STR(words, key, pEntry);
//    }
//    int n = strlen(s);
//    int* vis = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i <= n; i++)
//    {
//        vis[i] = -1;
//    }
//    bool dfs(int i)
//    {
//        if (i == 0)
//            return true;
//
//        if (vis[i] != -1)
//            return vis[i];
//        for (int j = i - 1; j >= fmax(i - max_l, 0); j--)
//        {
//            char* sub = (char*)malloc(sizeof(char) * (i - j + 1));
//            strncpy(sub, s + j, i - j);
//            sub[i - j] = '\0';
//            HASH_FIND_STR(words, sub, pEntry);
//            if (pEntry && dfs(j))
//            {
//                vis[i] = 1;
//                return true;
//            }
//        }
//        vis[i] = 0;
//        return false;
//    }
//    return dfs(n);
//}
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//bool wordBreak(char* s, char** wordDict, int wordDictSize)
//{
//    HashItem* words = NULL;
//    HashItem* pEntry = NULL;
//    int max_l = 0;
//    for (int i = 0; i < wordDictSize; i++)
//    {
//        max_l = fmax(max_l, strlen(wordDict[i]));
//        pEntry = (HashItem*)malloc(sizeof(HashItem));
//        pEntry->key = wordDict[i];
//        HASH_ADD_STR(words, key, pEntry);
//    }
//    int n = strlen(s);
//    bool f[n + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = i - 1; j >= fmax(i - max_l, 0); j--)
//        {
//            char* sub = (char*)malloc(sizeof(char) * (i - j + 1));
//            strncpy(sub, s + j, i - j);
//            sub[i - j] = '\0';
//            HASH_FIND_STR(words, sub, pEntry);
//            if (pEntry && f[j])
//            {
//                f[i] = 1;
//                break;
//            }
//        }
//    }
//    return f[n];
//}
//
////132. 分割回文串 II
//
//int minCut(char* s)
//{
//    int n = strlen(s);
//    int* vis = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i <= n; i++)
//    {
//        vis[i] = INT_MAX;
//    }
//    bool isPalindrome(int l, int r)
//    {
//        while (l < r)
//        {
//            if (s[l] != s[r])
//                return false;
//            l++; r--;
//        }
//        return true;
//    }
//    int dfs(int r)
//    {
//        if (isPalindrome(0, r))
//            return 0;
//
//        if (vis[r] != INT_MAX)
//            return vis[r];
//
//        for (int l = 1; l <= r; l++)
//        {
//            if (isPalindrome(l, r))
//                vis[r] = fmin(vis[r], dfs(l - 1) + 1);
//        }
//        return vis[r];
//    }
//
//    return dfs(n - 1);
//}
//
//int minCut(char* s)
//{
//    int n = strlen(s);
//    bool** isPalindrome = (bool**)malloc(sizeof(bool*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        isPalindrome[i] = (bool*)malloc(sizeof(bool) * n);
//        for (int j = 0; j < n; j++)
//        {
//            isPalindrome[i][j] = 1;
//        }
//    }
//    for (int l = n - 2; l >= 0; l--)
//    {
//        for (int r = l + 1; r < n; r++)
//        {
//            isPalindrome[l][r] = s[l] == s[r] && isPalindrome[l + 1][r - 1];
//        }
//    }
//    int f[n];
//    memset(f, 0, sizeof(f));
//    for (int r = 0; r < n; r++)
//    {
//        if (isPalindrome[0][r])
//            continue;
//        int res = INT_MAX;
//        for (int l = 1; l <= r; l++)
//        {
//            if (isPalindrome[l][r])
//                res = fmin(res, f[l - 1] + 1);
//        }
//        f[r] = res;
//    }
//
//    return f[n - 1];
//}
//
////3578. 统计极差最大为 K 的分割方式数
//
////TO(n^2)
//const int mod = 1e9 + 7;
//int countPartitions(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int res[n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        res[i] = -1;
//    }
//    int dfs(int i)
//    {
//        if (i == 0)
//            return 1;
//
//        if (res[i] != -1)
//            return res[i];
//
//        int min = nums[i - 1];
//        int max = min;
//        long long ret = 0;
//        for (int j = i - 1; j >= 0; j--)
//        {
//            max = fmax(max, nums[j]);
//            min = fmin(min, nums[j]);
//            if (max - min <= k)
//                ret = (ret + dfs(j)) % mod;
//        }
//        res[i] = ret;
//        return ret;
//    }
//    return dfs(n);
//}
//
////TO(n^2)
//const int mod = 1e9 + 7;
//int countPartitions(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int f[n + 1];
//    f[0] = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        int max = nums[i - 1];
//        int min = max;
//        long long ret = 0;
//        for (int j = i - 1; j >= 0; j--)
//        {
//            max = fmax(max, nums[j]);
//            min = fmin(min, nums[j]);
//            if (max - min <= k)
//                ret = (ret + f[j]) % mod;
//        }
//        f[i] = ret;
//    }
//    return f[n];
//}
//
////TO(n)
//const int mod = 1e9 + 7;
//int countPartitions(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int f[n + 1];
//    f[0] = 1;
//    int* min_q = (int*)malloc(sizeof(int) * n);
//    int* max_q = (int*)malloc(sizeof(int) * n);
//    int min_l = 0, max_l = 0;
//    int min_r = 0, max_r = 0;
//    int left = 0;
//    long long sum_f = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        int x = nums[i];
//        sum_f += f[i];
//
//        while (min_r - min_l > 0 && x <= nums[min_q[min_r - 1]])
//        {
//            min_r--;
//        }
//        min_q[min_r++] = i;
//
//        while (max_r - max_l > 0 && x >= nums[max_q[max_r - 1]])
//        {
//            max_r--;
//        }
//        max_q[max_r++] = i;
//
//        while (nums[max_q[max_l]] - nums[min_q[min_l]] > k)
//        {
//            sum_f -= f[left];
//            left++;
//
//            if (min_q[min_l] < left)
//                min_l++;
//
//            if (max_q[max_l] < left)
//                max_l++;
//        }
//
//        f[i + 1] = sum_f % mod;
//    }
//    return f[n];
//}
//
