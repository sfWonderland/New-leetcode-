////3392. ͳ�Ʒ�����������Ϊ 3 ����������Ŀ
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
////1456. �����Ӵ���Ԫ���������Ŀ
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
////643. ���������ƽ���� I(re)
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
////1343. ��СΪ K ��ƽ��ֵ���ڵ�����ֵ����������Ŀ
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
////2090. �뾶Ϊ k ��������ƽ��ֵ
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
