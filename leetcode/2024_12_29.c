#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include<stdbool.h>

//27.�Ƴ�Ԫ��
//int removeElement(int* nums, int numsSize, int val) {
//    int i = 0;
//    int num = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            nums[num] = nums[i];
//            num++;
//        }
//    }
//    return num;
//}
//
//int main()
//{
//    int nums[] = { 0,0,1,1,1,2,2,3,3,4 }; // ��������
//    int val = 3;
//    int expectedNums[] = { 0,0,1,1,1,2,2,4 }; // ������ȷ��������
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    int k = removeElement(nums, numsSize, val); // ����
//
//   assert(k == 8);
//    for (int i = 0; i < k; i++) 
//    {
//        assert(nums[i] == expectedNums[i]);
//    }
//    return 0;
//}

//28.�ҳ��ַ����е�һ��ƥ������±�
//int strStr(char* haystack, char* needle) 
//{
//	int len1 = strlen(haystack);
//	int len2 = strlen(needle);
//	int i = 0;
//	int ret = -1;
//	for (i = 0; i < len1 - len2 + 1; i++)
//	{
//		int flag = 1;
//		for (int j = i; j < i + len2; j++)
//		{
//			if (haystack[j] != needle[j - i])
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//		{
//			ret = i;
//			break;
//		}
//	}
//	return ret;
//}

