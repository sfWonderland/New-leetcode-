////2605. 从两个数字数组里生成最小数字
//
//int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int appear[10] = { 0 };
//    for (int i = 0; i < nums1Size; i++)
//    {
//        appear[nums1[i]] = 1;
//    }
//    int ans = 99;
//    for (int i = 0; i < nums2Size; i++)
//    {
//        if (appear[nums2[i]])
//            ans = fmin(nums2[i], ans);
//        else
//            appear[nums2[i]] = 2;
//    }
//    if (ans < 10) return ans;
//    ans = 0;
//    int flag = 0;
//    for (int i = 0; i < 10 && ans < 10; i++)
//    {
//        if (appear[i] == 0 || flag == appear[i])
//            continue;
//        ans *= 10;
//        ans += i;
//        flag = appear[i];
//    }
//    return ans;
//}
//
////2442. 反转之后不同整数的数目    
//
//int countDistinctIntegers(int* nums, int numsSize)
//{
//    bool appear[1000001] = { 0 };
//    int pos = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        if (!appear[x])
//        {
//            appear[x] = true;
//            pos++;
//        }
//        int rev = 0;
//        while (x)
//        {
//            rev *= 10;
//            rev += x % 10;
//            x /= 10;
//        }
//        if (!appear[rev])
//        {
//            appear[rev] = true;
//            pos++;
//        }
//    }
//    return pos;
//}
//
////2491. 划分技能点相等的团队
//
//long long dividePlayers(int* skill, int skillSize)
//{
//    int sum = 0, cnt[1001] = { 0 };
//    int arr[skillSize], pos = 0;
//    for (int i = 0; i < skillSize; i++)
//    {
//        if (cnt[skill[i]] == 0)
//        {
//            arr[pos++] = skill[i];
//        }
//        cnt[skill[i]]++;
//        sum += skill[i];
//    }
//    int k = 2 * sum / skillSize;
//    // printf("%d %d\n", sum, k);
//    long long ans = 0;
//    for (int i = 0; i < pos; i++)
//    {
//        int x = arr[i];
//        if (cnt[x])
//        {
//            if (k - x > 1000 || x >= k || cnt[k - x] != cnt[x])
//            {
//                return -1;
//            }
//            if (k == 2 * x)
//            {
//                if (cnt[x] % 2)
//                {
//                    return -1;
//                }
//
//                cnt[x] /= 2;
//            }
//            ans += 1ll * x * (k - x) * cnt[x];
//            cnt[x] = 0; cnt[k - x] = 0;
//        }
//    }
//    return ans;
//}
//
////2443. 反转之后的数字和
//
//bool sumOfNumberAndReverse(int num)
//{
//    for (int i = num; i >= num / 2; i--)
//    {
//        int rev = 0, x = i;
//        while (x)
//        {
//            rev *= 10;
//            rev += x % 10;
//            x /= 10;
//        }
//
//        if (i + rev == num)
//            return true;
//    }
//    return false;
//}
//
