////884. 两句话中的不常见单词
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
//char** uncommonFromSentences(char* s1, char* s2, int* returnSize)
//{
//    HashItem* words = NULL;
//    HashItem* pEntry = NULL;
//    int m = 0;
//    for (char* s = strtok(s1, " "); s; s = strtok(NULL, " "))
//    {
//        HASH_FIND_STR(words, s, pEntry);
//        if (pEntry == NULL)
//        {
//            int n = strlen(s);
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * (n + 1));
//            memcpy(pEntry->key, s, sizeof(char) * n);
//            pEntry->val = 0;
//            pEntry->key[n] = '\0';
//            HASH_ADD_STR(words, key, pEntry);
//            m++;
//        }
//        else
//            pEntry->val = 1;
//    }
//    for (char* s = strtok(s2, " "); s; s = strtok(NULL, " "))
//    {
//        HASH_FIND_STR(words, s, pEntry);
//        if (pEntry == NULL)
//        {
//            int n = strlen(s);
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * (n + 1));
//            memcpy(pEntry->key, s, sizeof(char) * n);
//            pEntry->val = 2;
//            pEntry->key[n] = '\0';
//            HASH_ADD_STR(words, key, pEntry);
//            m++;
//        }
//        else if (pEntry->val < 2)
//            pEntry->val = 3;
//        else
//            pEntry->val = 5;
//    }
//    char** ans = (char**)malloc(sizeof(char*) * m);
//    int k = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, words, pEntry, tmp)
//    {
//        if (pEntry->val % 2 == 0)
//        {
//            int n = strlen(pEntry->key);
//            ans[k] = (char*)malloc(sizeof(char) * (n + 1));
//            memcpy(ans[k], pEntry->key, sizeof(char) * n);
//            ans[k][n] = '\0';
//            k++;
//        }
//    }
//    *returnSize = k;
//    return ans;
//}
//
////819. 最常见的单词
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//void toLegal(char* s)
//{
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] < 'a')
//            s[i] += 32;
//    }
//}
//char* mostCommonWord(char* paragraph, char** banned, int bannedSize)
//{
//    HashItem* words = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < bannedSize; i++)
//    {
//        int n = strlen(banned[i]);
//        pEntry = (HashItem*)malloc(sizeof(HashItem));
//        pEntry->key = (char*)malloc(sizeof(char) * (n + 1));
//        memcpy(pEntry->key, banned[i], sizeof(char) * n);
//        pEntry->val = 0;
//        pEntry->key[n] = '\0';
//        HASH_ADD_STR(words, key, pEntry);
//    }
//    int max = 0;
//    char* ans = (char*)malloc(sizeof(char) * 100);
//    for (char* s = strtok(paragraph, " !?',;."); s; s = strtok(NULL, " !?',;."))
//    {
//        toLegal(s);
//        int n = strlen(s);
//        HASH_FIND_STR(words, s, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * (n + 1));
//            memcpy(pEntry->key, s, sizeof(char) * n);
//            pEntry->val = 1;
//            pEntry->key[n] = '\0';
//            HASH_ADD_STR(words, key, pEntry);
//        }
//        else if (pEntry->val)
//        {
//            pEntry->val++;
//        }
//
//        if (max < pEntry->val)
//        {
//            max = pEntry->val;
//            memcpy(ans, pEntry->key, sizeof(char) * n);
//            ans[n] = '\0';
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, words, pEntry, tmp)
//    {
//        free(pEntry->key);
//        free(pEntry);
//    }
//    return ans;
//}
//
////888. 公平的糖果交换
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize)
//{
//    int diff = 0;
//    for (int i = 0; i < aliceSizesSize; i++)
//    {
//        diff += aliceSizes[i];
//    }
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < bobSizesSize; i++)
//    {
//        diff -= bobSizes[i];
//        HASH_FIND_INT(hash, &bobSizes[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = bobSizes[i];
//            HASH_ADD_INT(hash, key, pEntry);
//        }
//    }
//    diff /= 2;
//
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < aliceSizesSize; i++)
//    {
//        int x = aliceSizes[i] - diff;
//        HASH_FIND_INT(hash, &x, pEntry);
//        if (pEntry)
//        {
//            ans[0] = aliceSizes[i];
//            ans[1] = x;
//            break;
//        }
//    }
//    *returnSize = 2;
//    return ans;
//}
//
////401. 二进制手表
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//const int hours[12] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3 };
//const int minutes[60] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4,5, 3, 4, 4, 5 };
//char** readBinaryWatch(int turnedOn, int* returnSize)
//{
//    *returnSize = 0;
//    if (turnedOn > 8)
//        return NULL;
//
//    char** ans = (char**)malloc(sizeof(char*) * 200);
//    int k = 0;
//    for (int h = 0; h < 12; h++)
//    {
//        for (int m = 0; m < 60; m++)
//        {
//            int n = minutes[m] + hours[h];
//            if (n == turnedOn)
//            {
//                ans[k] = (char*)malloc(sizeof(char) * 6);
//                sprintf(ans[k], "%d:%02d", h, m);
//                k++;
//            }
//        }
//    }
//    *returnSize = k;
//    return ans;
//}
//
