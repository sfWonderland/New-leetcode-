////2432. 处理用时最长的那个任务的员工
//
//int hardestWorker(int n, int** logs, int logsSize, int* logsColSize)
//{
//    int ans = logs[0][0];
//    int period = logs[0][1];
//    for (int i = 1; i < logsSize; i++)
//    {
//        int t = logs[i][1] - logs[i - 1][1];
//        if (t > period)
//        {
//            ans = logs[i][0];
//            period = t;
//        }
//        else if (t == period && ans > logs[i][0])
//            ans = logs[i][0];
//    }
//    return ans;
//}
//
////2331. 计算布尔二叉树的值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool evaluateTree(struct TreeNode* root)
//{
//    if (root->val == 0)
//        return false;
//    else if (root->val == 1)
//        return true;
//    else if (root->val == 2)
//        return evaluateTree(root->left) | evaluateTree(root->right);
//    else
//        return evaluateTree(root->left) & evaluateTree(root->right);
//}
//
////2460. 对数组执行操作
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // int* applyOperations(int* nums, int numsSize, int* returnSize) 
// // {
// //     for(int i = 1; i < numsSize; i++)
// //     {
// //         if(nums[i] == nums[i - 1])
// //         {
// //             nums[i] = 0;
// //             nums[i - 1] *= 2;
// //         }
// //     }
// //     int left = 0;
// //     for(int i = 0; i < numsSize; i++)
// //     {
// //         if(nums[i])
// //         nums[left++] = nums[i];
// //     }
// //     while(left < numsSize)
// //     {
// //         nums[left++] = 0;
// //     }
// //     *returnSize = numsSize;
// //     return nums;
// // }
//int* applyOperations(int* nums, int numsSize, int* returnSize)
//{
//    for (int i = 0, j = 0; i < numsSize; i++)
//    {
//        if (i + 1 < numsSize && nums[i] == nums[i + 1])
//        {
//            nums[i] *= 2;
//            nums[i + 1] = 0;
//        }
//        if (nums[i])
//        {
//            int tmp = nums[i];
//            nums[i] = nums[j];
//            nums[j] = tmp;
//            j++;
//        }
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////2357. 使数组中所有元素都等于零
//
//int minimumOperations(int* nums, int numsSize)
//{
//    int hash[101] = { 0 };
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] && hash[nums[i]] == 0)
//        {
//            hash[nums[i]] = 1;
//            n++;
//        }
//    }
//    return n;
//}
//
