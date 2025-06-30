////3330. 找到初始输入字符串 I
//
//int possibleStringCount(char* word)
//{
//    int sum = 1;
//    char ch = 0;
//    for (int i = 0; word[i]; i++)
//    {
//        if (ch != word[i])
//            ch = word[i];
//        else
//            sum++;
//    }
//    return sum;
//}
//
////2750. 将数组划分成若干好子数组的方式
//
//#define mod 1000000007
//int numberOfGoodSubarraySplits(int* nums, int numsSize)
//{
//    int i = 0;
//    while (i < numsSize && nums[i] == 0)
//        i++;
//
//    if (i == numsSize)
//        return 0;
//
//    long long ans = 1;
//    for (i = i + 1; i < numsSize; i++)
//    {
//        int left = i;
//        while (i < numsSize && nums[i] == 0)
//            i++;
//
//        if (left > 0 && i < numsSize)
//            ans = (ans * (i - left + 1)) % mod;
//    }
//    return ans;
//}
//
////2550. 猴子碰撞的方法数
//
//#define mod 1000000007
//int monkeyMove(int n)
//{
//    long long exp = n, base = 2, ans = 1;
//    while (exp > 0)
//    {
//        if (exp & 1)
//            ans = (ans * base) % mod;
//
//        base = (base * base) % mod;
//        exp >>= 1;
//    }
//    return (ans + mod - 2) % mod;
//}
//
////1922. 统计好数字的数目
//
//#define mod 1000000007
//int countGoodNumbers(long long n)
//{
//    long long even = (n + 1) / 2, odd = n / 2;
//    long long base_e = 5, base_o = 4;
//    long long ans1 = 1, ans2 = 1;
//    while (even > 0)
//    {
//        if (even & 1)
//            ans1 = ans1 * base_e % mod;
//
//        base_e = base_e * base_e % mod;
//        even >>= 1;
//    }
//    while (odd > 0)
//    {
//        if (odd & 1)
//            ans2 = ans2 * base_o % mod;
//
//        base_o = base_o * base_o % mod;
//        odd >>= 1;
//    }
//    return (ans1 * ans2) % mod;
//}
//
