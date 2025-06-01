////135. 分发糖果
//
//int candy(int* ratings, int ratingsSize)
//{
//    int ans = ratingsSize; //先每人分一个，满足每人至少一个的条件
//    for (int i = 0; i < ratingsSize; i++)
//    {
//        int start = i > 0 && ratings[i - 1] < ratings[i] ? i - 1 : i; //谷底共用
//        while (i < ratingsSize - 1 && ratings[i] < ratings[i + 1]) //上坡
//            i++;
//        int top = i; // 峰顶
//        while (i < ratingsSize - 1 && ratings[i] > ratings[i + 1]) //下坡
//            i++;
//        int dec = i - top, inc = top - start; //下降序列和上升序列的宽度
//        ans += (dec * (dec - 1) + inc * (inc - 1)) / 2 + fmax(dec, inc);
//        //上升下降序列的最小糖数量和峰顶数量（峰顶数量取最大序列宽度）
//    }
//    return ans;
//}
//
////3517. 最小回文排列 I
//
//char* smallestPalindrome(char* s)
//{
//    int n = strlen(s);
//    int cnt[26] = { 0 };
//    for (int i = 0; i < n / 2; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    char* ans = (char*)malloc(sizeof(int) * (n + 1));
//    ans[n] = '\0';
//    if (n % 2) ans[n / 2] = s[n / 2];
//    int t = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        while (cnt[i])
//        {
//            ans[t] = 'a' + i;
//            ans[n - 1 - t] = ans[t];
//            t++;
//            cnt[i]--;
//        }
//    }
//    return ans;
//}
//
////1400. 构造 K 个回文字符串
//
//bool canConstruct(char* s, int k)
//{
//    int n = strlen(s);
//    if (n < k)
//        return false;
//    int cnt[26] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    int odd = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        odd += (cnt[i] & 1);
//    }
//    if (odd > k)
//        return false;
//
//    return true;
//}
//
////2131. 连接两字母单词得到的最长回文串
//
//int longestPalindrome(char** words, int wordsSize)
//{
//    int alpha[26][26] = { 0 };
//    for (int i = 0; i < wordsSize; i++)
//    {
//        alpha[words[i][0] - 'a'][words[i][1] - 'a']++;
//    }
//
//    int sum = 0, odd = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        int c = alpha[i][i];
//        sum += c - c % 2;
//        odd |= c % 2;
//        for (int j = i + 1; j < 26; j++)
//        {
//            sum += fmin(alpha[i][j], alpha[j][i]) * 2;
//        }
//    }
//
//    return (sum + odd) * 2;
//}
//
