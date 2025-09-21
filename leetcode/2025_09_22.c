////2905. 找出满足差值条件的下标 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = -1; ans[1] = -1;
//    *returnSize = 2;
//
//    int d = indexDifference, diff = valueDifference;
//    int mx[2] = { INT_MIN, -1 }, mn[2] = { INT_MAX, -1 };
//    for (int i = indexDifference; i < numsSize; i++)
//    {
//        if (nums[i - d] - diff > mx[0])
//        {
//            mx[0] = nums[i - d] - diff;
//            mx[1] = i - d;
//        }
//        if (nums[i - d] + diff < mn[0])
//        {
//            mn[0] = nums[i - d] + diff;
//            mn[1] = i - d;
//        }
//
//        if (mx[0] >= nums[i])
//        {
//            ans[0] = mx[1];
//            ans[1] = i;
//            return ans;
//        }
//        if (mn[0] <= nums[i])
//        {
//            ans[0] = mn[1];
//            ans[1] = i;
//            return ans;
//        }
//    }
//    return ans;
//}
//
////1031. 两个非重叠子数组的最大和
//
//int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen)
//{
//    int n = numsSize;
//    int pre[n + 1];
//    pre[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre[i + 1] = pre[i] + nums[i];
//    }
//    int a = firstLen, b = secondLen;
//    int sumA = 0, sumB = 0, ans = 0;
//    for (int i = a + b; i <= n; i++)
//    {
//        sumA = fmax(sumA, pre[i - a] - pre[i - a - b]);
//        sumB = fmax(sumB, pre[i - b] - pre[i - a - b]);
//        ans = fmax(ans, sumA + pre[i] - pre[i - a]);
//        ans = fmax(ans, sumB + pre[i] - pre[i - b]);
//    }
//    return ans;
//}
//
////3583. 统计特殊三元组
//
//#define MOD 1000000007
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}Hash;
//int specialTriplets(int* nums, int numsSize)
//{
//    Hash* suf = NULL;
//    Hash* tmp = NULL;
//    for (int i = 2; i < numsSize; i++)
//    {
//        HASH_FIND_INT(suf, &nums[i], tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Hash*)malloc(sizeof(Hash));
//            tmp->key = nums[i];
//            tmp->val = 1;
//            HASH_ADD_INT(suf, key, tmp);
//        }
//        else
//            tmp->val++;
//    }
//    Hash* pre = NULL;
//    tmp = NULL;
//    long long ans = 0;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (i > 1)
//        {
//            HASH_FIND_INT(suf, &nums[i], tmp);
//            if (tmp->val == 1)
//                HASH_DEL(suf, tmp);
//            else
//                tmp->val--;
//        }
//        if (i > 0)
//        {
//            int t = nums[i] * 2;
//            HASH_FIND_INT(pre, &t, tmp);
//            if (tmp)
//            {
//                int l = tmp->val;
//                HASH_FIND_INT(suf, &t, tmp);
//                if (tmp)
//                {
//                    int r = tmp->val;
//                    ans = (ans + 1ll * l * r) % MOD;
//                }
//            }
//        }
//
//        HASH_FIND_INT(pre, &nums[i], tmp);
//        if (tmp == NULL)
//        {
//            tmp = (Hash*)malloc(sizeof(Hash));
//            tmp->key = nums[i];
//            tmp->val = 1;
//            HASH_ADD_INT(pre, key, tmp);
//        }
//        else
//            tmp->val++;
//    }
//    Hash* s = NULL;
//    HASH_ITER(hh, pre, tmp, s)
//    {
//        HASH_DEL(pre, tmp);
//        free(tmp);
//    }
//    HASH_ITER(hh, suf, tmp, s)
//    {
//        HASH_DEL(suf, tmp);
//        free(tmp);
//    }
//    return ans;
//}
//
////1930. 长度为 3 的不同回文子序列
//
//int countPalindromicSubsequence(char* s)
//{
//    bool flag[26][26] = { 0 };
//    int n = strlen(s), ans = 0;
//    int suf[26] = { 0 };
//    for (int i = 2; i < n; i++)
//    {
//        suf[s[i] - 'a']++;
//    }
//    bool pre[26] = { 0 };
//    pre[s[0] - 'a'] = true;
//    for (int i = 1; i < n - 1; i++)
//    {
//        int t = s[i] - 'a';
//        if (i > 1)
//            suf[t]--;
//        for (int j = 0; j < 26; j++)
//        {
//            if (pre[j] && !flag[j][t])
//            {
//                if (suf[j])
//                {
//                    flag[j][t] = true;
//                    ans++;
//                }
//            }
//        }
//        pre[t] = true;
//    }
//    return ans;
//}
//
