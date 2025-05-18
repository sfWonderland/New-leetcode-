////3024. 三角形类型
//
//char* triangleType(int* nums, int numsSize)
//{
//    int a = nums[0], b = nums[1], c = nums[2];
//    if (a + b <= c || a + c <= b || b + c <= a)
//        return "none";
//    if (a == b && b == c && a == c)
//        return "equilateral";
//    if (a == b || b == c || a == c)
//        return "isosceles";
//
//    return "scalene";
//}
//
////228. 汇总区间
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** summaryRanges(int* nums, int numsSize, int* returnSize)
//{
//    returnSize[0] = 0;
//    if (numsSize == 0)
//        return NULL;
//    char** ret = (char**)malloc(sizeof(char*) * numsSize);
//    int left = 0, right = 1, n = 0;
//    for (int right = 1; right <= numsSize; right++)
//    {
//        if (right == numsSize || nums[right] != nums[right - 1] + 1)
//        {
//            int j = 0;
//            ret[n] = (char*)malloc(sizeof(char) * 25);
//            sprintf(ret[n], "%d", nums[left]);
//            if (right != left + 1)
//            {
//                sprintf(ret[n] + strlen(ret[n]), "->");
//                sprintf(ret[n] + strlen(ret[n]), "%d", nums[right - 1]);
//            }
//            n++;
//            left = right;
//        }
//    }
//    *returnSize = n;
//    return ret;
//}
//
////3456. 找出长度为 K 的特殊子字符串
//
//bool hasSpecialSubstring(char* s, int k)
//{
//    int n = strlen(s), cnt = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cnt++;
//        if (i == n - 1 || s[i] != s[i + 1])
//        {
//            if (cnt == k)
//                return true;
//            cnt = 0;
//        }
//    }
//    return false;
//}
//
////3498. 字符串的反转度
//
//int reverseDegree(char* s)
//{
//    int ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        ans += ('z' - s[i] + 1) * (i + 1);
//    }
//    return ans;
//}
//
