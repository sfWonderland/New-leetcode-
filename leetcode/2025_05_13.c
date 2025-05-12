////3335. 字符串转换后的长度 I
//
//#define MOD 1000000007;
//int lengthAfterTransformations(char* s, int t)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    for (int i = 0; i < t; i++)
//    {
//        int nxt[26] = { 0 };
//        nxt[0] = cnt[25];
//        nxt[1] = (cnt[0] + cnt[25]) % MOD;
//        for (int j = 2; j < 26; j++)
//        {
//            nxt[j] = cnt[j - 1];
//        }
//        memcpy(cnt, nxt, sizeof(nxt));
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        ans = (ans + cnt[i]) % MOD;
//    }
//    return ans;
//}
//
////2769. 找出最大的可达成数字
//
//int theMaximumAchievableX(int num, int t)
//{
//    return num + 2 * t;
//}
//
////3285. 找到稳定山的下标
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* stableMountains(int* height, int heightSize, int threshold, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * (heightSize - 1));
//    int n = 0;
//    for (int i = 1; i < heightSize; i++)
//    {
//        if (height[i - 1] > threshold)
//            ans[n++] = i;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////3280. 将日期转换为二进制表示
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
//void toBinary(char* date, int left, int right, char* ans, int* n)
//{
//    int num = 0;
//    for (int i = left; i <= right; i++)
//    {
//        num *= 10;
//        num += date[i] - '0';
//    }
//    //printf("%d", num);
//    int l = *n;
//    while (num)
//    {
//        ans[(*n)++] = (num & 1) + '0';
//        num >>= 1;
//    }
//    reverse(ans, l, (*n) - 1);
//}
//char* convertDateToBinary(char* date)
//{
//    char* ans = malloc(24);
//    int n = 0;
//    toBinary(date, 0, 3, ans, &n);
//    ans[n++] = '-';
//    toBinary(date, 5, 6, ans, &n);
//    ans[n++] = '-';
//    toBinary(date, 8, 9, ans, &n);
//    ans[n] = '\0';
//    return ans;
//}
//
