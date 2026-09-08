//// 4038. 计算单个区间中出现的整数数量
//
//int countSpecialIntegers(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int idx[101] = { 0 };
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int x = nums[i];
//        if (idx[x] == -1)
//            continue;
//        else if (idx[x] == 0)
//        {
//            idx[x] = i + 1;
//            ans++;
//        }
//        else if (idx[x] != i)
//        {
//            idx[x] = -1;
//            ans--;
//        }
//        else
//            idx[x]++;
//    }
//    return ans;
//}
//
