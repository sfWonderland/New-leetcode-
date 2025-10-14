////2598. 执行操作后的最大 MEX
//
//int findSmallestInteger(int* nums, int numsSize, int value)
//{
//    int cnt[value];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = ((nums[i] % value) + value) % value;
//        cnt[x]++;
//    }
//    int ans = 0;
//    while (cnt[ans % value]-- > 0)
//        ans++;
//    return ans;
//}
//
////面试题 08.07. 无重复字符串的排列组合
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
//char** ans;
//char* tmp;
//void dfs(char* s, int i, int n, int* ansSize, bool* path)
//{
//    if (i == n)
//    {
//        ans[*ansSize] = (char*)malloc(sizeof(char) * (n + 1));
//        tmp[i] = '\0';
//        strcpy(ans[*ansSize], tmp);
//        (*ansSize)++;
//        return;
//    }
//    for (int j = 0; j < n; j++)
//    {
//        if (path[j] == 0)
//        {
//            path[j] = 1;
//            tmp[i] = s[j];
//            dfs(s, i + 1, n, ansSize, path);
//            path[j] = 0;
//        }
//    }
//}
//char** permutation(char* S, int* returnSize)
//{
//    int n = strlen(S);
//    int m = 1, t = 2;
//    while (t <= n)
//    {
//        m *= t++;
//    }
//    ans = (char**)malloc(sizeof(char*) * m);
//    bool* path = (bool*)calloc(sizeof(bool), n);
//    tmp = (char*)malloc(sizeof(char) * (n + 1));
//    *returnSize = 0;
//    dfs(S, 0, n, returnSize, path);
//    return ans;
//}
//
////面试题 04.03. 特定深度节点链表
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
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
//  /**
//   * Note: The returned array must be malloced, assume caller calls free().
//   */
//int get_num(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return 1 + get_num(root->left) + get_num(root->right);
//}
//int get_depth(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return 1 + fmax(get_depth(root->left), get_depth(root->right));
//}
//struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize)
//{
//    int n = get_num(tree);
//    int depth = get_depth(tree);
//    struct ListNode** ans = (struct ListNode**)malloc(sizeof(struct ListNode*) * depth);
//    struct TreeNode* queue[n];
//    int top = 0, bottom = 0, m = 0;
//    queue[top++] = tree;
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        struct ListNode* pre = NULL;
//        for (int i = start; i < bottom; i++)
//        {
//            struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//            cur->val = queue[i]->val;
//            cur->next = NULL;
//            if (pre == NULL)
//            {
//                ans[m] = cur;
//                pre = cur;
//            }
//            else
//            {
//                pre->next = cur;
//                pre = cur;
//            }
//            if (queue[i]->left) queue[top++] = queue[i]->left;
//            if (queue[i]->right) queue[top++] = queue[i]->right;
//        }
//        m++;
//    }
//    *returnSize = depth;
//    return ans;
//}
//
////.
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** stringSequence(char* target, int* returnSize)
//{
//    int m = strlen(target), n = 0;
//    for (int i = 0; i < m; i++)
//    {
//        n += target[i] - 'a' + 1;
//    }
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    int idx = 0;
//    char* tmp = (char*)malloc(sizeof(char) * (m + 1));
//    tmp[0] = 'a';
//    tmp[1] = '\0';
//    ans[0] = (char*)malloc(sizeof(char) * 2);
//    strcpy(ans[0], tmp);
//    for (int i = 1; i < n; i++)
//    {
//        if (tmp[idx] != target[idx])
//            tmp[idx]++;
//        else
//        {
//            tmp[++idx] = 'a';
//            tmp[idx + 1] = '\0';
//        }
//        ans[i] = (char*)malloc(sizeof(char) * (idx + 2));
//        strcpy(ans[i], tmp);
//    }
//    *returnSize = n;
//    return ans;
//}
//
