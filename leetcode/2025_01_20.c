//#define _CRT_SECURE_NO_WARNINGS
//
////2239.找到最接近0的数字
//
//int findClosestNumber(int* nums, int numsSize)
//{
//    int ret = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (abs(nums[i]) < abs(ret))
//            ret = nums[i];
//        else if (abs(nums[i]) == abs(ret) && nums[i] > ret)
//            ret = nums[i];
//        //printf("ret = %d\n", ret);
//    }
//    return ret;
//}
//
////392.判断子序列
//bool isSubsequence(char* s, char* t)
//{
//    int lens = strlen(s);
//    int lent = strlen(t);
//    int i = 0;
//    int j = 0;
//    while (i < lens && j < lent)
//    {
//        if (t[j] == s[i])
//            i++;
//        j++;
//    }
//    return i == lens ? true : false;
//}
//
////476.数字的补数
//int findComplement(int num)
//{
//    int t = 0;
//    int tmp = num;
//    while (tmp)
//    {
//        tmp >>= 1;
//        t++;
//    }
//    if (t < 31)
//        return (1 << t) - num - 1;
//    else
//        return num ^ 0x7fffffff;
//}
//
////485.最大连续1的个数
//
//int findMaxConsecutiveOnes(int* nums, int numsSize)
//{
//    int count1 = 0;
//    int count2 = 0;
//    int record = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        count2 = count1;
//        count1 += nums[i];
//        if (count1 == count2)
//        {
//            if (record < count2)
//                record = count2;
//            count1 = 0;
//        }
//        //printf("i = %d, record1 = %d, record2 = %d\n", i, count1, count2);
//    }
//    if (record < count1)
//        return count1;
//    return record;
//}