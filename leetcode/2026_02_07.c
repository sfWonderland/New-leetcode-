////1653. 使字符串平衡的最少删除次数
//
//int minimumDeletions(char* s)
//{
//    int n = strlen(s);
//    int cntB[n];
//    cntB[0] = s[0] - 'a';
//    for (int i = 1; i < n; i++)
//    {
//        cntB[i] = cntB[i - 1] + s[i] - 'a';
//    }
//    int dfs(int i)
//    {
//        if (i < 0)
//            return 0;
//
//        if (s[i] - 'a')
//            return dfs(i - 1);
//
//        return fmin(cntB[i], dfs(i - 1) + 1);
//    }
//    return dfs(n - 1);
//}
//
//int minimumDeletions(char* s)
//{
//    int cntB = 0, f = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] - 'a')
//            cntB++;
//        else
//            f = fmin(f + 1, cntB);
//    }
//    return f;
//}
//
//int minimumDeletions(char* s)
//{
//    int del = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        del += 'b' - s[i];
//    }
//    int ans = del;
//    for (int i = 0; s[i]; i++)
//    {
//        del += s[i] == 'b' ? 1 : -1;
//        ans = fmin(ans, del);
//    }
//    return ans;
//}
//
////43. 字符串相乘    
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//void sumUp(char* sum, char* num, int d, int n)
//{
//    int upgrade = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        int s = sum[i + d] - '0' + num[i] - '0' + upgrade;
//        upgrade = s / 10;
//        sum[i + d] = s % 10 + '0';
//    }
//}
//char* multiply(char* num1, char* num2)
//{
//    int m = strlen(num1);
//    int n = strlen(num2);
//    int len = m + n + 1;
//    char* ret = (char*)malloc(sizeof(char) * len);
//    memset(ret, '0', sizeof(char) * len);
//    ret[len - 1] = '\0';
//    int sum = 0;
//    char* num = (char*)malloc(sizeof(char) * (n + 2));
//    memset(num, 0, sizeof(char) * (n + 2));
//    for (int i = m - 1; i >= 0; i--)
//    {
//        int a_bit = num1[i] - '0';
//        int upgrade = 0;
//        for (int j = n - 1; j >= 0; j--)
//        {
//            int b_bit = num2[j] - '0';
//            int bit_multi = a_bit * b_bit + upgrade;
//            num[n - 1 - j] = bit_multi % 10 + '0';
//            upgrade = bit_multi / 10;
//            //printf("b_bit = %d, bit_multi = %d, sum = %d\n", b_bit, bit_multi, dsum);
//        }
//        num[n] = upgrade + '0';
//        reverse(num, 0, n);
//        //printf("%s\n", num);
//        sumUp(ret, num, i, n + 1);
//        //printf("%s\n", ret);
//        memset(num, 0, sizeof(char) * (n + 2));
//    }
//    //printf("%s\n", ret);
//    int i = 0;
//    while (i < len - 2 && ret[i] == '0')
//        i++;
//
//    return ret + i;
//}
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//void sumUp(char* sum, char* num, int d, int n)
//{
//    int upgrade = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        int s = sum[i + d] - '0' + num[i] - '0' + upgrade;
//        upgrade = s / 10;
//        sum[i + d] = s % 10 + '0';
//    }
//}
//char* multiply(char* num1, char* num2)
//{
//    int m = strlen(num1);
//    int n = strlen(num2);
//    int len = m + n + 1;
//    char* ret = (char*)malloc(sizeof(char) * len);
//    memset(ret, '0', sizeof(char) * len);
//    ret[len - 1] = '\0';
//    int sum = 0;
//    char** nums = (char**)malloc(sizeof(char*) * 10);
//    nums[0] = (char*)malloc(sizeof(char) * (n + 2));
//    memset(nums[0], '0', sizeof(char) * (n + 2));
//    nums[0][n + 1] = '\0';
//    for (int i = 1; i < 10; i++)
//    {
//        nums[i] = (char*)malloc(sizeof(char) * (n + 2));
//        memset(nums[i], 0, sizeof(char) * (n + 2));
//        int upgrade = 0;
//        for (int j = n - 1; j >= 0; j--)
//        {
//            int b_bit = num2[j] - '0';
//            int bit_multi = i * b_bit + upgrade;
//            nums[i][n - 1 - j] = bit_multi % 10 + '0';
//            upgrade = bit_multi / 10;
//        }
//        nums[i][n] = upgrade + '0';
//        reverse(nums[i], 0, n);
//    }
//    for (int i = m - 1; i >= 0; i--)
//    {
//        int a_bit = num1[i] - '0';
//        int upgrade = 0;
//        sumUp(ret, nums[a_bit], i, n + 1);
//    }
//    //printf("%s\n", ret);
//    int i = 0;
//    while (i < len - 2 && ret[i] == '0')
//        i++;
//
//    for (int i = 0; i < 10; i++)
//    {
//        free(nums[i]);
//    }
//    free(nums);
//    return ret + i;
//}
//
////38. 外观数列
//
//char* countAndSay(int n)
//{
//    if (n == 1)
//        return "1";
//
//    char* s = countAndSay(n - 1);
//    int m = strlen(s);
//    char* ans = (char*)malloc(sizeof(char) * (2 * m + 1));
//    int idx = 0, cnt = 1;
//    for (int i = 0; i < m - 1; i++)
//    {
//        if (s[i] == s[i + 1])
//            cnt++;
//        else
//        {
//            ans[idx++] = cnt + '0';
//            ans[idx++] = s[i];
//            cnt = 1;
//        }
//    }
//    ans[idx++] = cnt + '0';
//    ans[idx++] = s[m - 1];
//
//    ans[idx] = '\0';
//    return ans;
//}
//
////393. UTF-8 编码验证
//
//char* numToStr(int n)
//{
//    char* ret = (char*)malloc(sizeof(char) * 9);
//    ret[8] = '\0';
//    int i = 7;
//    while (n)
//    {
//        ret[i--] = (n & 1) + '0';
//        n >>= 1;
//    }
//    for (int j = 0; j <= i; j++)
//    {
//        ret[j] = '0';
//    }
//    return ret;
//}
//int check(int n)
//{
//    char* s = numToStr(n);
//    //printf("%s\n", s);
//    int i = 0;
//    while (s[i] == '1')
//        i++;
//    return i;
//}
//bool validUtf8(int* data, int dataSize)
//{
//    int limit = 0;
//    for (int i = 0; i < dataSize; i++)
//    {
//        int c = check(data[i]);
//        //printf("%d ", c);
//        if (limit == 0)
//        {
//            if (c != 1 && c <= 4)
//                limit = fmax(0, c - 1);
//            else
//                return false;
//        }
//        else if (c == 1)
//            limit--;
//        else
//            return false;
//        //printf("%d\n", limit);
//    }
//    return !limit;
//}
//
//bool validUtf8(int* data, int dataSize)
//{
//    int limit = 0;
//    for (int i = 0; i < dataSize; i++)
//    {
//        if (limit == 0)
//        {
//            if ((data[i] & 128) == 0)
//                continue;
//            else if (data[i] <= 191 || data[i] >= 248)
//                return false;
//            if (data[i] >= 240)
//                limit = 3;
//            else if (data[i] >= 224)
//                limit = 2;
//            else
//                limit = 1;
//        }
//        else if (data[i] >= 128 && data[i] <= 191)
//            limit--;
//        else
//            return false;
//    }
//    return !limit;
//}
//
