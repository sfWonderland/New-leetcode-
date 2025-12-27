////756. 金字塔转换矩阵
//
//bool pyramidTransition(char* bottom, char** allowed, int allowedSize)
//{
//    bool*** groups = (bool***)malloc(sizeof(bool**) * 6);
//    for (int i = 0; i < 6; i++)
//    {
//        groups[i] = (bool**)malloc(sizeof(bool*) * 6);
//        for (int j = 0; j < 6; j++)
//        {
//            groups[i][j] = (bool*)calloc(sizeof(bool), 6);
//        }
//    }
//    for (int i = 0; i < allowedSize; i++)
//    {
//        groups[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A'] = true;
//    }
//    int n = strlen(bottom);
//    char** pyramid = (char**)malloc(sizeof(char*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        pyramid[i] = (char*)malloc(sizeof(char) * (i + 2));
//    }
//    strcpy(pyramid[n - 1], bottom);
//    bool dfs(int i, int j)
//    {
//        if (i < 0)
//            return true;
//
//        if (j == i + 1)
//            return dfs(i - 1, 0);
//
//        int left = pyramid[i + 1][j] - 'A', right = pyramid[i + 1][j + 1] - 'A';
//        for (int k = 0; k < 6; k++)
//        {
//            if (!groups[left][right][k])
//                continue;
//
//            pyramid[i][j] = k + 'A';
//            if (dfs(i, j + 1))
//                return true;
//        }
//        return false;
//    }
//    return dfs(n - 2, 0);
//}
//
//typedef struct
//{
//    char* key;
//    bool val;
//    UT_hash_handle hh;
//}HashItem;
//bool pyramidTransition(char* bottom, char** allowed, int allowedSize)
//{
//    bool*** groups = (bool***)malloc(sizeof(bool**) * 6);
//    for (int i = 0; i < 6; i++)
//    {
//        groups[i] = (bool**)malloc(sizeof(bool*) * 6);
//        for (int j = 0; j < 6; j++)
//        {
//            groups[i][j] = (bool*)calloc(sizeof(bool), 6);
//        }
//    }
//    for (int i = 0; i < allowedSize; i++)
//    {
//        groups[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A'] = true;
//    }
//    int n = strlen(bottom);
//    char** pyramid = (char**)malloc(sizeof(char*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        pyramid[i] = (char*)malloc(sizeof(char) * (i + 2));
//    }
//    strcpy(pyramid[n - 1], bottom);
//    HashItem* vis = NULL;
//    bool dfs(int i, int j)
//    {
//        if (i < 0)
//            return true;
//
//        if (j == i + 1)
//        {
//            pyramid[i][j] = '\0';
//            HashItem* pEntry = NULL;
//            HASH_FIND_STR(vis, pyramid[i], pEntry);
//            if (pEntry == NULL)
//            {
//                pEntry = (HashItem*)malloc(sizeof(HashItem));
//                pEntry->key = (char*)malloc(sizeof(char) * (j + 1));
//                strcpy(pEntry->key, pyramid[i]);
//                pEntry->val = dfs(i - 1, 0);
//                HASH_ADD_STR(vis, key, pEntry);
//            }
//            return pEntry->val;
//        }
//
//        int left = pyramid[i + 1][j] - 'A', right = pyramid[i + 1][j + 1] - 'A';
//        for (int k = 0; k < 6; k++)
//        {
//            if (!groups[left][right][k])
//                continue;
//
//            pyramid[i][j] = k + 'A';
//            if (dfs(i, j + 1))
//                return true;
//        }
//        return false;
//    }
//    bool ans = dfs(n - 2, 0);
//    HashItem* pEntry = NULL;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, vis, pEntry, tmp)
//    {
//        free(pEntry->key);
//        free(pEntry);
//    }
//    for (int i = 0; i < 6; i++)
//    {
//        for (int j = 0; j < 6; j++)
//        {
//            free(groups[i][j]);
//        }
//        free(groups[i]);
//    }
//    free(groups);
//    for (int i = 0; i < n; i++)
//    {
//        free(pyramid[i]);
//    }
//    free(pyramid);
//    return ans;
//}
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//bool pyramidTransition(char* bottom, char** allowed, int allowedSize)
//{
//    bool*** groups = (bool***)malloc(sizeof(bool**) * 6);
//    for (int i = 0; i < 6; i++)
//    {
//        groups[i] = (bool**)malloc(sizeof(bool*) * 6);
//        for (int j = 0; j < 6; j++)
//        {
//            groups[i][j] = (bool*)calloc(sizeof(bool), 6);
//        }
//    }
//    for (int i = 0; i < allowedSize; i++)
//    {
//        groups[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A'] = true;
//    }
//    int n = strlen(bottom);
//    char** pyramid = (char**)malloc(sizeof(char*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        pyramid[i] = (char*)malloc(sizeof(char) * (i + 2));
//    }
//    strcpy(pyramid[n - 1], bottom);
//    HashItem* vis = NULL;
//    bool dfs(int i, int j)
//    {
//        if (i < 0)
//            return true;
//
//        pyramid[i][j] = '\0';
//        HashItem* pEntry = NULL;
//        HASH_FIND_STR(vis, pyramid[i], pEntry);
//        if (pEntry)
//            return false;
//
//        if (j == i + 1)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * (j + 1));
//            strcpy(pEntry->key, pyramid[i]);
//            HASH_ADD_STR(vis, key, pEntry);
//            return dfs(i - 1, 0);
//        }
//
//        int left = pyramid[i + 1][j] - 'A', right = pyramid[i + 1][j + 1] - 'A';
//        for (int k = 0; k < 6; k++)
//        {
//            if (!groups[left][right][k])
//                continue;
//
//            pyramid[i][j] = k + 'A';
//            if (dfs(i, j + 1))
//                return true;
//        }
//        return false;
//    }
//    bool ans = dfs(n - 2, 0);
//    HashItem* pEntry = NULL;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, vis, pEntry, tmp)
//    {
//        free(pEntry->key);
//        free(pEntry);
//    }
//    for (int i = 0; i < 6; i++)
//    {
//        for (int j = 0; j < 6; j++)
//        {
//            free(groups[i][j]);
//        }
//        free(groups[i]);
//    }
//    free(groups);
//    for (int i = 0; i < n; i++)
//    {
//        free(pyramid[i]);
//    }
//    free(pyramid);
//    return ans;
//}
//
//bool pyramidTransition(char* bottom, char** allowed, int allowedSize)
//{
//    bool*** groups = (bool***)malloc(sizeof(bool**) * 7);
//    for (int i = 0; i < 7; i++)
//    {
//        groups[i] = (bool**)malloc(sizeof(bool*) * 7);
//        for (int j = 0; j < 7; j++)
//        {
//            groups[i][j] = (bool*)calloc(sizeof(bool), 7);
//        }
//    }
//    for (int i = 0; i < allowedSize; i++)
//    {
//        groups[allowed[i][0] & 31][allowed[i][1] & 31][allowed[i][2] & 31] = true;
//    }
//    int n = strlen(bottom);
//    int* pyramid = (int*)calloc(sizeof(int*), n);
//    for (int i = 0; i < n; i++)
//    {
//        pyramid[n - 1] |= (bottom[i] & 31) << (i * 3);
//    }
//    bool* vis = (bool*)calloc(sizeof(bool), (1 << (n - 1) * 3));
//    bool dfs(int i, int j)
//    {
//        if (i < 0)
//            return true;
//
//        if (vis[pyramid[i]])
//            return false;
//
//        if (j == i + 1)
//        {
//            vis[pyramid[i]] = true;
//            return dfs(i - 1, 0);
//        }
//
//        int left = pyramid[i + 1] >> (j * 3) & 7, right = pyramid[i + 1] >> (j * 3 + 3) & 7;
//        for (int k = 1; k < 7; k++)
//        {
//            if (!groups[left][right][k])
//                continue;
//            pyramid[i] &= ~(7 << (j * 3));
//            pyramid[i] |= k << (j * 3);
//            if (dfs(i, j + 1))
//                return true;
//        }
//        return false;
//    }
//    bool ans = dfs(n - 2, 0);
//    free(vis);
//    for (int i = 0; i < 6; i++)
//    {
//        for (int j = 0; j < 6; j++)
//        {
//            free(groups[i][j]);
//        }
//        free(groups[i]);
//    }
//    free(groups);
//    free(pyramid);
//    return ans;
//}
//
////.
//
//bool repeatedSubstringPattern(char* s)
//{
//    int n = strlen(s);
//    // 字符串至少有两个，最长为n / 2;
//    for (int i = 1; i * 2 <= n; i++) // 最小子串的长度
//    {
//        if (n % i)
//            continue;
//
//        bool match = true;
//        // 子串重复出现，相同间距下，字符一定相等
//        for (int j = i; j < n; j++) // 新子串的头开始
//        {
//            if (s[j] != s[j - i])
//            {
//                match = false;
//                break;
//            }
//        }
//        if (match)
//            return true;
//    }
//    return false;
//}
//
//bool repeatedSubstringPattern(char* s)
//{
//    int n = strlen(s);
//    char* s2 = (char*)malloc(sizeof(char) * (2 * n + 1));
//    strcpy(s2, s);
//    strcat(s2, s);
//    s2[2 * n - 1] = '\0';
//    char* ans = strstr(s2 + 1, s);
//    free(s2);
//    return ans;
//}
//
////599. 两个列表的最小索引总和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize)
//{
//    HashItem* words = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < list1Size; i++)
//    {
//        HASH_FIND_STR(words, list1[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = list1[i];
//            pEntry->val = (i + 1) * 10000;
//            HASH_ADD_STR(words, key, pEntry);
//        }
//    }
//    int min = 2002, ansSize = 0;
//    for (int i = 0; i < list2Size; i++)
//    {
//        HASH_FIND_STR(words, list2[i], pEntry);
//        if (pEntry && pEntry->val >= 10000)
//        {
//            int sum = pEntry->val / 10000 - 1 + i;
//            if (min > sum)
//            {
//                min = sum;
//                ansSize = 1;
//                pEntry->val = sum;
//            }
//            else if (min == sum)
//            {
//                ansSize++;
//                pEntry->val = sum;
//            }
//        }
//    }
//    HashItem* tmp = NULL;
//    char** ans = (char**)malloc(sizeof(char*) * ansSize);
//    int i = 0;
//    HASH_ITER(hh, words, pEntry, tmp)
//    {
//        if (min == pEntry->val)
//            ans[i++] = pEntry->key;
//        free(pEntry);
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////2395. 和相等的子数组
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//bool findSubarrays(int* nums, int numsSize)
//{
//    HashItem* sum = NULL;
//    HashItem* pEntry = NULL;
//    bool ans = false;
//    for (int i = 0; i < numsSize - 1 && !ans; i++)
//    {
//        int x = nums[i] + nums[i + 1];
//        HASH_FIND_INT(sum, &x, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = x;
//            HASH_ADD_INT(sum, key, pEntry);
//        }
//        else
//            ans = true;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, sum, pEntry, tmp)
//    {
//        free(pEntry);
//    }
//    return ans;
//}
//
