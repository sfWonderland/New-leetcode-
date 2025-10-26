////面试题 16.02. 单词频率
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//} WordsFrequency;
//
//
//WordsFrequency* wordsFrequencyCreate(char** book, int bookSize)
//{
//    WordsFrequency* obj = NULL;
//    WordsFrequency* tmp = NULL;
//    for (int i = 0; i < bookSize; i++)
//    {
//        HASH_FIND_STR(obj, book[i], tmp);
//        if (tmp == NULL)
//        {
//            tmp = (WordsFrequency*)malloc(sizeof(WordsFrequency));
//            tmp->key = book[i];
//            tmp->val = 1;
//            HASH_ADD_STR(obj, key, tmp);
//        }
//        else
//            tmp->val++;
//    }
//    return obj;
//}
//
//int wordsFrequencyGet(WordsFrequency* obj, char* word)
//{
//    WordsFrequency* tmp = NULL;
//    HASH_FIND_STR(obj, word, tmp);
//    if (tmp)
//        return tmp->val;
//    else
//        return 0;
//}
//
//void wordsFrequencyFree(WordsFrequency* obj)
//{
//    WordsFrequency* pEntry = NULL;
//    WordsFrequency* tmp = NULL;
//    HASH_ITER(hh, obj, pEntry, tmp)
//    {
//        HASH_DEL(obj, pEntry);
//        free(pEntry);
//    }
//}
//
///**
// * Your WordsFrequency struct will be instantiated and called as such:
// * WordsFrequency* obj = wordsFrequencyCreate(book, bookSize);
// * int param_1 = wordsFrequencyGet(obj, word);
//
// * wordsFrequencyFree(obj);
//*/
//
////LCR 091. 粉刷房子
//
//int minCost(int** costs, int costsSize, int* costsColSize)
//{
//    int n = costsSize;
//    int f[n + 1][3];
//    memset(f[0], 0, sizeof(f[0]));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            int a = (j + 1) % 3;
//            int b = (j + 2) % 3;
//            f[i + 1][j] = fmin(f[i][a] + costs[i][a], f[i][b] + costs[i][b]);
//        }
//    }
//    return fmin(f[n][0], fmin(f[n][1], f[n][2]));
//}
//
//int minCost(int** costs, int costsSize, int* costsColSize)
//{
//    int n = costsSize;
//    int f[2][3];
//    memset(f[0], 0, sizeof(f[0]));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            int a = (j + 1) % 3;
//            int b = (j + 2) % 3;
//            f[(i + 1) % 2][j] = fmin(f[i % 2][a] + costs[i][a], f[i % 2][b] + costs[i][b]);
//        }
//    }
//    return fmin(f[n % 2][0], fmin(f[n % 2][1], f[n % 2][2]));
//}
//
////1823. 找出游戏的获胜者
//
//int findTheWinner(int n, int k)
//{
//    int ans = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        ans = (ans + k) % i;
//    }
//    return ans + 1;
//}
//
////347. 前 K 个高频元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int cmp_s(const void* e1, const void* e2)
//{
//    return (*(HashItem*)e2).val - (*(HashItem*)e1).val;
//}
//int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    HashItem cnt[numsSize];
//    int idx = 0;
//    cnt[idx].key = nums[0];
//    cnt[idx].val = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i - 1] == nums[i])
//            cnt[idx].val++;
//        else
//        {
//            cnt[++idx].key = nums[i];
//            cnt[idx].val = 1;
//        }
//    }
//    qsort(cnt, idx + 1, sizeof(HashItem), cmp_s);
//    int* ans = (int*)malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//    {
//        ans[i] = cnt[i].key;
//    }
//    *returnSize = k;
//    return ans;
//}
//
