//// LCR 036. 逆波兰表达式求值
//
//int evalRPN(char** tokens, int tokensSize)
//{
//    int n = tokensSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (tokens[i][0] >= '0' || tokens[i][1] >= '0')
//        {
//            int x = atoi(tokens[i]);
//            st[top++] = x;
//        }
//        else
//        {
//            char sym = tokens[i][0];
//            top--;
//            if (sym == '*')
//                st[top - 1] *= st[top];
//            else if (sym == '/')
//                st[top - 1] /= st[top];
//            else if (sym == '+')
//                st[top - 1] += st[top];
//            else
//                st[top - 1] -= st[top];
//        }
//        // for(int j = 0; j < top; j++)
//        // {
//        //     printf("%d ", st[j]);
//        // }
//        // printf("\n");
//    }
//    return st[0];
//}
//
//// 面试题 17.12. BiNode    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* cur;
//void dfs(struct TreeNode* node)
//{
//    if (node == NULL)
//        return;
//
//    dfs(node->left);
//    cur->right = node;
//    node->left = NULL;
//    cur = node;
//    dfs(node->right);
//}
//struct TreeNode* convertBiNode(struct TreeNode* root)
//{
//    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    dummy->right = dummy->left = NULL;
//    cur = dummy;
//    dfs(root);
//    return dummy->right;
//}
//
//// 面试题 17.14. 最小K个数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j])
//            j++;
//
//        if (heap[j] < x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//void push(int* heap, int* i, int x)
//{
//    heap[*i] = x;
//    up(heap, (*i)++);
//}
//void pop(int* heap, int n, int x)
//{
//    heap[0] = x;
//    down(heap, 0, n);
//}
//int* smallestK(int* arr, int arrSize, int k, int* returnSize)
//{
//    if (k == 0)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int* heap = (int*)malloc(sizeof(int) * k);
//    int j = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        if (i < k)
//            push(heap, &j, arr[i]);
//        else if (arr[i] < heap[0])
//            pop(heap, k, arr[i]);
//    }
//    *returnSize = k;
//    return heap;
//}
//
//// 面试题 17.16. 按摩师
//
//int massage(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//        return 0;
//    if (numsSize == 1)
//        return nums[0];
//    int n = numsSize;
//    int f[n];
//    f[0] = nums[0], f[1] = fmax(nums[0], nums[1]);
//    for (int i = 2; i < n; i++)
//    {
//        f[i] = fmax(f[i - 1], f[i - 2] + nums[i]);
//    }
//    return f[n - 1];
//}
//
