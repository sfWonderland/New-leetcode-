//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//
////242.有效的字母异位词
//
//bool isAnagram(char* s, char* t)
//{
//    int len1 = strlen(s);
//    int len2 = strlen(t);
//    if (len1 != len2)
//        return false;
//    else
//    {
//        int arr1[26] = { 0 };
//        int arr2[26] = { 0 };
//        for (int i = 0; i < len1; i++)
//        {
//            arr1[s[i] - 'a']++;
//            arr2[t[i] - 'a']++;
//        }
//
//        for (int i = 0; i < 26; i++)
//        {
//            if (arr1[i] != arr2[i])
//            {
//                return false;
//                break;
//            }
//        }
//        return true;
//    }
//}
//
////283.移动零
//
//void moveZeroes(int* nums, int numsSize)
//{
//    int ps = numsSize - 1;
//    int pe = numsSize - 1;
//    while (pe >= 0 && 0 == nums[pe])
//        pe--;
//    ps = pe;
//    for (ps = pe; ps >= 0; ps--)
//    {
//        if (0 == nums[ps])
//        {
//            //printf("nums[%d] = 0\n", ps);
//            for (int i = ps; i < pe; i++)
//            {
//                int tmp = nums[i];
//                nums[i] = nums[i + 1];
//                nums[i + 1] = tmp;
//            }
//            pe--;
//        }
//    }
//}