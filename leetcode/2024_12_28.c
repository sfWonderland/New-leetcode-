#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

//删除无序数组中的重复项
//int removeDuplicates(int* nums, int numsSize)
//{
//    int i = 0;
//    int num = 1;
//    for (i = 0; i < numsSize; i++)
//    {
//        num = i + 1;
//        for (int j = i + 1; j < numsSize; j++)
//        {
//            if (nums[i] != nums[j])
//            {
//                nums[num] = nums[j];
//                num++;
//            }
//        }
//        numsSize = num;
//       // printf("i = %d\n", i);
//        //for (int j = 0; j < numsSize; j++)
//        //{
//            //printf("%d ", nums[j]);
//        //}
//        //printf("\n");
//        //printf("num = %d\n", num);
//    }
//    //printf("num = %d\n", num);
//    return num;
//}
//
//int main()
//{
//    int nums[] = { 0,0,1,1,1,2,2,3,3,4 }; // 输入数组
//    int expectedNums[] = { 0, 1, 2, 3, 4 }; // 长度正确的期望答案
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    int k = removeDuplicates(nums, numsSize); // 调用
//
//   assert(k == 5);
//    for (int i = 0; i < k; i++) 
//    {
//        assert(nums[i] == expectedNums[i]);
//    }
//    return 0;
//}