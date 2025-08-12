////2385. 感染二叉树需要的总时间
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int ans;
//int x;
//int dfs(struct TreeNode* node)
//{
//    if (node == NULL)
//        return -1;
//
//    int l = dfs(node->left) + 1;
//    int r = dfs(node->right) + 1;
//    if (node->val == x)
//    {
//        ans = fmax(l, r);
//        return 100001;
//    }
//
//    ans = fmax(l + r - 100001, ans);
//    return fmax(l, r);
//}
//int amountOfTime(struct TreeNode* root, int start)
//{
//    ans = 0;
//    x = start;
//    dfs(root);
//    return ans;
//}
//
////2944. 购买水果需要的最少金币数
//
//int minimumCoins(int* prices, int pricesSize)
//{
//    int n = pricesSize;
//    for (int i = (n - 1) / 2 - 1; i >= 0; i--)
//    {
//        int min = INT_MAX;
//        for (int j = i + 1; j < fmin(n, i * 2 + 3); j++)
//        {
//            min = fmin(prices[j], min);
//        }
//        prices[i] += min;
//    }
//    return prices[0];
//}
//
////845. 数组中的最长山脉
//
//int longestMountain(int* arr, int arrSize)
//{
//    int max = 0;
//    for (int i = 1; i < arrSize;)
//    {
//        int up = 0, down = 0;
//        while (i < arrSize && arr[i] > arr[i - 1]) i++, up++;
//        while (i < arrSize && arr[i] < arr[i - 1]) i++, down++;
//        if (up && down) max = fmax(max, up + down + 1);
//        while (i < arrSize&& arr[i] == arr[i - 1]) i++;
//    }
//    return max;
//}
//
////2012. 数组美丽值求和
//
//int sumOfBeauties(int* nums, int numsSize)
//{
//    int pre = nums[0];
//    int suf[numsSize];
//    suf[numsSize - 1] = INT_MAX;
//    for (int i = numsSize - 2; i > 0; i--)
//    {
//        suf[i] = fmin(suf[i + 1], nums[i + 1]);
//    }
//    int ans = 0;
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        if (nums[i] > pre && suf[i] > nums[i])
//            ans += 2;
//        else if (nums[i] > nums[i - 1] && nums[i + 1] > nums[i])
//            ans++;
//
//        pre = fmax(pre, nums[i]);
//    }
//    return ans;
//}
//
