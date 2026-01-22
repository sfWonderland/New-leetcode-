////3809. 最好可到达的塔
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* bestTower(int** towers, int towersSize, int* towersColSize, int* center, int centerSize, int radius, int* returnSize)
//{
//    int idx = -1;
//    for (int i = 0; i < towersSize; i++)
//    {
//        int dist = abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]);
//        if (dist <= radius)
//        {
//            if (idx < 0
//                || towers[i][2] > towers[idx][2]
//                || (towers[i][2] == towers[idx][2]
//                    && (towers[i][0] < towers[idx][0]
//                        || (towers[i][0] == towers[idx][0]
//                            && towers[i][1] < towers[idx][1])
//                        )
//                    )
//                )
//                idx = i;
//        }
//    }
//    *returnSize = 2;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = -1; ans[1] = -1;
//    if (idx >= 0)
//    {
//        ans[0] = towers[idx][0];
//        ans[1] = towers[idx][1];
//    }
//    return ans;
//}
//
////3810. 变成目标数组的最少操作次数    
//
//int minOperations(int* nums, int numsSize, int* target, int targetSize)
//{
//    bool diff[100001] = { 0 };
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != target[i] && !diff[nums[i]])
//        {
//            ans += 1 - diff[nums[i]];
//            diff[nums[i]] = 1;
//        }
//    }
//    return ans;
//}
//
////3811. 交替按位异或分割的数目
//
//const int MOD = 1e9 + 7;
////前缀和+动态规划（状态转换）
//int alternatingXOR(int* nums, int numsSize, int target1, int target2)
//{
//    if (numsSize == 1)
//        return nums[0] == target1;
//
//    // 1 ~ 100000 的异或和最多有16位1
//    int f1[1 << 17] = { 0 };
//    // 相当于在第一段前面有一个空前缀，异或和为 0。这样我们计算第一段时，就可以让第一段的方案数是 1。
//    int f2[1 << 17] = { 1 };
//    int preSum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        preSum ^= nums[i];
//        // 后续状态更新可能污染旧值
//        int save_f1 = f2[preSum ^ target1];
//        // if(preSum == target1)
//        // save_f1++;
//        // 等价于f2[0] = 1;
//        int save_f2 = f1[preSum ^ target2];
//        // 要在最后一轮更新前返回，因为，f[preSum]算的是前缀异或和为 preSum 的方案数。
//        // 在遍历完后，再从 f1 和 f2 中取数据，
//        // 这可能会把「异或和恰好等于整个数组的异或和」的前缀的划分方案也算进来。
//        if (i == numsSize - 1)
//            return (save_f1 + save_f2) % MOD;
//        f1[preSum] = (f1[preSum] + save_f1) % MOD;
//        f2[preSum] = (f2[preSum] + save_f2) % MOD;
//    }
//    return -1;
//}
////3120. 统计特殊字母的数量 I
//
//int numberOfSpecialChars(char* word)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; word[i]; i++)
//    {
//        if (word[i] < 'a')
//            cnt[word[i] - 'A'] |= 1;
//        else
//            cnt[word[i] - 'a'] |= 2;
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        ans += cnt[i] == 3;
//    }
//    return ans;
//}
//
