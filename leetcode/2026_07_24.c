//// 3514. 不同 XOR 三元组的数目 II
//
//int uniqueXorTriplets(int* nums, int numsSize)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (max < nums[i])
//            max = nums[i];
//    }
//    int u = 1 << (32 - __builtin_clz(max));
//    bool* vis1 = (bool*)calloc(sizeof(bool), u);
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i; j < numsSize; j++)
//        {
//            vis1[nums[i] ^ nums[j]] = true;
//        }
//    }
//    bool* vis2 = (bool*)calloc(sizeof(bool), u);
//    for (int i = 0; i < u; i++)
//    {
//        if (!vis1[i]) continue;
//        for (int j = 0; j < numsSize; j++)
//        {
//            vis2[i ^ nums[j]] = true;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < u; i++)
//    {
//        ans += vis2[i];
//    }
//    free(vis1);
//    free(vis2);
//    return ans;
//}
//
