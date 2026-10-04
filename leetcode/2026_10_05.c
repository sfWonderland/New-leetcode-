//// 606. 根据二叉树创建字符串
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void pushInt(char** s, int x, int* size, int* capacity)
//{
//    if (x == 0)
//    {
//        (*s)[(*size)++] = '0';
//        if (*size >= *capacity)
//        {
//            (*capacity) *= 2;
//            *s = (char*)realloc(*s, sizeof(char) * (*capacity));
//        }
//        return;
//    }
//    if (x < 0)
//    {
//        (*s)[(*size)++] = '-';
//        if (*size >= *capacity)
//        {
//            (*capacity) *= 2;
//            *s = (char*)realloc(*s, sizeof(char) * (*capacity));
//        }
//        x = -x;
//    }
//    int base = 1000;
//    while (base > x)
//        base /= 10;
//    while (base)
//    {
//        int y = x / base;
//        (*s)[(*size)++] = y + '0';
//        if (*size >= *capacity)
//        {
//            (*capacity) *= 2;
//            *s = (char*)realloc(*s, sizeof(char) * (*capacity));
//        }
//        x -= base * y;
//        base /= 10;
//    }
//}
//void dfs(struct TreeNode* node, char** s, int* size, int* capacity)
//{
//    if (node == NULL) return;
//    pushInt(s, node->val, size, capacity);
//    if (!node->left && !node->right)
//        return;
//    (*s)[(*size)++] = '(';
//    if (*size >= *capacity)
//    {
//        (*capacity) *= 2;
//        *s = (char*)realloc(*s, sizeof(char) * (*capacity));
//    }
//    dfs(node->left, s, size, capacity);
//    (*s)[(*size)++] = ')';
//    if (*size >= *capacity)
//    {
//        (*capacity) *= 2;
//        *s = (char*)realloc(*s, sizeof(char) * (*capacity));
//    }
//    if (node->right)
//    {
//        (*s)[(*size)++] = '(';
//        if (*size >= *capacity)
//        {
//            (*capacity) *= 2;
//            *s = (char*)realloc(*s, sizeof(char) * (*capacity));
//        }
//        dfs(node->right, s, size, capacity);
//        (*s)[(*size)++] = ')';
//        if (*size >= *capacity)
//        {
//            (*capacity) *= 2;
//            *s = (char*)realloc(*s, sizeof(char) * (*capacity));
//        }
//    }
//}
//char* tree2str(struct TreeNode* root)
//{
//    int capacity = 64;
//    char* ans = (char*)malloc(sizeof(char) * capacity);
//    int size = 0;
//    dfs(root, &ans, &size, &capacity);
//    ans[size] = '\0';
//    return ans;
//}
//
//// 2265. 统计值等于子树平均值的节点数   
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* cntA)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, cntA);
//    int right = dfs(node->right, cntA);
//    int sum = left / 1001 + right / 1001 + node->val;
//    int cnt = left % 1001 + right % 1001 + 1;
//    if (sum / cnt == node->val) (*cntA)++;
//    return sum * 1001 + cnt;
//}
//int averageOfSubtree(struct TreeNode* root)
//{
//    int cntA = 0;
//    dfs(root, &cntA);
//    return cntA;
//}
//
//// 1026. 节点与其祖先之间的最大差值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* node, int mx, int mn, int* dMax)
//{
//    if (node == NULL)
//    {
//        *dMax = *dMax > mx - mn ? *dMax : mx - mn;
//        return;
//    }
//    mx = mx > node->val ? mx : node->val;
//    mn = mn < node->val ? mn : node->val;
//    dfs(node->left, mx, mn, dMax);
//    dfs(node->right, mx, mn, dMax);
//}
//int maxAncestorDiff(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, INT_MIN, INT_MAX, &ans);
//    return ans;
//}
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dMax;
//void dfs(struct TreeNode* node, int mx, int mn)
//{
//    if (node == NULL)
//    {
//        dMax = dMax > mx - mn ? dMax : mx - mn;
//        return;
//    }
//    mx = mx > node->val ? mx : node->val;
//    mn = mn < node->val ? mn : node->val;
//    dfs(node->left, mx, mn);
//    dfs(node->right, mx, mn);
//}
//int maxAncestorDiff(struct TreeNode* root)
//{
//    dMax = 0;
//    dfs(root, INT_MIN, INT_MAX);
//    return dMax;
//}
//
//// 3319. 第 K 大的完美二叉子树的大小
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; ; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x) break;
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0) break;
//    }
//    heap[i] = x;
//}
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//        if (heap[j] >= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//void push(int* heap, int x, int* heapSize, int n)
//{
//    if (*heapSize < n)
//    {
//        heap[*heapSize] = x;
//        up(heap, (*heapSize)++);
//    }
//    else if (x > heap[0])
//    {
//        heap[0] = x;
//        down(heap, 0, n);
//    }
//}
//int dfs(struct TreeNode* node, int* heap, int* heapSize, int n)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, heap, heapSize, n);
//    int right = dfs(node->right, heap, heapSize, n);
//    if (left == -1 || left != right)
//        return -1;
//    int sum = left + right + 1;
//    push(heap, sum, heapSize, n);
//    return sum;
//}
//int kthLargestPerfectSubtree(struct TreeNode* root, int k)
//{
//    int* heap = (int*)malloc(sizeof(int) * k);
//    int heapSize = 0;
//    dfs(root, heap, &heapSize, k);
//    return heapSize == k ? heap[0] : -1;
//}
//
