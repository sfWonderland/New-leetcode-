////93. 复原 IP 地址
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool isValid(char* s, int left, int right)
//{
//    int n = right - left;
//    if (n > 3 || (n > 1 && s[left] == '0'))
//        return false;
//    char tmp = s[right];
//    s[right] = '\0';
//    int x = atoi(s + left);
//    s[right] = tmp;
//    return x <= 255;
//}
//void substr(char* dest, int* idx, char* s, int left, int right)
//{
//    int i = *idx;
//    for (int t = left; t < right; t++)
//    {
//        dest[i++] = s[t];
//    }
//    *idx = i;
//}
//char** restoreIpAddresses(char* s, int* returnSize)
//{
//    int n = strlen(s);
//    char** ans = (char**)malloc(sizeof(char*) * 1000);
//    int ansSize = 0;
//
//    for (int i = 1; i < n && isValid(s, 0, i); i++)
//    {
//        for (int j = i + 1; j < n && isValid(s, i, j); j++)
//        {
//            for (int k = j + 1; k < n && isValid(s, j, k); k++)
//            {
//                if (isValid(s, k, n))
//                {
//                    ans[ansSize] = (char*)malloc(sizeof(char) * (n + 4));
//                    int idx = 0;
//                    substr(ans[ansSize], &idx, s, 0, i);
//                    ans[ansSize][idx++] = '.';
//                    substr(ans[ansSize], &idx, s, i, j);
//                    ans[ansSize][idx++] = '.';
//                    substr(ans[ansSize], &idx, s, j, k);
//                    ans[ansSize][idx++] = '.';
//                    substr(ans[ansSize], &idx, s, k, n);
//                    ans[ansSize++][idx] = '\0';
//                }
//            }
//        }
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////1048. 最长字符串链    
//
//int cmp(const void* e1, const void* e2)
//{
//    return strlen(*(char**)e1) - strlen(*(char**)e2);
//}
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int longestStrChain(char** words, int wordsSize)
//{
//    qsort(words, wordsSize, sizeof(char*), cmp);
//    HashItem* ws = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        p = (HashItem*)malloc(sizeof(HashItem));
//        p->key = words[i];
//        p->val = 0;
//        HASH_ADD_STR(ws, key, p);
//    }
//    int ans = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        char* s = words[i];
//        int res = 0;
//        HashItem* p1 = NULL;
//        HASH_FIND_STR(ws, s, p1);
//        int n = strlen(s);
//        char* t = (char*)malloc(sizeof(char) * n);
//        for (int i = 1; i < n; i++)
//        {
//            t[i - 1] = s[i];
//        }
//        t[n - 1] = '\0';
//        //printf("%s\n", s);
//        for (int i = 0; i < n; i++)
//        {
//            HashItem* p2 = NULL;
//            //printf("%s\n", t);
//            HASH_FIND_STR(ws, t, p2);
//            if (p2)
//                res = fmax(res, p2->val);
//            t[i] = s[i];
//        }
//        free(t);
//        p1->val = res + 1;
//        ans = fmax(ans, res + 1);
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, ws, p, tmp)
//    {
//        HASH_DEL(ws, p);
//        free(p);
//    }
//    return ans;
//}
//
////3855. 给定范围内 K 位数字之和
//
//const int MOD = 1e9 + 7;
//long long qPow(long long x, int n)
//{
//    long long res = 1;
//    while (n)
//    {
//        if (n & 1) res = res * x % MOD;
//        x = x * x % MOD;
//        n /= 2;
//    }
//    return res;
//}
//int sumOfNumbers(int l, int r, int k)
//{
//    int m = r - l + 1;
//    // 先选择一位数，比如在l = 0，r = 3 的情况下选定十位上的2；
//    // 则其他一位有（3 - 0 + 1）= 4共四种选法，共计4^2种选法，那么该位的贡献为20 * 4 ^ 2;
//    // 选择一个数，那就是其分别占据各位的情况，如还是选2，其贡献为222 * 4 ^ 2 = 2 * 111 * 4 ^ 2
//    // 再到所有数，其贡献就是（0 + 3）*（3 - 0 + 1）/ 2 * 111 * 4 ^ 2
//    // 111 可以写做 (10 ^ 3 - 1) / 9
//    // 所以总结得到以下公式
//    // (l + r) * m / 2 * (10 ^ k - 1) / 9 * m ^ (k - 1); 
//    // 涉及幂计算需要用到快速幂
//    return (l + r) * m * (qPow(10, k) - 1 + MOD) % MOD * qPow(18, MOD - 2) % MOD * qPow(m, k - 1) % MOD;
//}
//
////979. 在二叉树中分配硬币
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int distributeCoins(struct TreeNode* root)
//{
//    int ans = 0;
//    int dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return 0;
//
//        int d = dfs(node->left) + dfs(node->right) + node->val - 1;
//        ans += abs(d);
//        return d;
//    }
//    dfs(root);
//    return ans;
//}
//
