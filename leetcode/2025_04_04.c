////806. 写字符串需要的行数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//#define MAX_WIDTH 100
//int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = 0; ret[1] = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        int t = widths[s[i] - 'a'];
//        if (ret[1] + t > MAX_WIDTH)
//        {
//            ret[0]++;
//            ret[1] = t;
//        }
//        else
//            ret[1] += t;
//    }
//    ret[0] += ret[1] > 0;
//    returnSize[0] = 2;
//    return ret;
//}
//
////1122. 数组的相对排序
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // int cmp(const void* e1, const void* e2)
// // {
// //     return *(int*)e1 - *(int*)e2;
// // }
// // int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) 
// // {
// //     int left = 0;
// //     for(int i = 0; i < arr2Size; i++)
// //     {
// //         for(int j = left; j < arr1Size; j++)
// //         {
// //             if(arr1[j] == arr2[i])
// //             {
// //                 int tmp = arr1[left];
// //                 arr1[left] = arr1[j];
// //                 arr1[j] = tmp;
// //                 left++;
// //             }
// //         }
// //     }
// //     qsort(&arr1[left], arr1Size - left, sizeof(int), cmp);
// //     returnSize[0] = arr1Size;
// //     return arr1;
// // }
// // int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) 
// // {
// //     int hash[1001] = {0};
// //     int* ret = (int*)malloc(sizeof(int) * arr1Size);
// //     for(int i = 0; i < arr1Size; i++)
// //     {
// //         hash[arr1[i]]++;
// //     }
// //     int n = 0;
// //     for(int i = 0; i < arr2Size; i++)
// //     {
// //         while(hash[arr2[i]])
// //         {
// //             ret[n++] = arr2[i];
// //             hash[arr2[i]]--;
// //         }
// //     }
// //     for(int i = 0; i < 1001; i++)
// //     {
// //         while(hash[i])
// //         {
// //             ret[n++] = i;
// //             hash[i]--;
// //         }
// //     }
// //     returnSize[0] = arr1Size;
// //     return ret;
// // }
//int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
//{
//    int max = 0;
//    for (int i = 0; i < arr1Size; i++)
//    {
//        max = fmax(max, arr1[i]);
//    }
//    int hash[max + 1];
//    memset(hash, 0, sizeof(int) * (max + 1));
//    int* ret = (int*)malloc(sizeof(int) * arr1Size);
//    for (int i = 0; i < arr1Size; i++)
//    {
//        hash[arr1[i]]++;
//    }
//    int n = 0;
//    for (int i = 0; i < arr2Size; i++)
//    {
//        while (hash[arr2[i]])
//        {
//            ret[n++] = arr2[i];
//            hash[arr2[i]]--;
//        }
//    }
//    for (int i = 0; i < max + 1; i++)
//    {
//        while (hash[i])
//        {
//            ret[n++] = i;
//            hash[i]--;
//        }
//    }
//    returnSize[0] = arr1Size;
//    return ret;
//}
//
////1331. 数组序号转换
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct {
//    int index;
//    int val;
//}List;
//int cmp(const void* e1, const void* e2)
//{
//    return ((List*)e1)->val - ((List*)e2)->val;
//}
//int* arrayRankTransform(int* arr, int arrSize, int* returnSize)
//{
//    if (arrSize == 0)
//    {
//        returnSize[0] = 0;
//        return arr;
//    }
//    List* p = (List*)malloc(sizeof(List) * arrSize);
//    for (int i = 0; i < arrSize; i++)
//    {
//        p[i].index = i;
//        p[i].val = arr[i];
//    }
//    qsort(p, arrSize, sizeof(List), cmp);
//    int rank = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        arr[p[i].index] = (i && p[i - 1].val == p[i].val) ? rank : ++rank;
//    }
//    returnSize[0] = arrSize;
//    return arr;
//}
//
////1337. 矩阵中战斗力最弱的 K 行
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct {
//    int val;
//    int index;
//}Line;
//int cmp(const void* e1, const void* e2)
//{
//    return ((Line*)e1)->val - ((Line*)e2)->val;
//}
//int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
//{
//    Line* nums = (Line*)malloc(sizeof(Line) * matSize);
//    for (int i = 0; i < matSize; i++)
//    {
//        nums[i].val = 0;
//        nums[i].index = i;
//    }
//    for (int i = 0; i < matSize; i++)
//    {
//        int left = 0;
//        int right = matColSize[0] - 1;
//        while (left <= right)
//        {
//            int mid = left + ((right - left) >> 1);
//            if (mat[i][mid])
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        nums[i].val = left;
//    }
//    qsort(nums, matSize, sizeof(Line), cmp);
//    int* ret = (int*)malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//    {
//        ret[i] = nums[i].index;
//    }
//    returnSize[0] = k;
//    return ret;
//}
//
