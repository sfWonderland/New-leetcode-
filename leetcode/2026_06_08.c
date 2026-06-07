//// 3950. 恰好一对连续置位
//
//bool consecutiveSetBits(int n)
//{
//    bool exist = false;
//    while (n > 1)
//    {
//        if ((n & 3) == 3)
//        {
//            if (exist)
//                return false;
//
//            exist = true;
//        }
//        n >>= 1;
//    }
//    return exist;
//}
//
//// 3951. 维持亮度的最小总能量    
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] == (*(int**)e2)[0] ? (*(int**)e2)[1] - (*(int**)e1)[1] : (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//long long minEnergy(int n, int brightness, int** intervals, int intervalsSize, int* intervalsColSize)
//{
//    int len = intervalsSize;
//    qsort(intervals, len, sizeof(int*), cmp);
//    int periods = 0;
//    for (int i = 1; i < len; i++)
//    {
//        int left = intervals[i][0], right = intervals[i][1];
//        if (right <= intervals[periods][1])
//            continue;
//        else if (left <= intervals[periods][1])
//            intervals[periods][1] = right;
//        else
//        {
//            intervals[++periods][0] = left;
//            intervals[periods][1] = right;
//        }
//    }
//    long long time = 0;
//    for (int i = 0; i <= periods; i++)
//    {
//        time += intervals[i][1] - intervals[i][0] + 1;
//    }
//    int m = (brightness + 2) / 3;
//    return time * m;
//}
//
//// 3952. 下标覆盖处的最大总和
//
//long long maxTotal(int* nums, int numsSize, char* s)
//{
//    int n = numsSize;
//    long long ans = 0;
//    int pre = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] & 1)
//        {
//            if (pre > nums[i])
//            {
//                ans += pre;
//                pre = nums[i];
//            }
//            else
//                ans += nums[i];
//        }
//        else
//            pre = nums[i];
//    }
//    return ans;
//}
//
