////3295. 举报垃圾信息
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//bool reportSpam(char** message, int messageSize, char** bannedWords, int bannedWordsSize)
//{
//    HashItem* banned = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < bannedWordsSize; i++)
//    {
//        HASH_FIND_STR(banned, bannedWords[i], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = bannedWords[i];
//            HASH_ADD_STR(banned, key, p);
//        }
//    }
//    int cnt = 0;
//    for (int i = 0; i < messageSize && cnt < 2; i++)
//    {
//        HASH_FIND_STR(banned, message[i], p);
//        if (p) cnt++;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, banned, p, tmp)
//    {
//        HASH_DEL(banned, p);
//        free(p);
//    }
//    return cnt == 2;
//}
//
////3249. 统计好节点的数目    
//
//int countGoodNodes(int** edges, int edgesSize, int* edgesColSize)
//{
//    int n = edgesSize + 1;
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int len[n];
//    int capacity[n];
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        len[i] = 0;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        grid[x][len[x]++] = y;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//        }
//        grid[y][len[y]++] = x;
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            grid[y] = (int*)realloc(grid[y], sizeof(int) * capacity[y]);
//        }
//    }
//    int ans = 0;
//    int dfs(int i, int fa)
//    {
//        int size = 1, sz0 = 0;
//        bool ok = true;
//        for (int j = 0; j < len[i]; j++)
//        {
//            if (grid[i][j] == fa)
//                continue;
//            int sz = dfs(grid[i][j], i);
//            if (sz0 == 0)
//                sz0 = sz;
//            else if (sz != sz0)
//                ok = false;
//
//            size += sz;
//        }
//        ans += ok;
//        return size;
//    }
//    dfs(0, -1);
//    return ans;
//}
//
////3255. 长度为 K 的子数组的能量值 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* resultsArray(int* nums, int numsSize, int k, int* returnSize)
//{
//    int cnt = 1;
//    int* ans = (int*)malloc(sizeof(int) * (numsSize - k + 1));
//    ans[0] = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] == nums[i - 1] + 1)
//            cnt++;
//        else
//            cnt = 1;
//
//        if (i < k - 1)
//            continue;
//
//        ans[i - k + 1] = cnt >= k ? nums[i] : -1;
//    }
//    *returnSize = numsSize - k + 1;
//    return ans;
//}
//
////3254. 长度为 K 的子数组的能量值 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* resultsArray(int* nums, int numsSize, int k, int* returnSize)
//{
//    int cnt = 1;
//    int* ans = (int*)malloc(sizeof(int) * (numsSize - k + 1));
//    ans[0] = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] == nums[i - 1] + 1)
//            cnt++;
//        else
//            cnt = 1;
//
//        if (i < k - 1)
//            continue;
//
//        ans[i - k + 1] = cnt >= k ? nums[i] : -1;
//    }
//    *returnSize = numsSize - k + 1;
//    return ans;
//}
//
