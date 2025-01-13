//#define _CRT_SECURE_NO_WARNINGS
//
////409.最长的回文串
//
//int longestPalindrome(char* s)
//{
//    int alpha[52] = { 0 };
//    int len = strlen(s);
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] >= 'A' && s[i] <= 'Z')
//            alpha[s[i] - 'A']++;
//        if (s[i] >= 'a' && s[i] <= 'z')
//            alpha[s[i] - 'a' + 26]++;
//    }
//
//    int sum = 0;
//    for (int j = 0; j < 52; j++)
//    {
//        if (alpha[j] / 2)
//            sum += alpha[j] - alpha[j] % 2;
//    }
//    if (sum < len)
//        sum++;
//    return sum;
//}
//
////414.第三大的数
//
//int thirdMax(int* nums, int numsSize)
//{
//    if (1 == numsSize)
//        return nums[0];
//    else if (2 == numsSize)
//        return nums[0] > nums[1] ? nums[0] : nums[1];
//    else
//    {
//        int max1 = 0x80000000;
//        int max2 = 0x80000000;
//        int max3 = 0x80000000;
//        int flag = 1;
//        for (int i = 0; i < numsSize; i++)
//        {
//            if (nums[i] >= max1)
//            {
//                if (nums[i] > max1)
//                {
//                    max3 = max2;
//                    max2 = max1;
//                    max1 = nums[i];
//                }
//                else if (nums[i] == 0x80000000)
//                    flag = 0;
//            }
//            else if (nums[i] >= max2)
//            {
//                if (nums[i] > max2)
//                {
//                    max3 = max2;
//                    max2 = nums[i];
//                }
//                else if (nums[i] == 0x80000000)
//                    flag = 0;
//            }
//            else if (nums[i] >= max3)
//            {
//                if (nums[i] == 0x80000000)
//                    flag = 0;
//                max3 = nums[i];
//            }
//
//        }
//        if (0x80000000 == max2)
//            return max1;
//        else if (0x80000000 == max3 && flag)
//            return max1;
//        else
//            return max3;
//    }
//}
//
////2733.既不是最小值也不是最大值
//
//int findNonMinOrMax(int* nums, int numsSize)
//{
//    if (numsSize < 3)
//        return -1;
//    else
//    {
//        int min = 100;
//        int max = 0;
//        for (int i = 0; i < numsSize; i++)
//        {
//            if (nums[i] > max)
//                max = nums[i];
//            if (nums[i] < min)
//                min = nums[i];
//        }
//        for (int i = 0; i < numsSize; i++)
//        {
//            if (nums[i] != min && nums[i] != max)
//            {
//                return nums[i];
//            }
//        }
//        return -1;
//    }
//}