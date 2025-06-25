////3591. 检查元素频次是否为质数
//
//bool isprime(int n)
//{
//    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29 || n == 31 || n == 37 || n == 41 || n == 43 || n == 47 || n == 53 || n == 59 || n == 61 || n == 67 || n == 71 || n == 73 || n == 79 || n == 83 || n == 89 || n == 97)
//        return true;
//
//    return false;
//}
//bool checkPrimeFrequency(int* nums, int numsSize)
//{
//    int cnt[101] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i]]++;
//    }
//    int ans = 0;
//    for (int i = 0; i < 101; i++)
//    {
//        if (isprime(cnt[i]))
//            ans++;
//    }
//    return ans;
//}
//
////2761. 和等于目标值的质数对
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** findPrimePairs(int n, int* returnSize, int** returnColumnSizes)
//{
//    if (n < 2)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    bool arr[n - 1];
//    for (int i = 0; i < n - 1; i++)
//    {
//        arr[i] = true;
//    }
//    for (int i = 2; i < sqrt(n); i++)
//    {
//        if (arr[i - 2])
//        {
//            for (int j = i * i; j <= n; j += i)
//            {
//                arr[j - 2] = false;
//            }
//        }
//    }
//    int** ans = (int**)malloc(sizeof(int*) * (n / 2));
//    int t = 0;
//    for (int i = 2; i <= n / 2; i++)
//    {
//        if (arr[i - 2] && arr[n - i - 2])
//        {
//            ans[t] = (int*)malloc(sizeof(int) * 2);
//            ans[t][0] = i;
//            ans[t++][1] = n - i;
//        }
//    }
//    *returnSize = t;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * t);
//    for (int i = 0; i < t; i++)
//    {
//        (*returnColumnSizes)[i] = 2;
//    }
//    return ans;
//}
//
////3233. 统计不是特殊数字的数字数量
//
//int nonSpecialCount(int l, int r)
//{
//    int n = sqrt(r);
//    if (n < 2)
//        return r - l + 1;
//    bool arr[n - 1];
//    for (int i = 0; i < n - 1; i++)
//    {
//        arr[i] = true;
//    }
//    for (int i = 2; i <= sqrt(n); i++)
//    {
//        if (arr[i - 2])
//        {
//            for (int j = i * i; j <= n; j += i)
//            {
//                arr[j - 2] = false;
//            }
//        }
//    }
//    int t = sqrt(l);
//    if (t * t < l)
//        ++t;
//    t = fmax(t, 2);
//    int ans = r - l + 1;
//    for (int i = t; i <= n; i++)
//    {
//        ans -= arr[i - 2];
//    }
//    return ans;
//}
//
////2523. 范围内最接近的两个质数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* closestPrimes(int left, int right, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = -1; ans[1] = -1;
//    *returnSize = 2;
//    if (right <= 2)
//        return ans;
//    left = fmax(2, left);
//    bool arr[right - 1];
//    for (int i = 0; i < right - 1; i++)
//    {
//        arr[i] = true;
//    }
//    int n = sqrt(right);
//    for (int i = 2; i <= n; i++)
//    {
//        if (arr[i - 2])
//        {
//            for (int j = i * i; j <= right; j += i)
//            {
//                arr[j - 2] = false;
//            }
//        }
//    }
//    int pre = -1;
//    for (int i = left; i <= right; i++)
//    {
//        if (arr[i - 2])
//        {
//            if (ans[0] == -1) ans[0] = i;
//            else if (ans[1] == -1) ans[1] = i;
//            else
//            {
//                if (i - pre < ans[1] - ans[0])
//                {
//                    ans[0] = pre;
//                    ans[1] = i;
//                }
//            }
//            pre = i;
//        }
//    }
//    if (ans[0] == -1 || ans[1] == -1)
//    {
//        ans[0] = -1;
//        ans[1] = -1;
//        return ans;
//    }
//    return ans;
//}
//
