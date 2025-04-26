////3392. 统计符合条件长度为 3 的子数组数目
//
//int countSubarrays(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize - 2; i++)
//    {
//        if ((nums[i] + nums[i + 2]) * 2 - nums[i + 1] == 0)
//            sum++;
//    }
//    return sum;
//}
//
////1456. 定长子串中元音的最大数目
//
//bool isvowel(char ch)
//{
//    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
//}
//int maxVowels(char* s, int k)
//{
//    int vowel = 0, ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        vowel += isvowel(s[i]);
//        if (i < k - 1)
//            continue;
//
//        ans = fmax(ans, vowel);
//        vowel -= isvowel(s[i - k + 1]);
//    }
//    return ans;
//}
//
////643. 子数组最大平均数 I(re)
//
//double findMaxAverage(int* nums, int numsSize, int k)
//{
//    double max = INT_MIN;
//    double sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        if (i < k - 1)
//            continue;
//
//        max = fmax(max, sum / (k + 0.0));
//        sum -= nums[i - k + 1];
//    }
//    return max;
//}
//
////1343. 大小为 K 且平均值大于等于阈值的子数组数目
//
//int numOfSubarrays(int* arr, int arrSize, int k, int threshold)
//{
//    int ans = 0, sum = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        sum += arr[i];
//        if (i < k - 1)
//            continue;
//
//        ans += sum >= threshold * k;
//        sum -= arr[i - k + 1];
//    }
//    return ans;
//}
//
////2090. 半径为 k 的子数组平均值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getAverages(int* nums, int numsSize, int k, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    memset(ans, -1, sizeof(int) * numsSize);
//    long long sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum = sum + nums[i];
//        if (i < k * 2)
//            continue;
//
//        ans[i - k] = sum / (2 * k + 1);
//        sum -= nums[i - 2 * k];
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
