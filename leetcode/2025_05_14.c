////287. 寻找重复数
//
//int findDuplicate(int* nums, int numsSize) {
//    int slow = 0, fast = 0;
//    while (fast != slow || slow == 0)
//    {
//        fast = nums[nums[fast]];
//        slow = nums[slow];
//    }
//
//    int ptr = 0;
//    while (ptr != slow)
//    {
//        ptr = nums[ptr];
//        slow = nums[slow];
//    }
//    return ptr;
//}
//
////2570. 合并两个二维数组 - 求和法
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = nums1Size, n = nums2Size;
//    int** ans = (int**)malloc(sizeof(int*) * (m + n));
//    for (int k = 0; k < m + n; k++)
//    {
//        ans[k] = (int*)malloc(sizeof(int) * 2);
//        memset(ans[k], 0, sizeof(int) * 2);
//    }
//    int i = 0, j = 0, index = -1;
//    while (i < m || j < n)
//    {
//        int num = 0, t = 0;
//        if (j >= n || (i < m && nums1[i][0] < nums2[j][0]))
//        {
//            num = nums1[i][1];
//            t = nums1[i++][0];
//        }
//        else
//        {
//            num = nums2[j][1];
//            t = nums2[j++][0];
//        }
//        if (index >= 0 && t == ans[index][0])
//            ans[index][1] += num;
//        else
//        {
//            ans[++index][0] = t;
//            ans[index][1] = num;
//        }
//    }
//    *returnSize = index + 1;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (index + 1));
//    for (int k = 0; k < index + 1; k++)
//    {
//        (*returnColumnSizes)[k] = 2;
//    }
//    return ans;
//}
//
////LCP 18. 早餐组合
//
//#define MOD 1000000007
//// int cmp(const void* e1, const void* e2)
//// {
////     return *(int*)e1 - *(int*)e2;
//// }
//// int breakfastNumber(int* staple, int stapleSize, int* drinks, int drinksSize, int x)
//// {
////     qsort(staple, stapleSize, sizeof(int), cmp);
////     qsort(drinks, drinksSize, sizeof(int), cmp);
//
////     for(int i = 0; i < stapleSize; i++)
////     {
////         if(staple[i] > x)
////         {
////             stapleSize = i + 1;
////             break;
////         }
////     }
//
////     for(int i = 0; i < drinksSize; i++)
////     {
////         if(drinks[i] > x)
////         {
////             drinksSize = i + 1;
////             break;
////         }
////     }
//
////     int j = drinksSize - 1, sum = 0;
////     for(int i = 0; i < stapleSize; i++)
////     {
////         for(; j >= 0; j--)
////         {
////             if(drinks[j] + staple[i] <= x)
////             {
////                 sum = (sum + j + 1) % MOD;
////                 break;
////             }
////         }
////     }
////     return sum;
//// }
//
//int breakfastNumber(int* staple, int stapleSize, int* drinks, int drinksSize, int x)
//{
//    int cnt[100001] = { 0 };
//    for (int i = 0; i < drinksSize; i++)
//    {
//        cnt[drinks[i]]++;
//    }
//    for (int i = 1; i < 100001; i++)
//    {
//        cnt[i] += cnt[i - 1];
//    }
//    long long num = 0;
//    for (int i = 0; i < stapleSize; i++)
//    {
//        int idx = x - staple[i];
//        if (idx > 0)
//        {
//            idx = fmin(idx, 100000);
//            num += cnt[idx];
//            if (num >= MOD)
//                num %= MOD;
//        }
//    }
//    return num;
//}
//
////3427. 变长子数组求和
//
//int subarraySum(int* nums, int numsSize)
//{
//    int pre[numsSize];
//    pre[0] = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        pre[i] = pre[i - 1] + nums[i];
//    }
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int start = fmax(0, i - nums[i]);
//        ans += start > 0 ? pre[i] - pre[start - 1] : pre[i];
//    }
//    return ans;
//}
//
