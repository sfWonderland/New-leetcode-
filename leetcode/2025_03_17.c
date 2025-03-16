////1768. 交替合并字符串
//
//char* mergeAlternately(char* word1, char* word2)
//{
//    int len1 = strlen(word1);
//    int len2 = strlen(word2);
//    char* ret = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
//    ret[len1 + len2] = '\0';
//    int i = 0;
//    int j = 0;
//    while (i < len1 || i < len2)
//    {
//        if (i < len1)
//            ret[j++] = word1[i];
//        if (i < len2)
//            ret[j++] = word2[i];
//        i++;
//    }
//    return ret;
//}
//
////1957. 删除字符使字符串变好
//
//char* makeFancyString(char* s)
//{
//    int slow = 0;
//    int cnt = 1;
//    for (int i = 0; s[i]; i++)
//    {
//        if (3 == cnt)
//        {
//            cnt--;
//            slow--;
//        }
//        if (s[i] == s[i + 1])
//            cnt++;
//        else
//            cnt = 1;
//        s[slow++] = s[i];
//    }
//    s[slow] = '\0';
//    return s;
//}
//
////1913. 两个数对之间的最大乘积差
//
//int maxProductDifference(int* nums, int numsSize)
//{
//    int max1 = 0;
//    int max2 = 0;
//    int min1 = 10001;
//    int min2 = 10001;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > max1)
//        {
//            max2 = max1;
//            max1 = nums[i];
//        }
//        else if (nums[i] > max2)
//            max2 = nums[i];
//        if (nums[i] < min1)
//        {
//            min2 = min1;
//            min1 = nums[i];
//        }
//        else if (nums[i] < min2)
//            min2 = nums[i];
//    }
//    return max1 * max2 - min1 * min2;
//}
//
////LCR 072. x 的平方根
//
//// int mySqrt(int x)
//// {
////     int left = 0;
////     int right = x;
////     while(left <= right)
////     {
////         int mid = left + ((right - left) >> 1);
////         while(mid > 46340)
////         {
////             right = mid - 1;
////             mid = left + ((right - left) >> 1);
////         }
////         int square = mid * mid;
////         if(square == x)
////         return mid;
////         else if(square > x)
////         right = mid - 1;
////         else
////         left = mid + 1;
////     }
////     return left - 1;
//// }
//
//int mySqrt(int x)
//{
//    if (0 == x)
//        return 0;
//
//    double C = x, x0 = x;
//    while (1)
//    {
//        double xi = 0.5 * (x0 + C / x0);
//        if (fabs(x0 - xi) < 1e-7)
//            break;
//        x0 = xi;
//    }
//    //printf("%lf", x0);
//    return (int)x0;
//}
//
