//#define _CRT_SECURE_NO_WARNINGS
//
////1588.所有奇数长度子数组的和
//
//// 1. 暴力
//// int sumOddLengthSubarrays(int* arr, int arrSize) 
//// {
////     int sum = 0;
////     //从起点开始遍历
////     for(int start = 0; start < arrSize; start++)
////     {
////         //限制子数组长度
////         for(int len = 1; start + len <= arrSize; len += 2)
////         {
////             //对每个子数组的元素进行加和
////             int end = start + len - 1;
////             for(int j = i; j <= end; j++)
////             {
////                 sum += arr[j];
////             }
////         }
////     }
////     return sum;
//// }
//// 2.前缀和
//// int sumOddLengthSubarrays(int* arr, int arrSize) 
//// {
////     //定义前缀和数组
////     int* prefixSums = (int*)malloc(sizeof(int) * (arrSize + 1));
////     memset(prefixSums, 0, sizeof(int) * (arrSize + 1));
////     for(int i = 0; i < arrSize; i++)
////     {
////         //计算前缀和, 下标为前缀个数
////         prefixSums[i + 1] = prefixSums[i] + arr[i]; 
////     }
////     int sum = 0;
////     //从起点开始遍历
////     for(int start = 0; start < arrSize; start++)
////     {
//
////         //限制子数组长度
////         for(int len = 1; start + len <= arrSize; len += 2)
////         {
////             //(end + 1)个元素和减去 start 个元素的和，即从start开始的len长度子数组长度
////             int end = start + len - 1;
////             sum += prefixSums[end + 1] - prefixSums[start];
////         }
////     }
////     free(prefixSums);
////     return sum;
//// }
//// 3.数学方法
//int sumOddLengthSubarrays(int* arr, int arrSize)
//{
//    int sum = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        //当前元素左右两边元素个数
//        int leftCount = i;
//        int rightCount = arrSize - 1 - i;
//        //当前元素所处子数组左右两边元素为奇数个
//        int leftOdd = (leftCount + 1) >> 1;
//        int rightOdd = (rightCount + 1) >> 1;
//        //当前元素所处子数组左右两边元素为偶数个
//        int leftEven = 1 + (leftCount >> 1);
//        int rightEven = 1 + (rightCount >> 1);
//
//        sum += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
//    }
//    return sum;
//}
//
////2778.特殊元素平方和
//
//int sumOfSquares(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 1; i * i <= numsSize; i++)
//    {
//        if (0 == numsSize % i)
//        {
//            sum += nums[i - 1] * nums[i - 1];
//            //加对应的因数，防止重复加完全平方根
//            if (i * i < numsSize)
//                sum += nums[numsSize / i - 1] * nums[numsSize / i - 1];
//        }
//    }
//    return sum;
//}
//
////633.平方数之和
//
//bool judgeSquareSum(int c)
//{
//    int right = (int)sqrt(c);
//    int left = (int)sqrt(c - right * right);
//    //printf("left = %d, right = %d\n", left, right);
//    while (left <= right)
//    {
//        long long num = (long long)left * left + right * right;
//        if (c == num)
//            return true;
//        else if (num < c)
//            left++;
//        else
//            right--;
//        //printf("left = %d, right = %d\n", left, right);
//    }
//    return false;
//}
//
////1592.重新排列单词间的空格
//
//char* reorderSpaces(char* text)
//{
//    int len = strlen(text);
//    char* ret = (char*)malloc(sizeof(char) * (len + 1));
//    memset(ret, ' ', sizeof(char) * len);
//    ret[len] = '\0';
//    int blanks = 0;
//    int words = 0;
//    if (text[0] != ' ')
//        words++;
//    for (int i = 0; i < len; i++)
//    {
//        if (text[i] == ' ')
//            blanks++;
//        else
//        {
//            if (i > 0 && text[i - 1] == ' ')
//                words++;
//        }
//    }
//    printf("blanks = %d, words = %d\n", blanks, words);
//    int division = 0;
//    int j = 0;
//    if (words > 1)
//        division = blanks / (words - 1);
//
//    for (int i = 0; i < len; i++)
//    {
//        if (text[i] != ' ')
//            ret[j++] = text[i];
//        else if (i > 0 && text[i - 1] != ' ')
//            j += division;
//    }
//
//    return ret;
//}
//
////1608.特殊数组的特征值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int specialArray(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    for (int i = 1; i <= numsSize; i++)
//    {
//        if (nums[i - 1] >= i && (i == numsSize || nums[i] < i))
//            return i;
//    }
//    return -1;
//}
//
////1619.删除某些元素后的数组均值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//double trimMean(int* arr, int arrSize)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int delete = arrSize / 20;
//    double sum = 0;
//    for (int i = delete; i < arrSize - delete; i++)
//    {
//        sum += arr[i];
//    }
//    return sum / (arrSize - 2 * delete);
//}
