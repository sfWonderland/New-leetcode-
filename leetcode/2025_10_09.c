////3494. 酿造药水需要的最少总时间
//
//long long minTime(int* skill, int skillSize, int* mana, int manaSize)
//{
//    int n = skillSize, m = manaSize;
//    long long pre[n];
//    memset(pre, 0, sizeof(pre));
//    for (int i = 0; i < m; i++)
//    {
//        //正反两次校对
//        long long sumT = 0;
//        for (int j = 0; j < n; j++)
//        {
//            sumT = fmax(sumT, pre[j]) + skill[j] * mana[i];
//        }
//        pre[n - 1] = sumT;
//        for (int j = n - 2; j >= 0; j--)
//        {
//            pre[j] = pre[j + 1] - skill[j + 1] * mana[i];
//        }
//    }
//    return pre[n - 1];
//}
//
////面试题 04.02. 最小高度树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//        return NULL;
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    int mid = numsSize / 2;
//    root->val = nums[mid];
//    root->left = sortedArrayToBST(nums, mid);
//    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
//    return root;
//}
//
////2496. 数组中字符串的最大值
//
//int maximumValue(char** strs, int strsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < strsSize; i++)
//    {
//        int len = 0, n = 0;
//        for (int j = 0; strs[i][j]; j++)
//        {
//            len++;
//            if (strs[i][j] >= 'a')
//                n = -2;
//            else if (n >= 0)
//                n = n * 10 + strs[i][j] - '0';
//        }
//        if (n >= 0)
//            ans = fmax(ans, n);
//        else
//            ans = fmax(ans, len);
//    }
//    return ans;
//}
//
////2717. 半有序排列
//
//int semiOrderedPermutation(int* nums, int numsSize)
//{
//    int left = 0, right = numsSize - 1;
//    while (nums[left] != 1)
//        left++;
//    while (nums[right] != numsSize)
//        right--;
//    return left + numsSize - 1 - right - (right < left);
//}
//
