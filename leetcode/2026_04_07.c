////3653. 区间乘法查询后的异或 I
//
//const int MOD = 1e9 + 7;
//int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize)
//{
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int l = queries[i][0], r = queries[i][1];
//        int k = queries[i][2], v = queries[i][3];
//        for (int j = l; j <= r; j += k)
//        {
//            nums[j] = (1ll * nums[j] * v) % MOD;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans ^= nums[i];
//    }
//    return ans;
//}
//
////3678. 大于平均值的最小未出现正整数    
//
//int smallestAbsent(int* nums, int numsSize)
//{
//    bool cnt[201] = { 0 };
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        cnt[nums[i] + 100] = true;
//    }
//    for (int i = fmax(1, sum / numsSize + 1); i <= 100; i++)
//    {
//        if (!cnt[i + 100])
//            return i;
//    }
//    return 101;
//}
//
////2069. 模拟行走机器人 II
//
//typedef struct
//{
//    int width;
//    int height;
//    int s;
//} Robot;
//
//
//Robot* robotCreate(int width, int height)
//{
//    Robot* obj = (Robot*)malloc(sizeof(Robot));
//    obj->width = width;
//    obj->height = height;
//    obj->s = 0;
//    return obj;
//}
//
//void robotStep(Robot* obj, int num)
//{
//    obj->s = (obj->s + num - 1) % ((obj->width + obj->height - 2) * 2) + 1;
//}
//
//int* robotGetPos(Robot* obj, int* retSize)
//{
//    int w = obj->width, h = obj->height, s = obj->s;
//    int x, y;
//    if (s < w)
//    {
//        x = s;
//        y = 0;
//    }
//    else if (s < w + h - 1)
//    {
//        x = w - 1;
//        y = s - w + 1;
//    }
//    else if (s < 2 * w + h - 2)
//    {
//        x = 2 * w + h - s - 3;
//        y = h - 1;
//    }
//    else
//    {
//        x = 0;
//        y = 2 * w + 2 * h - s - 4;
//    }
//
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = x; ans[1] = y;
//    *retSize = 2;
//    return ans;
//}
//
//char* robotGetDir(Robot* obj)
//{
//    int w = obj->width, h = obj->height, s = obj->s;
//    if (s < w)
//        return "East";
//    else if (s < w + h - 1)
//        return "North";
//    else if (s < 2 * w + h - 2)
//        return "West";
//
//    return "South";
//}
//
//void robotFree(Robot* obj)
//{
//    free(obj);
//}
//
///**
// * Your Robot struct will be instantiated and called as such:
// * Robot* obj = robotCreate(width, height);
// * robotStep(obj, num);
//
// * int* param_2 = robotGetPos(obj, retSize);
//
// * char* param_3 = robotGetDir(obj);
//
// * robotFree(obj);
//*/
//
////3765. 完全质数
//
//bool isPrime(int x)
//{
//    if (x % 2 == 0)
//        return x == 2;
//    for (int i = 3; i * i <= x; i += 2)
//    {
//        if (x % i == 0)
//            return false;
//    }
//    return x > 1;
//}
//bool completePrime(int num)
//{
//    if (!isPrime(num))
//        return false;
//    int pre = num / 10, suf = num % 10;
//    int base = 10;
//    while (pre)
//    {
//        if (!isPrime(pre))
//            return false;
//        if (!isPrime(suf))
//            return false;
//
//        base *= 10;
//        pre = num / base;
//        suf = num % base;
//    }
//    return true;
//}
//
