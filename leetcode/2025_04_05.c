////1863. 找出所有子集的异或总和再求和
//
//int subsetXORSum(int* nums, int numsSize)
//{
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        n |= nums[i];
//    }
//    return n << (numsSize - 1);
//}
//
////3115. 质数的最大距离
//
//// bool my_prime(int n)
//// {
////     for(int i = 2; i * i <= n; i++)
////     {
////         if(0 == n % i)
////         return false;
////     }
////     return n == 2;
//// }
//// int maximumPrimeDifference(int* nums, int numsSize) 
//// {
////     int i = 0;
////     while(int i = 0; i < numsSize; i++)
////     {
////         if(my_prime(nums[i]))
////             initial = i;
////     }
////     return ret;
//// }
//
//
//// 全局质数掩码数组
//const uint64_t PRIME_MASK[2] = {
//    0x28208a20a08a28acULL,
//    0x202088288ULL
//};
//
//int maximumPrimeDifference(int* nums, int numsSize)
//{
//    int i = 0;
//    // 找到第一个质数 
//    while (((PRIME_MASK[nums[i] / 64] >> (nums[i] % 64)) & 1) == 0)
//        i++;
//
//    int j = numsSize - 1;
//    // 找到最后一个质数 
//    while (((PRIME_MASK[nums[j] / 64] >> (nums[j] % 64)) & 1) == 0)
//        j--;
//
//    return j - i;
//}
//
////2293. 极大极小游戏
//
//int minMaxGame(int* nums, int numsSize)
//{
//    int n = numsSize;
//    while (n != 1)
//    {
//        int flag = -1;
//        int num = 0;
//        for (int i = 0; i < n; i += 2)
//        {
//            nums[num++] = flag == 1 ? fmax(nums[i], nums[i + 1]) : fmin(nums[i], nums[i + 1]);
//            flag = -flag;
//        }
//        n /= 2;
//    }
//    return nums[0];
//}
//
//
////2303. 计算应缴税款总额
//
//double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income)
//{
//    if (income <= brackets[0][0])
//        return income * brackets[0][1] / 100.0;
//    double tax = brackets[0][0] * brackets[0][1] / 100.0;;
//    for (int i = 1; i < bracketsSize; i++)
//    {
//        if (income > brackets[i][0])
//            tax += (brackets[i][0] - brackets[i - 1][0]) * brackets[i][1] / 100.0;
//        else
//        {
//            tax += (income - brackets[i - 1][0]) * brackets[i][1] / 100.0;
//            break;
//        }
//    }
//    return tax;
//}
//
