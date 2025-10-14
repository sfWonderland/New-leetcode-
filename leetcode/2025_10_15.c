////804. 唯一摩尔斯密码词
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//const static char* morse[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
//int uniqueMorseRepresentations(char** words, int wordsSize)
//{
//    HashItem* hash = NULL;
//    HashItem* tmp = NULL;
//    int ans = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        char* s = (char*)malloc(sizeof(char) * 49);
//        strcpy(s, morse[words[i][0] - 'a']);
//        for (int j = 1; words[i][j]; j++)
//        {
//            strcat(s, morse[words[i][j] - 'a']);
//        }
//        HASH_FIND_STR(hash, s, tmp);
//        if (tmp == NULL)
//        {
//            HashItem* tmp = (HashItem*)malloc(sizeof(HashItem));
//            tmp->key = (char*)malloc(sizeof(char) * 49);
//            strcpy(tmp->key, s);
//            HASH_ADD_STR(hash, key, tmp);
//            ans++;
//        }
//    }
//    return ans;
//}
//
////面试题 08.04. 幂集
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** ans;
//int ansSize;
//int* len;
//int size;
//int* path;
//void dfs(int* nums, int numsSize, int i)
//{
//    ans[ansSize] = (int*)malloc(sizeof(int) * size);
//    memcpy(ans[ansSize], path, sizeof(int) * size);
//    len[ansSize++] = size;
//    for (int j = i; j < numsSize; j++)
//    {
//        path[size++] = nums[j];
//        dfs(nums, numsSize, j + 1);
//        size--;
//    }
//}
//int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = 1 << numsSize;
//    printf("%d ", n);
//    ans = (int**)malloc(sizeof(int*) * n);
//    path = (int*)malloc(sizeof(int) * numsSize);
//    size = 0;
//    len = (int*)malloc(sizeof(int) * n);
//    ansSize = 0;
//    dfs(nums, numsSize, 0);
//    *returnSize = ansSize;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        (*returnColumnSizes)[i] = len[i];
//    }
//    return ans;
//}
//
////LCR 080. 组合
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** ans;
//int ansSize;
//int* len;
//int size;
//int* path;
//void dfs(int i, int n, int k)
//{
//    if (size == k)
//    {
//        ans[ansSize] = (int*)malloc(sizeof(int) * size);
//        memcpy(ans[ansSize], path, sizeof(int) * size);
//        len[ansSize++] = size;
//        return;
//    }
//    for (int j = i; j <= n; j++)
//    {
//        path[size++] = j;
//        dfs(j + 1, n, k);
//        size--;
//    }
//}
//int combo(int n, int k)
//{
//    long long a = 1, b = 1;
//    while (k)
//    {
//        a = a * n;
//        b = b * k;
//        n--;
//        k--;
//    }
//    return a / b;
//}
//int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
//{
//    int m = combo(n, k);
//    printf("%d ", m);
//    ans = (int**)malloc(sizeof(int*) * m);
//    path = (int*)malloc(sizeof(int) * k);
//    size = 0;
//    len = (int*)malloc(sizeof(int) * m);
//    ansSize = 0;
//    dfs(1, n, k);
//    *returnSize = ansSize;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        (*returnColumnSizes)[i] = len[i];
//    }
//    return ans;
//}
//
////LCP 66. 最小展台数量
//
//int minNumBooths(char** demand, int demandSize)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; i < demandSize; i++)
//    {
//        int tmp[26] = { 0 };
//        for (int j = 0; demand[i][j]; j++)
//        {
//            tmp[demand[i][j] - 'a']++;
//            cnt[demand[i][j] - 'a'] = fmax(cnt[demand[i][j] - 'a'], tmp[demand[i][j] - 'a']);
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        ans += cnt[i];
//    }
//    return ans;
//}
//
