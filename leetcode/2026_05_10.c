//// 101061. 连接逆序数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* concatWithReverse(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize * 2);
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans[i] = nums[i];
//        ans[2 * numsSize - 1 - i] = nums[i];
//    }
//    *returnSize = 2 * numsSize;
//    return ans;
//}
//
//// 101055. 有效单词计数    
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
//int* countWordOccurrences(char** chunks, int chunksSize, char** queries, int queriesSize, int* returnSize)
//{
//    char s[100001];
//    s[0] = '\0';
//    char* p1 = s;
//    for (int i = 0; i < chunksSize; i++)
//    {
//        int m = strlen(chunks[i]);
//        strcpy(p1, chunks[i]);
//        p1 += m;
//    }
//    int n = strlen(s);
//    int i = 0;
//    while (i < n && s[i] < 'a')
//    {
//        s[i++] = ' ';
//    }
//    int j = n - 1;
//    while (j > i && s[j] < 'a')
//    {
//        s[j--] = ' ';
//    }
//    while (i < j)
//    {
//        while (i < j && s[i] >= 'a')
//            i++;
//        while (i < j && s[i + 1] < 'a')
//            s[i++] = ' ';
//        if (s[i - 1] < 'a')
//            s[i] = ' ';
//        i++;
//    }
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    for (char* p = strtok(s, " "); p; p = strtok(NULL, " "))
//    {
//        HASH_FIND_STR(cnt, p, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = p;
//            pEntry->val = 0;
//            HASH_ADD_STR(cnt, key, pEntry);
//        }
//        pEntry->val++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        HASH_FIND_STR(cnt, queries[i], pEntry);
//        if (pEntry)
//            ans[i] = pEntry->val;
//        else
//            ans[i] = 0;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        HASH_DEL(cnt, pEntry);
//        free(pEntry);
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
//// 101063. 可整除替换后的数组最小元素和
//
//long long minArraySum(int* nums, int numsSize)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = max < nums[i] ? nums[i] : max;
//    }
//    int* values = (int*)malloc(sizeof(int) * (max + 1));
//    memset(values, 0x3f, sizeof(int) * (max + 1));
//    for (int i = 0; i < numsSize; i++)
//    {
//        values[nums[i]] = nums[i];
//    }
//    for (int i = 1; i < max; i++)
//    {
//        if (values[i] == 0x3f3f3f3f)
//            continue;
//
//        for (int j = 2 * i; j <= max; j += i)
//        {
//            if (values[j] > i)
//                values[j] = i;
//        }
//    }
//    long long ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans += values[nums[i]];
//    }
//    free(values);
//    return ans;
//}
//
//// 面试题 04.05. 合法二叉搜索树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* node, long long left, long long right)
//{
//    if (node == NULL)
//        return true;
//    int x = node->val;
//    if (x < left || x > right)
//        return false;
//
//    return dfs(node->left, left, x - 1ll) && dfs(node->right, x + 1ll, right);
//}
//bool isValidBST(struct TreeNode* root)
//{
//    return dfs(root, INT_MIN, INT_MAX);
//}
//
