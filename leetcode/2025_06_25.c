////3162. 优质数对的总数 I
//
//int numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
//{
//    int cnt[51] = { 0 };
//    for (int i = 0; i < nums1Size; i++)
//    {
//        if (nums1[i] % k)
//            continue;
//        int x = nums1[i] / k;
//        for (int j = 1; j * j <= x; j++)
//        {
//            if (x % j)
//                continue;
//
//            cnt[j]++;
//            if (j * j < x)
//                cnt[x / j]++;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < nums2Size; i++)
//    {
//        ans += cnt[nums2[i]];
//    }
//    return ans;
//}
//
////2194. Excel 表中某个范围内的单元格
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** cellsInRange(char* s, int* returnSize)
//{
//    int c1 = s[0], c2 = s[3];
//    int r1 = s[1], r2 = s[4];
//    int n = (c2 - c1 + 1) * (r2 - r1 + 1);
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    int t = 0;
//    for (int i = c1; i <= c2; i++)
//    {
//        for (int j = r1; j <= r2; j++)
//        {
//            ans[t] = (char*)malloc(sizeof(char) * 3);
//            ans[t][0] = i;
//            ans[t][1] = j;
//            ans[t][2] = '\0';
//            t++;
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////3131. 找出与数组相加的整数 I
//
//int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int max[2] = { 0 };
//    for (int i = 0; i < nums1Size; i++)
//    {
//        max[0] = fmax(max[0], nums1[i]);
//        max[1] = fmax(max[1], nums2[i]);
//    }
//    return max[1] - max[0];
//}
//
////3492. 船上可以装载的最大集装箱数量
//
//int maxContainers(int n, int w, int maxWeight)
//{
//    int max = maxWeight / w;
//    return n * n > max ? max : n * n;
//}
//
