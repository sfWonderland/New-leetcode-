////2048. 下一个更大的数值平衡数
//
//int nextBeautifulNumber(int n)
//{
//    while (1)
//    {
//        n++;
//
//        int cnt[10] = { 0 };
//        for (int x = n; x > 0; x /= 10)
//        {
//            cnt[x % 10]++;
//        }
//
//        bool ok = true;
//        for (int x = n; x > 0; x /= 10)
//        {
//            if (cnt[x % 10] != x % 10)
//            {
//                ok = false;
//                break;
//            }
//        }
//        if (ok)
//            return n;
//    }
//    return 0;
//}
//
////318. 最大单词长度乘积
//
//int maxProduct(char** words, int wordsSize)
//{
//    int hash[wordsSize][2]; // bitHash & len
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int bitHash = 0, len = 0;
//        for (; words[i][len]; len++)
//        {
//            bitHash |= 1 << (words[i][len] - 'a');
//        }
//        hash[i][0] = bitHash;
//        hash[i][1] = len;
//    }
//    int ans = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        for (int j = i + 1; j < wordsSize; j++)
//        {
//            if (hash[i][0] & hash[j][0])
//                continue;
//
//            ans = fmax(ans, hash[i][1] * hash[j][1]);
//        }
//    }
//    return ans;
//}
//
////386. 字典序排数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* lexicalOrder(int n, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * n);
//    int num = 1;
//    for (int i = 0; i < n; i++)
//    {
//        ret[i] = num;
//
//        if (num * 10 <= n)
//            num *= 10;
//        else
//        {
//            while (num % 10 == 9 || num + 1 > n)
//                num /= 10;
//
//            num++;
//        }
//    }
//    *returnSize = n;
//    return ret;
//}
//
////429. N 叉树的层序遍历
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     int numChildren;
// *     struct Node** children;
// * };
// */
//
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    if (!root)
//    {
//        *returnColumnSizes = NULL;
//        return NULL;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * 1000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
//    struct Node* q[10000];
//    int i = 0, front = 0, rear = 0;
//    q[rear++] = root;
//    while (rear > front)
//    {
//        int len = rear - front;
//        ans[i] = (int*)malloc(sizeof(int) * len);
//        int start = front;
//        front = rear;
//        for (int n = start; n < front; n++)
//        {
//            struct Node* node = q[n];
//            ans[i][n - start] = node->val;
//            for (int j = 0; j < node->numChildren; j++)
//            {
//                q[rear++] = node->children[j];
//            }
//        }
//        (*returnColumnSizes)[i++] = len;
//    }
//
//    *returnSize = i;
//    return ans;
//}
//
