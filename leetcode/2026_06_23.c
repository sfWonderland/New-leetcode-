//// 698. 划分为k个相等的子集
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool canPartitionKSubsets(int* nums, int numsSize, int k)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    if (sum % k) return false;
//
//    int d = sum / k;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int right = numsSize - 1, left = 0;
//    if (nums[right] > d) return false;
//    while (k && nums[right] == d)
//    {
//        right--;
//        k--;
//    }
//    if (k == 0) return true;
//    bool vis[right + 1];
//    memset(vis, 0, sizeof(vis));
//    int dfs(int i, int cur, int cnt)
//    {
//        if (cnt == k) return true;
//        if (cur == d) return dfs(right, 0, cnt + 1);
//        for (int j = i; j >= 0; j--)
//        {
//            if (vis[j] || cur + nums[j] > d) continue;
//
//            vis[j] = true;
//            if (dfs(i - 1, cur + nums[j], cnt)) return true;
//            vis[j] = false;
//            if (cur == 0) return false;
//        }
//        return false;
//    }
//    return dfs(right, 0, 0);
//}
//
