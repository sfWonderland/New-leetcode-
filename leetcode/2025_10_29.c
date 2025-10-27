////3069. 将元素分配到两个数组中 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* resultArray(int* nums, int numsSize, int* returnSize)
//{
//    int* arr1 = (int*)malloc(sizeof(int) * numsSize);
//    int* arr2 = (int*)malloc(sizeof(int) * numsSize);
//    arr1[0] = nums[0], arr2[0] = nums[1];
//    int idx1 = 0, idx2 = 0;
//    for (int i = 2; i < numsSize; i++)
//    {
//        if (arr1[idx1] > arr2[idx2])
//        {
//            arr1[++idx1] = nums[i];
//        }
//        else
//        {
//            arr2[++idx2] = nums[i];
//        }
//    }
//    for (int i = 0; i <= idx2; i++)
//    {
//        arr1[++idx1] = arr2[i];
//    }
//    *returnSize = numsSize;
//    return arr1;
//}
//
////537. 复数乘法
//
//bool parseComplexNumber(const char* num, int* real, int* image)
//{
//    char* token = strtok(num, "+");
//    *real = atoi(token);
//    token = strtok(NULL, "i");
//    *image = atoi(token);
//    return true;
//}
//char* complexNumberMultiply(char* num1, char* num2)
//{
//    int real1 = 0, image1 = 0;
//    int real2 = 0, image2 = 0;
//    parseComplexNumber(num1, &real1, &image1);
//    parseComplexNumber(num2, &real2, &image2);
//    char* ans = (char*)malloc(sizeof(char) * 20);
//    snprintf(ans, 20, "%d+%di", real1 * real2 - image1 * image2, real1 * image2 + image1 * real2);
//    return ans;
//}
//
////2562. 找出数组的串联值
//
//long long findTheArrayConcVal(int* nums, int numsSize)
//{
//    int left = 0, right = numsSize - 1;
//    long long ans = 0;
//    while (left < right)
//    {
//        int x = nums[left];
//        int y = nums[right];
//        while (y)
//        {
//            x *= 10;
//            y /= 10;
//        }
//        ans += x + nums[right];
//        left++;
//        right--;
//    }
//
//    if (left == right)
//        ans += nums[left];
//
//    return ans;
//}
//
////LCP 50. 宝石补给
//
//int giveGem(int* gem, int gemSize, int** operations, int operationsSize, int* operationsColSize)
//{
//    for (int i = 0; i < operationsSize; i++)
//    {
//        int gift = gem[operations[i][0]] / 2;
//        gem[operations[i][0]] -= gift;
//        gem[operations[i][1]] += gift;
//    }
//    int max = 0, min = 1001;
//    for (int i = 0; i < gemSize; i++)
//    {
//        max = fmax(gem[i], max);
//        min = fmin(gem[i], min);
//    }
//    return max - min;
//}
//
