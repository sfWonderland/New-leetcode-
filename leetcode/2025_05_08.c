////2824. ͳ�ƺ�С��Ŀ����±����Ŀ
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int countPairs(int* nums, int numsSize, int target)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (int left = 0, right = numsSize - 1; left < right; left++)
//    {
//        while (left < right && (nums[left] + nums[right]) >= target)
//            right--;
//
//        ans += right - left;
//    }
//    return ans;
//}
//
////LCP 28. �ɹ�����
//
//#define MOD 1000000007;
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int purchasePlans(int* nums, int numsSize, int target)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (int left = 0, right = numsSize - 1; left < right; left++)
//    {
//        while (left < right && nums[left] + nums[right] > target)
//            right--;
//
//        ans = (ans + right - left) % MOD;
//    }
//    return ans;
//}
//
////LCR 003. ����λ����
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cnt(int n)
//{
//    int ret = 0;
//    while (n)
//    {
//        n &= n - 1;
//        ret++;
//    }
//    return ret;
//}
//int* countBits(int n, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * (n + 1));
//    *returnSize = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        ans[(*returnSize)++] = cnt(i);
//    }
//    return ans;
//}
//
////LCP 01. ������
//
//int game(int* guess, int guessSize, int* answer, int answerSize)
//{
//    int n = guessSize, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans += (guess[i] == answer[i]);
//    }
//    return ans;
//}
//
