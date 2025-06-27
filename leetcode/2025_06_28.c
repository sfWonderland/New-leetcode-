////2099. 找到和最大的长度为 K 的子序列
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* nums0;
//int cmp_nums(const void* e1, const void* e2)
//{
//    return nums0[*(int*)e2] - nums0[*(int*)e1];
//}
//int cmp_idx(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize)
//{
//    nums0 = nums;
//    int* idx = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        idx[i] = i;
//    }
//    qsort(idx, numsSize, sizeof(int), cmp_nums);
//    qsort(idx, k, sizeof(int), cmp_idx);
//    for (int i = 0; i < k; i++)
//    {
//        idx[i] = nums[idx[i]];
//    }
//    *returnSize = k;
//    return idx;
//}
//
////2521. 数组乘积中的不同质因数数目
//
//int distinctPrimeFactors(int* nums, int numsSize)
//{
//    int factor[1001] = { 0 };
//
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = 2;
//        for (; x * x <= nums[i]; x++)
//        {
//            if (nums[i] % x == 0)
//            {
//                if (factor[x] == 0)
//                {
//                    factor[x] = 1;
//                    ans++;
//                }
//
//                nums[i] /= x;
//                while (nums[i] % x == 0)
//                    nums[i] /= x;
//            }
//        }
//        if (nums[i] > 1)
//        {
//            if (factor[nums[i]] == 0)
//            {
//                factor[nums[i]] = 1;
//                ans++;
//            }
//        }
//    }
//    return ans;
//}
//
////1492. n 的第 k 个因子
//
//int kthFactor(int n, int k)
//{
//    if (k == 1)
//        return 1;
//    int num = sqrt(n);
//    int factor[num];
//    memset(factor, 0, sizeof(int) * num);
//    factor[0] = 1;
//    int t = 1;
//    for (int i = 2; i * i <= n; i++)
//    {
//        if (n % i == 0)
//        {
//            factor[t++] = i;
//            if (k == t)
//                return i;
//        }
//    }
//    int sum = t * 2 - (num * num == n);
//    if (sum < k)
//        return -1;
//
//    return n / factor[sum - k];
//}
//
////1390. 四因数
//
//int sumFourDivisors(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int m = sqrt(nums[i]);
//        if (nums[i] == m * m)
//            continue;
//
//        int k = 2, sum = 1 + nums[i];
//        for (int x = 2; x * x < nums[i]; x++)
//        {
//            if (nums[i] % x == 0)
//            {
//                if (k == 2)
//                {
//                    k += 2;
//                    sum += x + nums[i] / x;
//                }
//                else
//                {
//                    k = 0;
//                    break;
//                }
//            }
//        }
//        if (k == 4)
//            ans += sum;
//    }
//    return ans;
//}
//
