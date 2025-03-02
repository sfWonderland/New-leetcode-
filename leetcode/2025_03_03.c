////1720. 解码异或后的数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* decode(int* encoded, int encodedSize, int first, int* returnSize)
//{
//    int n = encodedSize + 1;
//    int* arr = (int*)malloc(sizeof(int) * n);
//    arr[0] = first;
//    for (int i = 1; i < n; i++)
//    {
//        arr[i] = arr[i - 1] ^ encoded[i - 1];
//    }
//    *returnSize = n;
//    return arr;
//}
//
////2433. 找出前缀异或的原始数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findArray(int* pref, int prefSize, int* returnSize)
//{
//    int n = prefSize;
//    for (int i = n - 1; i > 0; i--)
//    {
//        pref[i] ^= pref[i - 1];
//    }
//    *returnSize = n;
//    return pref;
//}
//
////260. 只出现一次的数字 III
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//long lowerbit(long n)
//{
//    return n & (~n + 1);
//}
//int* singleNumber(int* nums, int numsSize, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = 0;
//    ret[1] = 0;
//    long n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        n ^= nums[i];
//    }
//    n = lowerbit(n);
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & n)
//            ret[0] ^= nums[i];
//        else
//            ret[1] ^= nums[i];
//    }
//    *returnSize = 2;
//    return ret;
//}
//
////1710. 卡车上的最大单元数
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e2)[1] - (*(int**)e1)[1];
//}
//int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize)
//{
//    int row = boxTypesSize;
//    qsort(boxTypes, row, sizeof(int*), cmp);
//    int num = 0;
//    for (int i = 0; i < row; i++)
//    {
//        int load = 0;
//        if (boxTypes[i][0] > truckSize)
//        {
//            num += truckSize * boxTypes[i][1];
//            break;
//        }
//        else
//        {
//            num += boxTypes[i][0] * boxTypes[i][1];
//            truckSize -= boxTypes[i][0];
//        }
//    }
//    return num;
//}
//
