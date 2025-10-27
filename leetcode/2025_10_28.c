////3354. 使数组元素等于零
//
//int countValidSelections(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > 0)
//            sum += nums[i];
//    }
//    int pre = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > 0)
//            pre += nums[i];
//        else if (nums[i] == 0)
//        {
//            int t = sum - pre * 2;
//            if (abs(t) == 0)
//                ans += 2;
//            else if (abs(t) == 1)
//                ans++;
//        }
//    }
//    return ans;
//}
//
////2149. 按符号重排数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* rearrangeArray(int* nums, int numsSize, int* returnSize)
//{
//    int p1 = 0, p2 = 1;
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > 0)
//        {
//            ans[p1] = nums[i];
//            p1 += 2;
//        }
//        else
//        {
//            ans[p2] = nums[i];
//            p2 += 2;
//        }
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
////LCR 045. 找树左下角的值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* root, int depth, int* max, int* ans)
//{
//    if (root == NULL)
//        return;
//
//    dfs(root->left, depth + 1, max, ans);
//    if (*max < depth)
//    {
//        *max = depth;
//        *ans = root->val;
//    }
//    dfs(root->right, depth + 1, max, ans);
//}
//
//int findBottomLeftValue(struct TreeNode* root)
//{
//    int ans = 0, max = -1;
//    dfs(root, 0, &max, &ans);
//    return ans;
//}
//
////589. N 叉树的前序遍历
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
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//void dfs(struct Node* root, int* ans, int* n)
//{
//    if (root == NULL)
//        return;
//
//    ans[(*n)++] = root->val;
//    for (int i = 0; i < root->numChildren; i++)
//    {
//        dfs(root->children[i], ans, n);
//    }
//}
//int* preorder(struct Node* root, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 10000);
//    int n = 0;
//    dfs(root, ans, &n);
//    *returnSize = n;
//    return ans;
//}
//
