//#define _CRT_SECURE_NO_WARNINGS
//
////3065.������ֵ�����ٲ�����I
//
//int minOperations(int* nums, int numsSize, int k)
//{
//    int count = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] >= k)
//            count++;
//    }
//    return numsSize - count;
//}
//
////2798.����Ŀ�깤��ʱ����Ա����Ŀ
//
//int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target)
//{
//    int count = 0;
//    for (int i = 0; i < hoursSize; i++)
//    {
//        if (hours[i] >= target)
//            count++;
//    }
//    return count;
//}
//
////2404.������Ƶ����ż��Ԫ��
//
//int mostFrequentEven(int* nums, int numsSize)
//{
//    int hash[100001] = { 0 };
//    int ret = -1;
//    int count = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (0 == nums[i] % 2)
//        {
//            hash[nums[i]]++;
//            if (hash[nums[i]] > count)
//            {
//                count = hash[nums[i]];
//                ret = nums[i];
//            }
//            else if ((hash[nums[i]] == count) && nums[i] < ret)
//                ret = nums[i];
//        }
//    }
//    return ret;
//}
//
