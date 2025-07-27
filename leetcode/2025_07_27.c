////3184. 构成整天的下标对数目 I
//
//int countCompleteDayPairs(int* hours, int hoursSize)
//{
//    int cnt[24] = { 0 };
//    for (int i = 0; i < hoursSize; i++)
//    {
//        int x = hours[i] % 24;
//        cnt[x]++;
//    }
//    int sum = 0;
//    for (int i = 0; i < 13; i++)
//    {
//        if (i % 12)
//            sum += cnt[i] * cnt[24 - i];
//        else
//            sum += cnt[i] * (cnt[i] - 1) / 2;
//    }
//    return sum;
//}
//
////1662. 检查两个字符串数组是否相等
//
//bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size)
//{
//    int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
//    while (r1 < word1Size && r2 < word2Size)
//    {
//        if (word1[r1][c1] != word2[r2][c2])
//            return false;
//        c1++;
//        if (word1[r1][c1] == '\0')
//        {
//            r1++;
//            c1 = 0;
//        }
//        c2++;
//        if (word2[r2][c2] == '\0')
//        {
//            r2++;
//            c2 = 0;
//        }
//    }
//    return r1 == word1Size && r2 == word2Size;
//}
//
////2341. 数组能形成多少数对
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* numberOfPairs(int* nums, int numsSize, int* returnSize)
//{
//    int cnt[101] = { 0 };
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(max, nums[i]);
//        cnt[nums[i]]++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = 0, ans[1] = 0;
//    for (int i = 0; i <= max; i++)
//    {
//        ans[0] += cnt[i] >> 1;
//        ans[1] += cnt[i] & 1;
//    }
//    *returnSize = 2;
//    return ans;
//}
//
////3550. 数位和等于下标的最小下标
//
//int smallestIndex(int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        int sum = 0;
//        while (nums[i])
//        {
//            sum += nums[i] % 10;
//            nums[i] /= 10;
//        }
//        if (sum == i)
//            return i;
//    }
//    return -1;
//}
//
