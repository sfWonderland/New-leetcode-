//#define _CRT_SECURE_NO_WARNINGS
//
/////1475.��Ʒ�ۿۺ�����ռ۸�
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* finalPrices(int* prices, int pricesSize, int* returnSize)
//{
//    for (int i = 0; i < pricesSize; i++)
//    {
//        for (int j = i + 1; j < pricesSize; j++)
//        {
//            if (prices[i] >= prices[j])
//            {
//                prices[i] -= prices[j];
//                break;
//            }
//        }
//    }
//    *returnSize = pricesSize;
//    return prices;
//}
//
////1480.һά����Ķ�̬��
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* runningSum(int* nums, int numsSize, int* returnSize)
//{
//    for (int i = 1; i < numsSize; i++)
//    {
//        nums[i] += nums[i - 1];
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////1304.��Ϊ���N����ͬ����
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* sumZero(int n, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * n);
//    int m = n / 2;
//    if (n % 2)
//        ret[n - 1] = 0;
//
//    for (int i = 0; i < m; i++)
//    {
//        ret[2 * i] = i + 1;
//        ret[2 * i + 1] = -1 - i;
//    }
//    *returnSize = n;
//    return ret;
//}
//
////1491.ȥ����͹��ʺ���߹��ʺ�Ĺ���
//
//double average(int* salary, int salarySize)
//{
//    int max = salary[0];
//    int min = salary[0];
//    int sum = salary[0];
//    for (int i = 1; i < salarySize; i++)
//    {
//        if (max < salary[i])
//            max = salary[i];
//        if (min > salary[i])
//            min = salary[i];
//
//        sum += salary[i];
//    }
//    sum -= min + max;
//    return (sum + 0.0) / (salarySize - 2);
//}