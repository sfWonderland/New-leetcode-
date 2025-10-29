////LCR 038. 每日温度
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
//{
//    int* st = (int*)malloc(sizeof(int) * temperaturesSize);
//    int* ans = (int*)malloc(sizeof(int) * temperaturesSize);
//    int idx = -1;
//    for (int i = 0; i < temperaturesSize; i++)
//    {
//        while (idx >= 0 && temperatures[st[idx]] < temperatures[i])
//        {
//            ans[st[idx]] = i - st[idx];
//            idx--;
//        }
//        st[++idx] = i;
//    }
//    while (idx >= 0)
//    {
//        ans[st[idx--]] = 0;
//    }
//    *returnSize = temperaturesSize;
//    return ans;
//}
//
////2428. 沙漏的最大总和
//
//int maxSum(int** grid, int gridSize, int* gridColSize)
//{
//    int ans = 0;
//    for (int i = 1; i < gridSize - 1; i++)
//    {
//        for (int j = 1; j < gridColSize[i] - 1; j++)
//        {
//            ans = fmax(ans,
//                grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1]
//                + grid[i][j]
//                + grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1]);
//        }
//    }
//    return ans;
//}
//
////LCR 033. 字母异位词分组
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int idx;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
//{
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    char*** ans = (char***)malloc(sizeof(char**) * strsSize);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
//    int idx = 0;
//    for (int i = 0; i < strsSize; i++)
//    {
//        int x = strlen(strs[i]);
//        char* s = (char*)malloc(sizeof(char) * (x + 1));
//        strcpy(s, strs[i]);
//        qsort(s, x, sizeof(char), cmp);
//        HASH_FIND_STR(hash, s, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * (x + 1));
//            strcpy(pEntry->key, s);
//            ans[idx] = (char**)malloc(sizeof(char*) * strsSize);
//            ans[idx][0] = (char*)malloc(sizeof(char) * (x + 1));
//            (*returnColumnSizes)[idx] = 1;
//            strcpy(ans[idx][0], strs[i]);
//            pEntry->idx = idx++;
//            pEntry->val = 1;
//            HASH_ADD_STR(hash, key, pEntry);
//        }
//        else
//        {
//            ans[pEntry->idx][pEntry->val] = (char*)malloc(sizeof(char) * (x + 1));
//            strcpy(ans[pEntry->idx][pEntry->val], strs[i]);
//            (*returnColumnSizes)[pEntry->idx]++;
//            pEntry->val++;
//        }
//    }
//
//    *returnSize = idx;
//    return ans;
//}
//
////1526. 形成目标数组的子数组最少增加次数
//
//int minNumberOperations(int* target, int targetSize)
//{
//    int ans = target[0];
//    for (int i = 1; i < targetSize; i++)
//    {
//        ans += fmax(0, target[i] - target[i - 1]);
//    }
//    return ans;
//}
//
