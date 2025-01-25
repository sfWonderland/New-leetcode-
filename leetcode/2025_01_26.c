//#define _CRT_SECURE_NO_WARNINGS
//
////696.计数二进制子串
//int countBinarySubstrings(char* s)
//{
//    int nums[2] = { 0 };
//    int sum = 0;
//    int len = strlen(s);
//    char ch = s[0];
//    for (int i = 0; i < len; i++)
//    {
//        if (ch == s[i])
//        {
//            nums[s[i] - 48]++;
//        }
//        else
//        {
//            sum += nums[0] < nums[1] ? nums[0] : nums[1];
//            nums[s[i] - 48] = 1;
//            ch = s[i];
//            //printf("i = %d, sum = %d\n", i, sum);
//        }
//    }
//    sum += nums[0] < nums[1] ? nums[0] : nums[1];
//    //printf("END, sum = %d\n", sum);
//
//    return sum;
//}
//
////704.二分查找
//
//int search(int* nums, int numsSize, int target)
//{
//    int left = 0;
//    int right = numsSize - 1;
//    while (left <= right)
//    {
//        if (nums[left] != target)
//            left++;
//        else
//            return left;
//        if (nums[right] != target)
//            right--;
//        else
//            return right;
//    }
//    return -1;
//}
//
////2529.正整数和负整数的最大计数
//
//int maximumCount(int* nums, int numsSize)
//{
//    int pos = 0;
//    int neg = 0;
//
//    int left = 0;
//    int right = numsSize - 1;
//    while (left <= right)
//    {
//        if (nums[left] > 0)
//            pos++;
//        else if (nums[left] < 0)
//            neg++;
//
//        if (left != right && nums[right] > 0)
//            pos++;
//        else if (left != right && nums[right] < 0)
//            neg++;
//
//        left++;
//        right--;
//    }
//
//    return pos > neg ? pos : neg;
//}
//
////1351.统计有序矩阵中的负数
//
//int countNegatives(int** grid, int gridSize, int* gridColSize)
//{
//    int n = 0;
//
//    int m = -1;
//    for (int i = gridSize - 1; i >= 0; i--)
//    {
//        int right = *gridColSize - 1;
//        while (right > m)
//        {
//            if (grid[i][right] & INT_MIN)
//            {
//                right--;
//                n++;
//            }
//            else
//            {
//                m = right;
//                break;
//            }
//        }
//    }
//
//    return n;
//}
//
////709.转换成小写字母
//
//char* toLowerCase(char* s)
//{
//    int len = strlen(s);
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] >= 65 && s[i] <= 90)
//            s[i] += 32;
//    }
//    return s;
//}
//
////2129.将标题首字母大写
//
//void lowercase(char* c)
//{
//    if (*c >= 65 && *c <= 90)
//        *c += 32;
//}
//
//void uppercase(char* c)
//{
//    if (*c >= 97 && *c <= 122)
//        *c -= 32;
//}
//
//char* capitalizeTitle(char* title)
//{
//    int len = strlen(title);
//    int left = 0;
//    int right = 0;
//    while (right < len)
//    {
//        while (right < len && title[right] != ' ')
//        {
//            right++;
//        }
//
//        if (right - left > 2)
//        {
//            uppercase(title + left);
//            for (int i = left + 1; i < right; i++)
//                lowercase(title + i);
//        }
//        else
//        {
//            for (int i = left; i < right; i++)
//                lowercase(title + i);
//        }
//        //printf("left = %d, right = %d\n", left, right);
//        right++;
//        left = right;
//    }
//    return title;
//}
//
////717.1比特与2比特字符
//
//bool isOneBitCharacter(int* bits, int bitsSize)
//{
//    int i = 0;
//    while (i < bitsSize - 1)
//    {
//        if (1 == bits[i])
//            i += 2;
//        else
//            i++;
//    }
//    if (i > bitsSize - 1)
//        return false;
//    else
//        return true;
//}
//
////724.寻找数组的中心下标 同1991
//
//int pivotIndex(int* nums, int numsSize)
//{
//    int index = 0;
//    int sumLeft = 0;
//    int sumRight = 0;
//
//    for (int i = 0; i < numsSize; i++)
//        sumRight += nums[i];
//
//    while (index < numsSize)
//    {
//        if (index > 0)
//            sumLeft += nums[index - 1];
//        sumRight -= nums[index];
//        //printf("index = %d, sumLeft = %d, sumRight = %d\n", index, sumLeft, sumRight);
//        if (sumLeft == sumRight)
//            return index;
//        else
//            index++;
//    }
//    return -1;
//}
//
////1013.将数组分成三个相等的部分
//
//bool canThreePartsEqualSum(int* arr, int arrSize)
//{
//    int sumLeft = arr[0];
//    int sumRight = arr[arrSize - 1];
//
//    int sum = 0;
//    for (int i = 0; i < arrSize; i++)
//        sum += arr[i];
//
//    if (sum % 3)
//        return false;
//
//    int average = sum / 3;
//
//    //printf("average = %d\n", average);
//
//    int left = 1;
//    int right = arrSize - 2;
//
//    while (left < right && sumLeft != average)
//    {
//        sumLeft += arr[left];
//        left++;
//    }
//    if (sumLeft != average)
//        return false;
//
//    //printf("sumLeft = %d\n", sumLeft);
//
//    while (left < right && sumRight != average)
//    {
//        sumRight += arr[right];
//        right--;
//    }
//    if (sumRight != average)
//        return false;
//
//    //printf("sumRight = %d\n", sumRight);
//
//    return true;
//}
