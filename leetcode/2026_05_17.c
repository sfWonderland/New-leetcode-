//// 3931. 检查相邻数字差
//
//bool isAdjacentDiffAtMostTwo(char* s)
//{
//    for (int i = 1; s[i]; i++)
//    {
//        if (abs(s[i] - s[i - 1]) > 2)
//            return false;
//    }
//    return true;
//}
//
//// 3932. 统计区间内的完全 K 次幂数量    
//
//int lower_bound(int n, int k)
//{
//    int left = 0, right = pow(n, 1.0 / k) + 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (pow(mid, k) >= n)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return pow(left, k) > n ? left - 1 : left;
//}
//int countKthRoots(int l, int r, int k)
//{
//    return lower_bound(r, k) - lower_bound(l - 1, k);
//}
//
//// 面试题 16.08. 整数的英语表示
//
//const char* singles[10] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
//const char* teens[10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
//const char* tens[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
//const char* thousands[4] = { "", "Thousand", "Million", "Billion" };
//char* hun = "Hundred ";
//char* recursion(int num)
//{
//    char* s = (char*)malloc(sizeof(char) * 40);
//    s[0] = '\0';
//    if (num == 0)
//        return s;
//    else if (num < 10)
//    {
//        int pos = 0;
//        for (int i = 0; singles[num][i]; i++)
//        {
//            s[pos++] = singles[num][i];
//        }
//        s[pos++] = ' ';
//        s[pos] = '\0';
//    }
//    else if (num < 20)
//    {
//        int pos = 0;
//        int d = num - 10;
//        for (int i = 0; teens[d][i]; i++)
//        {
//            s[pos++] = teens[d][i];
//        }
//        s[pos++] = ' ';
//        s[pos] = '\0';
//    }
//    else if (num < 100)
//    {
//        int pos = 0;
//        int d = num / 10;
//        for (int i = 0; tens[d][i]; i++)
//        {
//            s[pos++] = tens[d][i];
//        }
//        s[pos++] = ' ';
//        char* t = recursion(num % 10);
//        for (int i = 0; t[i]; i++)
//        {
//            s[pos++] = t[i];
//        }
//        free(t);
//        s[pos] = '\0';
//    }
//    else
//    {
//        int pos = 0;
//        char* t1 = recursion(num / 100);
//        for (int i = 0; t1[i]; i++)
//        {
//            s[pos++] = t1[i];
//        }
//        free(t1);
//        for (int i = 0; hun[i]; i++)
//        {
//            s[pos++] = hun[i];
//        }
//        char* t2 = recursion(num % 100);
//        for (int i = 0; t2[i]; i++)
//        {
//            s[pos++] = t2[i];
//        }
//        free(t2);
//        s[pos] = '\0';
//    }
//    return s;
//}
//char* numberToWords(int num)
//{
//    if (num == 0)
//        return "Zero";
//    char* s = (char*)malloc(sizeof(char) * 200);
//    int pos = 0;
//    int unit = (int)1e9;
//    for (int k = 3; k >= 0; k--)
//    {
//        int curNum = num / unit;
//        if (curNum)
//        {
//            num -= curNum * unit;
//            char* t = recursion(curNum);
//            for (int i = 0; t[i]; i++)
//            {
//                s[pos++] = t[i];
//            }
//            for (int i = 0; thousands[k][i]; i++)
//            {
//                s[pos++] = thousands[k][i];
//            }
//            s[pos++] = ' ';
//        }
//        unit /= 1000;
//    }
//    while (s[pos - 1] == ' ')
//        pos--;
//    s[pos] = '\0';
//    return s;
//}
//
//// 面试题 16.11. 跳水板
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* divingBoard(int shorter, int longer, int k, int* returnSize)
//{
//    if (k == 0)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//
//    if (shorter == longer)
//    {
//        int* ans = (int*)malloc(sizeof(int));
//        ans[0] = k * shorter;
//        *returnSize = 1;
//        return ans;
//    }
//
//    int* ans = (int*)malloc(sizeof(int) * (k + 1));
//    for (int i = 0; i <= k; i++)
//    {
//        ans[i] = longer * i + shorter * (k - i);
//    }
//    *returnSize = k + 1;
//    return ans;
//}
//
