//// 3996. 偶数次骑士移动
//
//bool canReach(int* start, int startSize, int* target, int targetSize)
//{
//    return (start[0] + start[1]) % 2 == (target[0] + target[1]) % 2;
//}
//
//// 3997. 统计二叉树中支配节点的数量    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* ans)
//{
//    if (node == NULL)
//        return 0;
//    int left = dfs(node->left, ans);
//    int right = dfs(node->right, ans);
//    int max = fmax(right, left);
//    if (max > node->val)
//        return max;
//
//    (*ans)++;
//    return node->val;
//}
//int countDominantNodes(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
//// 3998. 使用子序列排序转换二进制字符串
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* transformStr(char* s, char** strs, int strsSize, int* returnSize)
//{
//    int n = strsSize;
//    int cnt0 = 0, cnt1 = 0, m = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] & 1)
//            cnt1++;
//        else
//            cnt0++;
//
//        m++;
//    }
//    bool* ans = (bool*)calloc(sizeof(int), n);
//    for (int i = 0; i < n; i++)
//    {
//        int count0 = 0, count1 = 0;
//        char* t = strs[i];
//        for (int j = 0; j < m; j++)
//        {
//            if (t[j] == '1')
//                count1++;
//            else if (t[j] == '0')
//                count0++;
//        }
//        if (count1 > cnt1 || count0 > cnt0)
//            continue;
//
//        int d1 = cnt1 - count1, chance = 0;
//        for (int j = m - 1; j >= 0; j--)
//        {
//            char c = t[j];
//            if (t[j] == '?')
//            {
//                if (d1 > 0)
//                {
//                    d1--;
//                    c = '1';
//                }
//                else
//                    c = '0';
//            }
//            if (s[j] > c)
//            {
//                chance--;
//                if (chance < 0)
//                    break;
//            }
//            else if (s[j] < c)
//                chance++;
//        }
//        if (chance >= 0)
//            ans[i] = true;
//    }
//    *returnSize = n;
//    return ans;
//}
//
//// 3999. 字符串变换后的最少分组数
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//
//void getMinRep(char* s, int n, char* out)
//{
//    int i = 0, j = 1, k = 0;
//    while (i < n && j < n && k < n)
//    {
//        char a = s[(i + k) % n];
//        char b = s[(j + k) % n];
//        if (a == b) k++;
//        else
//        {
//            if (a > b) i += k + 1;
//            else j += k + 1;
//
//            if (i == j) j++;
//            k = 0;
//        }
//    }
//
//    int start = i < j ? i : j;
//    for (int i = 0; i < n; i++)
//    {
//        out[i] = s[(i + start) % n];
//    }
//    out[n] = '\0';
//}
//int minimumGroups(char** words, int wordsSize)
//{
//    int n = wordsSize;
//    HashItem* groups = NULL;
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int m = strlen(words[i]);
//        char* even = (char*)malloc(sizeof(char) * (m / 2 + 1));
//        char* odd = (char*)malloc(sizeof(char) * ((m + 1) / 2 + 1));
//        even[m / 2] = '\0';
//        odd[(m + 1) / 2] = '\0';
//        int numE = 0, numO = 0;
//        for (int j = 0; j < m; j++)
//        {
//            if (j % 2) even[numE++] = words[i][j];
//            else odd[numO++] = words[i][j];
//        }
//        char* new_even = (char*)malloc(sizeof(char) * (numE + 1));
//        char* new_odd = (char*)malloc(sizeof(char) * (numO + 1));
//        getMinRep(even, numE, new_even);
//        getMinRep(odd, numO, new_odd);
//        char* s1 = (char*)malloc(sizeof(char) * (m + 2));
//        sprintf(s1, "%s#%s", new_even, new_odd);
//        HashItem* p1 = NULL;
//        HASH_FIND_STR(groups, s1, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = s1;
//            HASH_ADD_STR(groups, key, p1);
//            ans++;
//        }
//        else
//            free(s1);
//        free(even);
//        free(odd);
//        free(new_even);
//        free(new_odd);
//    }
//    HashItem* p0 = NULL, * tmp = NULL;
//    HASH_ITER(hh, groups, p0, tmp)
//    {
//        free(p0->key);
//        HASH_DEL(groups, p0);
//        free(p0);
//    }
//    return ans;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return strcmp(*(char**)e1, *(char**)e2);
//}
//void getMinRep(char* s, int n, char* out)
//{
//    int i = 0, j = 1, k = 0;
//    while (i < n && j < n && k < n)
//    {
//        char a = s[(i + k) % n];
//        char b = s[(j + k) % n];
//        if (a == b) k++;
//        else
//        {
//            if (a > b) i += k + 1;
//            else j += k + 1;
//
//            if (i == j) j++;
//            k = 0;
//        }
//    }
//
//    int start = i < j ? i : j;
//    for (int i = 0; i < n; i++)
//    {
//        out[i] = s[(i + start) % n];
//    }
//    out[n] = '\0';
//}
//int minimumGroups(char** words, int wordsSize)
//{
//    if (wordsSize == 0) return 0;
//    int n = wordsSize;
//    char** key_words = (char**)malloc(sizeof(char*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        int m = strlen(words[i]);
//        char* even = (char*)malloc(sizeof(char) * (m / 2 + 1));
//        char* odd = (char*)malloc(sizeof(char) * ((m + 1) / 2 + 1));
//        even[m / 2] = '\0';
//        odd[(m + 1) / 2] = '\0';
//        int numE = 0, numO = 0;
//        for (int j = 0; j < m; j++)
//        {
//            if (j % 2) even[numE++] = words[i][j];
//            else odd[numO++] = words[i][j];
//        }
//        char* new_even = (char*)malloc(sizeof(char) * (numE + 1));
//        char* new_odd = (char*)malloc(sizeof(char) * (numO + 1));
//        getMinRep(even, numE, new_even);
//        getMinRep(odd, numO, new_odd);
//        key_words[i] = (char*)malloc(sizeof(char) * (m + 2));
//        sprintf(key_words[i], "%s#%s", new_even, new_odd);
//        free(even);
//        free(odd);
//        free(new_even);
//        free(new_odd);
//    }
//    qsort(key_words, n, sizeof(char*), cmp);
//    int ans = 1;
//    for (int i = 1; i < n; i++)
//    {
//        if (strcmp(key_words[i - 1], key_words[i]))
//            ans++;
//        free(key_words[i - 1]);
//    }
//    free(key_words[n - 1]);
//    free(key_words);
//    return ans;
//}
//
