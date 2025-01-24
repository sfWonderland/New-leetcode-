//#define _CRT_SECURE_NO_WARNINGS
//
////598.区间加法II
//int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize)
//{
//    int row = m;
//    int col = n;
//    for (int i = 0; i < opsSize; i++)
//    {
//        if (row > ops[i][0])
//            row = ops[i][0];
//        if (col > ops[i][1])
//            col = ops[i][1];
//    }
//    return row * col;
//}
//
////628.三个数的最大乘积
//
//int maximumProduct(int* nums, int numsSize)
//{
//    // 最小的和第二小的
//    int min1 = INT_MAX, min2 = INT_MAX;
//    // 最大的、第二大的和第三大的
//    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        if (x < min1) {
//            min2 = min1;
//            min1 = x;
//        }
//        else if (x < min2) {
//            min2 = x;
//        }
//
//        if (x > max1) {
//            max3 = max2;
//            max2 = max1;
//            max1 = x;
//        }
//        else if (x > max2) {
//            max3 = max2;
//            max2 = x;
//        }
//        else if (x > max3) {
//            max3 = x;
//        }
//    }
//
//    return fmax(min1 * min2 * max1, max1 * max2 * max3);
//}
//
////643.子数组的最大平均数I
//
//double findMaxAverage(int* nums, int numsSize, int k)
//{
//    double max = INT_MIN;
//    double sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i < k - 1)
//            sum += nums[i];
//        else
//        {
//            if (i == k - 1)
//                sum += nums[i];
//            else
//                sum += nums[i] - nums[i - k];
//            if (sum > max)
//                max = sum;
//            //printf("sum = %d\n", sum);
//        }
//    }
//    //printf("max = %d\n", max);
//    return max / k;
//}
//
////657.机器人能否返回原点
//
//bool judgeCircle(char* moves)
//{
//    int horizonal = 0;
//    int vertical = 0;
//    int len = strlen(moves);
//    for (int i = 0; i < len; i++)
//    {
//        //horizonal
//        if (moves[i] == 'R' || moves[i] == 'L')
//        {
//            if (moves[i] == 'R')
//                horizonal++;
//            else
//                horizonal--;
//        }
//        //vertical
//        if (moves[i] == 'U' || moves[i] == 'D')
//        {
//            if (moves[i] == 'U')
//                vertical++;
//            else
//                vertical--;
//        }
//    }
//
//    if ((!horizonal) && (!vertical))
//        return true;
//    else
//        return false;
//}
//
////2833.距离原点最远的点
//
//int furthestDistanceFromOrigin(char* moves)
//{
//    int left = 0;
//    int right = 0;
//    int underline = 0;
//    for (int i = 0; i < strlen(moves); i++)
//    {
//        if (moves[i] == 'L')
//            left++;
//        else if (moves[i] == 'R')
//            right++;
//        else
//            underline++;
//    }
//
//    return abs(left - right) + underline;
//}
//
////680. 验证回文串II
//
//bool is_Palindrome(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        if (s[left] == s[right])
//        {
//            left++;
//            right--;
//        }
//        else
//            return false;
//    }
//    return true;
//}
//bool validPalindrome(char* s)
//{
//    int left = 0;
//    int right = strlen(s) - 1;
//    int flag = 1;
//    while ((left < right) && (s[left] == s[right]))
//    {
//        left++;
//        right--;
//    }
//
//    if (left < right)
//    {
//        if ((is_Palindrome(s, left, right - 1)) || (is_Palindrome(s, left + 1, right)))
//            return true;
//        else
//            return false;
//    }
//
//    return true;
//}
//
////674.最长连续递增序列
//
//int findLengthOfLCIS(int* nums, int numsSize)
//{
//    int sum = 1;
//    int i = 0;
//    while (i < numsSize)
//    {
//        int len = 1;
//        for (i = i + 1; i < numsSize; i++)
//        {
//            if (nums[i] > nums[i - 1])
//                len++;
//            else
//                break;
//        }
//        if (len > sum)
//            sum = len;
//    }
//    return sum;
//}
//
////1446.连续字符
//
//int maxPower(char* s)
//{
//    int len = strlen(s);
//    int sum = 1;
//    int len1 = 1;
//    for (int i = 1; i < len; i++)
//    {
//        if (s[i] == s[i - 1])
//            len1++;
//        else
//        {
//            if (len1 > sum)
//                sum = len1;
//            len1 = 1;
//        }
//    }
//
//    if (len1 > sum)
//        return len1;
//
//    return sum;
//}
//
////693.交替位二进制数
//
//bool hasAlternatingBits(int n)
//{
//    if (n > 0x55555555)
//        return false;
//    else if (0x55555555 == n)
//        return true;
//
//    int test = n + n / 2 + 1;
//    if (!(test & (test - 1)))
//        return true;
//    else
//        return false;
//}
//
////682.棒球比赛
//
//int calPoints(char** operations, int operationsSize)
//{
//    int nums[operationsSize + 1];
//    for (int i = 0; i <= operationsSize; i++)
//    {
//        nums[i] = 0;
//    }
//    int k = 0;
//    for (int i = 0; i < operationsSize; i++)
//    {
//        if ('+' == operations[i][0])
//        {
//            k++;
//            nums[k] = nums[k - 2] + nums[k - 1];
//        }
//        else if ('D' == operations[i][0])
//        {
//            k++;
//            nums[k] = 2 * nums[k - 1];
//        }
//        else if ('C' == operations[i][0])
//        {
//            nums[k] = 0;
//            k--;
//        }
//        else
//        {
//            k++;
//            int flag = 0;
//            if ('-' == operations[i][0])
//                flag = 1;
//            for (int j = 0; j < strlen(operations[i]); j++)
//            {
//                if (0 == j && flag)
//                    j++;
//                nums[k] *= 10;
//                nums[k] += operations[i][j] - 48;
//            }
//            if (flag)
//                nums[k] *= -1;
//        }
//    }
//
//    int sum = 0;
//    for (int i = 0; i <= k; i++)
//    {
//        sum += nums[i];
//    }
//
//    return sum;
//}