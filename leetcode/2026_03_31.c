////3305. 元音辅音字符串计数 I
//
//int f(char* word, int k)
//{
//    int cnt[26] = { 0 }, left = 0, sum = 0, ans = 0;
//    for (int i = 0; word[i]; i++)
//    {
//        cnt[word[i] - 'a']++;
//        if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u')
//            sum++;
//        while (cnt[0] && cnt[4] && cnt[8] && cnt[14] && cnt[20] && sum >= k)
//        {
//            cnt[word[left] - 'a']--;
//            if (word[left] != 'a' && word[left] != 'e' && word[left] != 'i' && word[left] != 'o' && word[left] != 'u')
//                sum--;
//            left++;
//        }
//        ans += left;
//    }
//    return ans;
//}
//int countOfSubstrings(char* word, int k)
//{
//    return f(word, k) - f(word, k + 1);
//}
//
////3306. 元音辅音字符串计数 II    
//
//long long f(char* word, int k)
//{
//    int mask = 0x104111;
//    int cnt1[21] = { 0 }, left = 0, size1 = 0, cnt2 = 0;
//    long long ans = 0;
//    for (int i = 0; word[i]; i++)
//    {
//        int x = word[i] - 'a';
//        if ((mask >> x) & 1)
//        {
//            cnt1[x]++;
//            if (cnt1[x] == 1)
//                size1++;
//        }
//        else
//        {
//            cnt2++;
//        }
//
//        while (size1 == 5 && cnt2 >= k)
//        {
//            int y = word[left] - 'a';
//            if ((mask >> y) & 1)
//            {
//                cnt1[y]--;
//                if (cnt1[y] == 0)
//                    size1--;
//            }
//            else
//            {
//                cnt2--;
//            }
//            left++;
//        }
//        ans += left;
//    }
//    return ans;
//}
//long long countOfSubstrings(char* word, int k)
//{
//    return f(word, k) - f(word, k + 1);
//}
//
////3309. 连接二进制表示可形成的最大数值
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
//void toBinary(char* s, int x)
//{
//    // if(x == 0)
//    // {
//    //     s[0] = '0';
//    //     s[1] = '\0';
//    // }
//    int i = 0;
//    while (x)
//    {
//        s[i++] = (x & 1) + '0';
//        x >>= 1;
//    }
//    s[i] = '\0';
//    reverse(s, 0, i - 1);
//}
//int toInt(char* s)
//{
//    int res = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        res <<= 1;
//        res += s[i] - '0';
//    }
//    return res;
//}
//char* s1, * s2;
//int cmp(const void* e1, const void* e2)
//{
//
//    strcpy(s1, *(char**)e1);
//    strcat(s1, *(char**)e2);
//    //printf("%s\n", s1);
//    strcpy(s2, *(char**)e2);
//    strcat(s2, *(char**)e1);
//    //printf("%s\n", s2);
//    return strcmp(s2, s1);
//}
//int maxGoodNumber(int* nums, int numsSize)
//{
//    char** strings = (char**)malloc(sizeof(char*) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        strings[i] = (char*)malloc(sizeof(char) * 9);
//        toBinary(strings[i], nums[i]);
//        //printf("%s\n", strings[i]);
//    }
//    s1 = (char*)malloc(sizeof(char) * 30);
//    s2 = (char*)malloc(sizeof(char) * 30);
//    qsort(strings, numsSize, sizeof(char*), cmp);
//    char* s = (char*)malloc(sizeof(char) * 9 * numsSize);
//    s[0] = '\0';
//    for (int i = 0; i < numsSize; i++)
//    {
//        strcat(s, strings[i]);
//        //printf("%s\n", s);
//    }
//    free(s1);
//    free(s2);
//    return toInt(s);
//}
//
//int get_len(int x)
//{
//    int res = 0;
//    while (x)
//    {
//        res++;
//        x >>= 1;
//    }
//    return res;
//}
//int maxGoodNumber(int* nums, int numsSize)
//{
//    int len[3] = { 0 };
//    int width = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        len[i] = get_len(nums[i]);
//        width += len[i];
//    }
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        width -= len[i];
//        int sum = nums[i] << width;
//        for (int j = 0; j < numsSize; j++)
//        {
//            if (j == i) continue;
//            width -= len[j];
//            sum += nums[j] << width;
//            for (int k = 0; k < numsSize; k++)
//            {
//                if (k == i || k == j) continue;
//                sum += nums[k];
//                ans = fmax(ans, sum);
//                sum -= nums[k];
//            }
//            sum -= nums[j] << width;
//            width += len[j];
//        }
//        width += len[i];
//    }
//    return ans;
//}
//
////3345. 最小可整除数位乘积 I
//
//int smallestNumber(int n, int t)
//{
//    // 至多循环 10 次，一定会遇到个位数为 0 的数字，数位乘积是 0，一定是 t 的倍数。
//    for (int i = n; ; i++)
//    {
//        int prod = 1;
//        for (int x = i; x; x /= 10)
//        {
//            prod *= x % 10;
//        }
//        if (prod % t == 0)
//            return i;
//    }
//    return -1;
//}
//
