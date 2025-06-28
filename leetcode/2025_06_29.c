////1498. 满足条件的子序列数目
//
//#define mod 1000000007
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int numSubseq(int* nums, int numsSize, int target)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int left = 0, right = numsSize - 1;
//    int ans = 0;
//    for (int i = left; i <= right; i++)
//    {
//        if (nums[left] * 2 > target)
//            break;
//        while (right >= i && nums[i] + nums[right] > target)
//        {
//            right--;
//        }
//        if (right < i)
//            break;
//        int exp = right - i;
//        long long result = 1, base = 2;
//        while (exp > 0)
//        {
//            if (exp & 1)
//                result = (result * base) % mod;
//            base = base * base % mod;
//            exp >>= 1;
//        }
//        //printf("%d %d\n", right - i, result);
//        ans = (ans + result) % mod;
//    }
//    return ans;
//}
//
////1362. 最接近的因数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int factor(int n, int* a, int* b)
//{
//    int m = sqrt(n);
//    for (int i = m; i > 0; i--)
//    {
//        if (n % i == 0)
//        {
//            *a = i;
//            *b = n / i;
//            break;
//        }
//    }
//    return *b - *a;
//}
//int* closestDivisors(int num, int* returnSize)
//{
//    int x1 = 1, x2 = 1, y1 = num + 1, y2 = num + 2;
//    int d1 = factor(num + 1, &x1, &y1), d2 = factor(num + 2, &x2, &y2);
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    if (d1 <= d2)
//    {
//        ans[0] = x1;
//        ans[1] = y1;
//    }
//    else
//    {
//        ans[0] = x2;
//        ans[1] = y2;
//    }
//    *returnSize = 2;
//    return ans;
//}
//
////2748. 美丽下标对的数目
//
//int gcd(int a, int b)
//{
//    while (a % b)
//    {
//        int t = b;
//        b = a % b;
//        a = t;
//    }
//    return b;
//}
//int countBeautifulPairs(int* nums, int numsSize)
//{
//    int ans = 0, cnt[10] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = 1; j < 10; j++)
//        {
//            if (cnt[j] && (gcd(j, nums[i] % 10) == 1))
//                ans += cnt[j];
//        }
//
//        while (nums[i] >= 10)
//            nums[i] /= 10;
//
//        cnt[nums[i]]++;
//    }
//    return ans;
//}
//
////1447. 最简分数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int gcd(int a, int b)
//{
//    while (a % b)
//    {
//        int tmp = b;
//        b = a % b;
//        a = tmp;
//    }
//    return b;
//}
//char** simplifiedFractions(int n, int* returnSize)
//{
//    char** ans = (char**)malloc(sizeof(char*) * (n + 1) * n / 2);
//    int t = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 1; j < i; j++)
//        {
//            if (gcd(i, j) == 1)
//            {
//                ans[t] = (char*)malloc(sizeof(char) * 7);
//                char s1[4], s2[4];
//                sprintf(s1, "%d", j);
//                int m = strlen(s1);
//                strcpy(ans[t], s1);
//                ans[t][m] = '/';
//                sprintf(s2, "%d", i);
//                strcpy(ans[t] + m + 1, s2);
//                t++;
//            }
//        }
//    }
//    *returnSize = t;
//    return ans;
//}
//
