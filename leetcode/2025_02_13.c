//#define _CRT_SECURE_NO_WARNINGS
//
////1108.IP地址无效化
//
//char* defangIPaddr(char* address)
//{
//    int len = strlen(address);
//    char* ret = (char*)malloc((len + 7) * sizeof(char));
//    ret[len + 6] = '\0';
//    int j = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (address[i] == '.')
//        {
//            ret[j++] = '[';
//            ret[j++] = '.';
//            ret[j++] = ']';
//            // j += sprintf(ret + j, "%s", "[.]");
//        }
//        else
//            ret[j++] = address[i];
//    }
//    return ret;
//}
//
////1742.盒子中小球的最大数量
//
//int digit_sum(int n)
//{
//    int sum = n % 10;
//    while (n > 9)
//    {
//        n /= 10;
//        sum += n % 10;
//    }
//    return sum;
//}
//int countBalls(int lowLimit, int highLimit)
//{
//    int hash[46] = { 0 };
//    for (int i = lowLimit; i <= highLimit; i++)
//    {
//        hash[digit_sum(i)]++;
//    }
//    int max = hash[0];
//    for (int i = 1; i < 46; i++)
//    {
//        if (max < hash[i])
//            max = hash[i];
//    }
//    return max;
//}
//
////1431.拥有最多糖果的孩子
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
//{
//    bool* ret = (bool*)malloc(sizeof(bool) * candiesSize);
//    memset(ret, 0, sizeof(bool) * candiesSize);
//    int max = candies[0];
//    for (int i = 1; i < candiesSize; i++)
//    {
//        if (max < candies[i])
//            max = candies[i];
//    }
//    for (int i = 0; i < candiesSize; i++)
//    {
//        ret[i] = candies[i] + extraCandies >= max;
//    }
//
//    *returnSize = candiesSize;
//    return ret;
//}
//
////1436.旅行终点站
//
//char* destCity(char*** paths, int pathsSize, int* pathsColSize)
//{
//    for (int i = 0; i < pathsSize; i++)
//    {
//        int j = 0;
//        for (j = 0; j < pathsSize; j++)
//        {
//            if (!strcmp(paths[i][1], paths[j][0]))
//                break;
//        }
//        if (j == pathsSize)
//            return paths[i][1];
//    }
//    return "error";
//}
//
////1437.是否所有1都至少相隔k个元素
//
//bool kLengthApart(int* nums, int numsSize, int k)
//{
//    int i = 0;
//    while (i < numsSize && (!nums[i]))
//        i++;
//    int l = i++;
//    for (; i < numsSize; i++)
//    {
//        if (nums[i])
//        {
//            if (i - l - 1 < k)
//                return false;
//            l = i;
//        }
//    }
//    return true;
//}
//
////1450.在既定时间做作业的学生人数
//
//int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime)
//{
//    int n = 0;
//    for (int i = 0; i < startTimeSize; i++)
//    {
//        if (startTime[i] <= queryTime && endTime[i] >= queryTime)
//            n++;
//    }
//    return n;
//}
//
////1460. 通过翻转子数组使两个数组相等
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool canBeEqual(int* target, int targetSize, int* arr, int arrSize)
//{
//    qsort(target, targetSize, sizeof(int), cmp);
//    qsort(arr, arrSize, sizeof(int), cmp);
//    return memcmp(target, arr, sizeof(int) * arrSize) == 0;
//}
//
////1464.
//
////a.quick sort;
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int maxProduct(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    return (nums[0] - 1) * (nums[1] - 1);
//}
//
////b.select the biggest two numbers
//int maxProduct(int* nums, int numsSize)
//{
//    int a = nums[0];
//    int b = nums[1];
//    if (a < b)
//    {
//        int tmp = a;
//        a = b;
//        b = tmp;
//    }
//    for (int i = 2; i < numsSize; i++)
//    {
//        if (a < nums[i])
//        {
//            b = a;
//            a = nums[i];
//        }
//        else if (b < nums[i])
//            b = nums[i];
//    }
//    return ((a - 1) * (b - 1));
//}
//
////1470.重新排序数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* shuffle(int* nums, int numsSize, int n, int* returnSize)
//{
//    int* arr = (int*)malloc(sizeof(int) * numsSize);
//    memset(arr, 0, sizeof(int) * numsSize);
//    for (int i = 0; i < n; i++)
//    {
//        arr[2 * i] = nums[i];
//        arr[2 * i + 1] = nums[i + n];
//    }
//    *returnSize = numsSize;
//    return arr;
//}
//
////2540.最小公共值
//
//int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int a = 0;
//    int b = 0;
//    while (a < nums1Size && b < nums2Size)
//    {
//        if (nums1[a] == nums2[b])
//            return nums1[a];
//        else if (nums1[a] > nums2[b])
//            b++;
//        else
//            a++;
//    }
//    return -1;
//}
//
////349.两个数组的交集
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    int n = 0;
//    int* ret = (int*)malloc(sizeof(int) * nums1Size);
//    memset(ret, 0, sizeof(int) * nums1Size);
//    int hash[1001] = { 0 };
//    for (int i = 0; i < nums1Size; i++)
//    {
//        hash[nums1[i]]++;
//    }
//    int j = 0;
//    for (int i = 0; i < nums2Size; i++)
//    {
//        if (hash[nums2[i]])
//        {
//            ret[j++] = nums2[i];
//            hash[nums2[i]] = 0;
//        }
//    }
//
//    *returnSize = j;
//    return ret;
//}
//
////350.两个数组的交集
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    if (nums1Size > nums2Size)
//        return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
//
//    int* m = (int*)calloc(1001, sizeof(int));
//    for (int i = 0; i < nums1Size; i++)
//    {
//        m[nums1[i]]++;
//    }
//    int* ret = (int*)malloc(sizeof(int) * nums1Size);
//    memset(ret, 0, sizeof(int) * nums1Size);
//    int index = 0;
//    for (int i = 0; i < nums2Size; i++)
//    {
//        if (m[nums2[i]])
//        {
//            ret[index++] = nums2[i];
//            m[nums2[i]]--;
//        }
//    }
//
//    free(m);
//    *returnSize = index;
//    return ret;
//}
//
