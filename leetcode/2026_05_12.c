//// 面试题 04.12. 求和路径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//typedef struct
//{
//    long long key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int pathSum(struct TreeNode* root, int sum)
//{
//    HashItem* prefix = NULL;
//    HashItem* p1 = (HashItem*)malloc(sizeof(HashItem));
//    p1->key = 0;
//    p1->val = 1;
//    HASH_ADD(hh, prefix, key, sizeof(long long), p1);
//    int dfs(struct TreeNode* node, long long curr, int sum)
//    {
//        if (node == NULL)
//            return 0;
//
//        int res = 0;
//        curr += node->val;
//        long long x = curr - sum;
//        HashItem* p2 = NULL;
//        HASH_FIND(hh, prefix, &x, sizeof(long long), p2);
//        if (p2 && p2->val)
//            res += p2->val;
//
//        HASH_FIND(hh, prefix, &curr, sizeof(long long), p2);
//        if (p2 == NULL)
//        {
//            p2 = (HashItem*)malloc(sizeof(HashItem));
//            p2->key = curr;
//            p2->val = 0;
//            HASH_ADD(hh, prefix, key, sizeof(long long), p2);
//        }
//        p2->val++;
//        res += dfs(node->left, curr, sum);
//        res += dfs(node->right, curr, sum);
//        p2->val--;
//
//        return res;
//    }
//    int ans = dfs(root, 0, sum);
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, prefix, p1, tmp)
//    {
//        HASH_DEL(prefix, p1);
//        free(p1);
//    }
//    return ans;
//}
//
//// 面试题 05.04. 下一个数  
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // 规律：
// // 找大：（后面必须有1）末0找最近后1交换，升位其他1后移
// // 找小：末0找最近前1交换，降位1提前
// // 特例：占据最大正二进制位，且0都在1后面的数无大，1后没有0无小
//int get_max(int num, int t, int n)
//{
//    num &= 0x7fffffff - (1 << (t + 1)) + 1;
//    int a = 1 << t;
//    n--;
//    int b = (1 << n) - 1;
//    return num | a | b;
//}
//int get_min(int num, int t, int n)
//{
//    int tmp = n;
//    while (t < 31 && ((num >> t) & 1) == 0)
//        t++;
//
//    if (t < 31)
//        num &= 0x7fffffff - (1 << (t + 1)) + 1;
//    else
//        num = 0;
//
//    n++;
//    int left = (1 << n) - 1;
//    int m = t - n;
//    return num | (left << m);
//}
//int* findClosedNumbers(int num, int* returnSize)
//{
//    int t = 0;
//    int min = INT_MIN, max = INT_MIN;
//    while (t < 31 && ((num >> t) & 1) == 0)
//        t++;
//    if (t != 0)
//        min = num - (1 << (t - 1));
//
//    int m = t;
//    while (t < 31 && ((num >> t) & 1))
//        t++;
//
//    max = t == 31 ? -1 : get_max(num, t, t - m);
//    if (min == INT_MIN)
//        min = t == 31 || (1 << t) > num ? -1 : get_min(num, t, t - m);
//
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = max; ans[1] = min;
//    *returnSize = 2;
//    return ans;
//}
//
//// 面试题 05.07. 配对交换
//
//int exchangeBits(int num)
//{
//    int a = num & 0x55555555;
//    int b = num & 0xaaaaaaaa;
//    return (a << 1) | (b >> 1);
//}
//
//// 面试题 05.08. 绘制直线
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int get_num(int x1, int x2)
//{
//    int n = x2 - x1;
//    x2 %= 32;
//    int last = (32 - x2) % 32;
//    // printf("%d %d\n", last, n);
//    unsigned int x = 1;
//    return ((x << n) - 1) << last;
//}
//int* drawLine(int length, int w, int x1, int x2, int y, int* returnSize)
//{
//    int n = w / 32;
//    int* ans = (int*)malloc(sizeof(int) * length);
//    memset(ans, 0, sizeof(int) * length);
//    for (int i = y * n; i < (y + 1)* n; i++)
//    {
//        // printf("%d ", i);
//        int j = i % n;
//        if (x1 > j * 32 + 31 || x2 < j * 32)
//            ans[i] = 0;
//        else
//        {
//            x1 = fmax(x1, j * 32);
//            int x = fmin((j + 1) * 32, x2 + 1);
//            // printf("%d %d\n", x1, x);
//            ans[i] = x - x1 > 31 ? -1 : get_num(x1, x);
//        }
//    }
//    *returnSize = length;
//    return ans;
//}
//
