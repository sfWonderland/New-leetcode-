////LCR 151. 彩灯装饰记录 III
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
//void reverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left++] = nums[right];
//        nums[right--] = tmp;
//    }
//}
//int** decorateRecord(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    if (root == NULL)
//        return NULL;
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
//    int** ans = (int**)malloc(sizeof(int*) * 10000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
//    int bottom = 0, top = 0;
//    queue[top++] = root;
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        ans[*returnSize] = (int*)malloc(sizeof(int) * (bottom - start));
//        for (int i = start; i < bottom; i++)
//        {
//            ans[*returnSize][i - start] = queue[i]->val;
//            if (queue[i]->left) queue[top++] = queue[i]->left;
//            if (queue[i]->right) queue[top++] = queue[i]->right;
//        }
//        if ((*returnSize) & 1)
//            reverse(ans[*returnSize], 0, bottom - start - 1);
//        (*returnColumnSizes)[(*returnSize)++] = bottom - start;
//    }
//    return ans;
//}
//
////LCR 174. 寻找二叉搜索树中的目标节点
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int get_nums(struct TreeNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    return get_nums(node->left) + get_nums(node->right) + 1;
//}
//void dfs(struct TreeNode* node, int* nums, int* i)
//{
//    if (!node->left && !node->right)
//    {
//        nums[(*i)++] = node->val;
//        return;
//    }
//    if (node->right) dfs(node->right, nums, i);
//    nums[(*i)++] = node->val;
//    if (node->left) dfs(node->left, nums, i);
//}
//int findTargetNode(struct TreeNode* root, int cnt)
//{
//    int n = get_nums(root);
//    int* nums = (int*)malloc(sizeof(int) * n);
//    int i = 0;
//    dfs(root, nums, &i);
//    return nums[cnt - 1];
//}
//
////6. Z 字形变换
//
//char* convert(char* s, int numRows)
//{
//    if (numRows == 1)
//        return s;
//    int n = strlen(s);
//    char* s1 = (char*)malloc(sizeof(char) * (n + 1));
//    int idx = 0, d = 2 * numRows - 2;
//    for (int i = 0; i < numRows; i++)
//    {
//        for (int j = i; j < n; j += d)
//        {
//            s1[idx++] = s[j];
//            //printf("%c ", s1[idx - 1]);
//            if (i != 0 && i != numRows - 1 && j + d - 2 * i < n)
//            {
//                s1[idx++] = s[j + d - 2 * i];
//                //printf("%c ", s1[idx - 1]);
//            }
//        }
//        //printf("\n");
//    }
//    s1[n] = '\0';
//    return s1;
//}
//
////637. 二叉树的层平均值
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
//double* averageOfLevels(struct TreeNode* root, int* returnSize)
//{
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
//    double* ans = (double*)malloc(sizeof(double) * 10000);
//    int idx = 0;
//    int bottom = 0, top = 0;
//    queue[top++] = root;
//    while (top > bottom)
//    {
//        int n = top - bottom;
//        long long sum = 0;
//        for (int i = 0; i < n; i++)
//        {
//            struct TreeNode* node = queue[bottom++];
//            sum += node->val;
//            if (node->left) queue[top++] = node->left;
//            if (node->right) queue[top++] = node->right;
//        }
//        ans[idx++] = 1.0 * sum / n;
//    }
//    *returnSize = idx;
//    return ans;
//}
//
