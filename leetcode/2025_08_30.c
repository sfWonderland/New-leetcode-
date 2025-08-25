////LCR 177. 撞色搭配
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* sockCollocation(int* sockets, int socketsSize, int* returnSize)
//{
//    int t = 0;
//    for (int i = 0; i < socketsSize; i++)
//        t ^= sockets[i];
//    //设两个只出现一次的数字为 x , y 
//    //由于 x != y ，则 x 和 y 二进制至少有一位不同
//    //根据此位可以将 sockets 拆分为分别包含 x 和 y 的两个子数组。
//    int k = 1;
//    while ((t & k) == 0)
//        k <<= 1;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = 0, ans[1] = 0;
//    for (int i = 0; i < socketsSize; i++)
//    {
//        if (sockets[i] & k)
//            ans[0] ^= sockets[i];
//        else
//            ans[1] ^= sockets[i];
//    }
//    *returnSize = 2;
//    return ans;
//}
//
////LCR 162. 数字 1 的个数
//
//int digitOneInNumber(int num)
//{
//    long long digit = 1;
//    int high = num / 10, cur = num % 10, low = 0;
//    int res = 0;
//    while (high != 0 || cur != 0)
//    {
//        if (cur == 0) res += high * digit;
//        else if (cur == 1) res += high * digit + low + 1;
//        else res += (high + 1) * digit;
//
//        low += cur * digit;
//        cur = high % 10;
//        high /= 10;
//        digit *= 10;
//    }
//    return res;
//}
//
////LCR 149. 彩灯装饰记录 I
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* decorateRecord(struct TreeNode* root, int* returnSize)
//{
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int* ans = (int*)malloc(sizeof(int) * 10000);
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
//    int top = 0, bottom = 0;
//    queue[top++] = root;
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        for (int i = start; i < bottom; i++)
//        {
//            ans[i] = queue[i]->val;
//            if (queue[i]->left) queue[top++] = queue[i]->left;
//            if (queue[i]->right) queue[top++] = queue[i]->right;
//        }
//    }
//    *returnSize = top;
//    return ans;
//}
//
////LCR 150. 彩灯装饰记录 II
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//int getDepth(struct TreeNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    return fmax(getDepth(node->left), getDepth(node->right)) + 1;
//}
//int** decorateRecord(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
//{
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int n = getDepth(root);
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
//    int top = 0, bottom = 0, idx = 0;
//    queue[top++] = root;
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        ans[idx] = (int*)malloc(sizeof(int) * 5000);
//        for (int i = start; i < bottom; i++)
//        {
//            ans[idx][i - start] = queue[i]->val;
//            if (queue[i]->left) queue[top++] = queue[i]->left;
//            if (queue[i]->right) queue[top++] = queue[i]->right;
//        }
//        (*returnColumnSizes)[idx++] = bottom - start;
//    }
//    *returnSize = n;
//    return ans;
//}
//
