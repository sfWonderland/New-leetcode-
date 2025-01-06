//#define _CRT_SECURE_NO_WARNINGS
//
////136.只出现一次的数字
//
//int singleNumber(int* nums, int numsSize) 
//{
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ret ^= nums[i];
//    }
//    return ret;
//}
//
////268.丢失的数字
//
//int missingNumber(int* nums, int numsSize)
//{
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ret ^= nums[i] ^ i;
//    }
//    ret ^= numsSize;
//    return ret;
//}
//
////389.找不同
//
//char findTheDifference(char* s, char* t)
//{
//    int len = strlen(s);
//    char ret = 0;
//    for (int i = 0; i < len; i++)
//    {
//        ret ^= s[i] ^ t[i];
//    }
//    ret ^= t[len];
//    return ret;
//}
//
////3158.求出现两次数字的XOR值
//
//int duplicateNumbersXOR(int* nums, int numsSize) 
//{
//    int ret = 0;
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < numsSize)
//    {
//        if ((nums[left] == nums[right]) && (left < right))
//        {
//            ret ^= nums[left];
//            nums[left] = 0;
//            nums[right] = 0;
//            left++;
//            right = numsSize - 1;
//        }
//        else
//        {
//            right--;
//        }
//        if (!nums[left] || left >= right)
//        {
//            left++;
//            right = numsSize - 1;
//        }
//    }
//    return ret;
//}
//
////169. 多数元素
//int majorityElement(int* nums, int numsSize) 
//{
//    int ret = 0x7fffffff;
//    int count = 0;
//    if (1 == numsSize)
//        ret = nums[0];
//    int n = 0;
//    while (ret == 0x7fffffff)
//    {
//        for (int i = numsSize - 1; i >= n; i--)
//        {
//            if (nums[n] == nums[i])
//            {
//                count++;
//                if (count > numsSize / 2)
//                {
//                    ret = nums[n];
//                    break;
//                }
//                nums[i] = 0x7ffffffe;
//            }
//        }
//        n++;
//        while (ret == 0x7fffffff && n < numsSize / 2 && nums[n] == 0x7ffffffe)
//            n++;
//        count = 0;
//    }
//    return ret;
//}