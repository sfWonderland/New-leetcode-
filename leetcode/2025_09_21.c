////2364. 统计坏数对的数目
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//long long countBadPairs(int* nums, int numsSize)
//{
//    Hash* hash = NULL;
//    Hash* tmp = NULL;
//    long long cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int n = nums[i] - i;
//        HASH_FIND_INT(hash, &n, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Hash*)malloc(sizeof(Hash));
//            tmp->key = n;
//            tmp->val = 1;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else
//            cnt += tmp->val++;
//    }
//    return 1ll * numsSize * (numsSize - 1) / 2 - cnt;
//}
//
////1014. 最佳观光组合
//
//int maxScoreSightseeingPair(int* values, int valuesSize)
//{
//    int mx = 0, ans = 0;
//    for (int i = 0; i < valuesSize; i++)
//    {
//        ans = fmax(ans, mx + values[i] - i);
//        mx = fmax(mx, values[i] + i);
//    }
//    return ans;
//}
//
////1814. 统计一个数组中好对子的数目
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//int rev(int x)
//{
//    int res = 0;
//    while (x)
//    {
//        res *= 10;
//        res += x % 10;
//        x /= 10;
//    }
//    return res;
//}
//int countNicePairs(int* nums, int numsSize)
//{
//    Hash* hash = NULL;
//    Hash* tmp = NULL;
//    long long ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i] - rev(nums[i]);
//        HASH_FIND_INT(hash, &x, tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Hash*)malloc(sizeof(Hash));
//            tmp->key = x;
//            tmp->val = 1;
//            HASH_ADD_INT(hash, key, tmp);
//        }
//        else
//            ans += tmp->val++;
//    }
//    int mod = 1e9 + 7;
//    return ans % mod;
//}
//
////3584. 子序列首尾元素的最大乘积
//
//long long maximumProduct(int* nums, int numsSize, int m)
//{
//    long long ans = LLONG_MIN;
//    long long mn = INT_MAX, mx = INT_MIN;
//    for (int i = 0; i < numsSize - m + 1; i++)
//    {
//        int y = nums[i];
//        mn = fmin(mn, y);
//        mx = fmax(mx, y);
//
//        int x = nums[i + m - 1];
//        ans = fmax(ans, x * mn);
//        ans = fmax(ans, x * mx);
//    }
//    return ans;
//}
//
