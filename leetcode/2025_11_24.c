////1680. 连接连续二进制数字
//
//int countBit(int x)
//{
//    int ret = 0;
//    while (x)
//    {
//        x >>= 1;
//        ret++;
//    }
//    return ret;
//}
//const int mod = 1e9 + 7;
//int concatenatedBinary(int n)
//{
//    int ans = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        ans = ((1ll * ans << countBit(i)) + i) % mod;
//    }
//    return ans;
//}
//
//const int mod = 1e9 + 7;
//int concatenatedBinary(int n)
//{
//    int ans = 0, shift = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        if ((i & (i - 1)) == 0)
//            shift++;
//
//        ans = ((1ll * ans << shift) | i) % mod;
//    }
//    return ans;
//}
//
////1261. 在受污染的二叉树中查找元素
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//typedef struct
//{
//    struct TreeNode* root;
//} FindElements;
//
//FindElements* findElementsCreate(struct TreeNode* root)
//{
//    FindElements* obj = (FindElements*)malloc(sizeof(FindElements));
//    obj->root = root;
//    return obj;
//}
//
//bool findElementsFind(FindElements* obj, int target)
//{
//    target++;
//    struct TreeNode* cur = obj->root;
//    for (int i = 30 - __builtin_clz(target); i >= 0; i--)
//    {
//        int bit = target >> i & 1;
//        cur = bit ? cur->right : cur->left;
//        if (cur == NULL)
//            return false;
//    }
//    return true;
//}
//
//void findElementsFree(FindElements* obj)
//{
//    free(obj);
//}
//
///**
// * Your FindElements struct will be instantiated and called as such:
// * FindElements* obj = findElementsCreate(root);
// * bool param_1 = findElementsFind(obj, target);
//
// * findElementsFree(obj);
//*/
//
////89. 格雷编码
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* grayCode(int n, int* returnSize)
//{
//    int m = 1 << n;
//    int* ans = (int*)malloc(sizeof(int) * m);
//    int size = 0;
//    ans[size++] = 0;
//    int head = 1;
//    for (int i = 0; i < n; i++)
//    {
//        int t = size;
//        for (int j = t - 1; j >= 0; j--)
//        {
//            ans[size++] = head + ans[j];
//        }
//        head <<= 1;
//    }
//    *returnSize = m;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int gray(int n)
//{
//    return n ^ (n >> 1);
//}
//int* grayCode(int n, int* returnSize)
//{
//    int m = 1 << n;
//    int* ans = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = gray(i);
//    }
//    *returnSize = m;
//    return ans;
//}
//
////1170. 比较字符串最小字母出现频次
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int f(char* s)
//{
//    char x = 'z';
//    int ret = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] < x)
//        {
//            x = s[i];
//            ret = 1;
//        }
//        else if (s[i] == x)
//            ret++;
//    }
//    return ret;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int binarySearch(int* nums, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] > x)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return left;
//}
//int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize)
//{
//    int n = wordsSize;
//    int nums[n];
//    for (int i = 0; i < n; i++)
//    {
//        nums[i] = f(words[i]);
//    }
//    qsort(nums, n, sizeof(int), cmp);
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        ans[i] = binarySearch(nums, n, f(queries[i]));
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
