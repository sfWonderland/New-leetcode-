////135. �ַ��ǹ�
//
//int candy(int* ratings, int ratingsSize)
//{
//    int ans = ratingsSize; //��ÿ�˷�һ��������ÿ������һ��������
//    for (int i = 0; i < ratingsSize; i++)
//    {
//        int start = i > 0 && ratings[i - 1] < ratings[i] ? i - 1 : i; //�ȵ׹���
//        while (i < ratingsSize - 1 && ratings[i] < ratings[i + 1]) //����
//            i++;
//        int top = i; // �嶥
//        while (i < ratingsSize - 1 && ratings[i] > ratings[i + 1]) //����
//            i++;
//        int dec = i - top, inc = top - start; //�½����к��������еĿ��
//        ans += (dec * (dec - 1) + inc * (inc - 1)) / 2 + fmax(dec, inc);
//        //�����½����е���С�������ͷ嶥�������嶥����ȡ������п�ȣ�
//    }
//    return ans;
//}
//
////3517. ��С�������� I
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
////1400. ���� K �������ַ���
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
////2131. ��������ĸ���ʵõ�������Ĵ�
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
