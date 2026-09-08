//// 4034. 象到达目标格子的最少移动步数
//
//int minBishopMoves(int* source, int sourceSize, int* target, int targetSize)
//{
//    int sum1 = source[0] + source[1];
//    int sum2 = target[0] + target[1];
//    if ((sum1 + sum2) & 1) return -1;
//    if ((sum1 != sum2 && (source[0] - source[1]) != (target[0] - target[1])))
//        return 2;
//    return 1;
//}
//
//// 4036. 字符对转换后字典序最大的字符串
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//char** largestString(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize;
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        int capacity = 8;
//        ans[i] = (char*)malloc(sizeof(char) * capacity);
//        char c = 'a';
//        int len = 0;
//        int x = nums[i] & 0x1ffffff;
//        int cntZ = nums[i] / (1 << 25);
//        while (x)
//        {
//            if (x & 1)
//            {
//                ans[i][len++] = c;
//                if (len >= capacity)
//                {
//                    capacity *= 2;
//                    ans[i] = (char*)realloc(ans[i], sizeof(char) * capacity);
//                }
//            }
//            c++;
//            x >>= 1;
//        }
//        while (cntZ--)
//        {
//            ans[i][len++] = 'z';
//            if (len >= capacity)
//            {
//                capacity *= 2;
//                ans[i] = (char*)realloc(ans[i], sizeof(char) * capacity);
//            }
//        }
//        ans[i][len] = '\0';
//        reverse(ans[i], 0, len - 1);
//    }
//    *returnSize = n;
//    return ans;
//}
//
