////3111. 覆盖所有点的最少矩形数目
//
//int cmp(const void* e1, const void* e2)
//{
//    return *((int**)e1)[0] - *((int**)e2)[0];
//}
//int minRectanglesToCoverPoints(int** points, int pointsSize, int* pointsColSize, int w)
//{
//    qsort(points, pointsSize, sizeof(int) * 2, cmp);
//    int ans = 1, left = points[0][0];
//    for (int i = 0; i < pointsSize; i++)
//    {
//        if (points[i][0] > left + w)
//        {
//            left = points[i][0];
//            ans++;
//        }
//    }
//    return ans;
//}
//
////2957. 消除相邻近似相等字符
//
//int removeAlmostEqualCharacters(char* word)
//{
//    int ans = 0, n = strlen(word);
//    for (int i = 1; i < n; i++)
//    {
//        if (abs(word[i] - word[i - 1]) <= 1)
//        {
//            ans++;
//            i++;
//        }
//    }
//    return ans;
//}
//
////3192. 使二进制数组全部等于 1 的最少操作次数 II
//
////方法一：记录操作次数
//// int minOperations(int* nums, int numsSize) 
//// {
////     int ans = 0;
////     for(int i = 0; i < numsSize; i++)
////     {
////         if(nums[i] == (ans & 1))
////             ans++;
////     }
////     return ans;
//// }
////方法二：比较相邻元素
//int minOperations(int* nums, int numsSize)
//{
//    int ans = nums[0] ^ 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        ans += nums[i] ^ nums[i - 1];
//    }
//    return ans;
//}
//
////2789. 合并后数组中的最大元素
//
//long long maxArrayValue(int* nums, int numsSize)
//{
//    long long ans = nums[numsSize - 1];
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        if (ans >= nums[i])
//            ans += nums[i];
//        else
//            ans = nums[i];
//    }
//    return ans;
//}
//
