////402. �Ƶ� K λ����
//
//char* removeKdigits(char* num, int k)
//{
//    int n = strlen(num);
//    if (n - k <= 0)
//        return "0";
//    char* st = (char*)malloc(sizeof(char) * n);
//    int idx = -1;
//    st[++idx] = num[0];
//    for (int i = 1; i < n; i++)
//    {
//        while (k > 0 && idx >= 0 && st[idx] > num[i])
//        {
//            k--;
//            idx--;
//        }
//
//        st[++idx] = num[i];
//    }
//
//    idx -= k;
//    st[idx + 1] = '\0';
//
//    int x = 0;
//    while (x < idx && st[x] == '0')
//    {
//        x++;
//    }
//
//    return st + x;
//}
//
////316. ȥ���ظ���ĸ
//
//char* removeDuplicateLetters(char* s)
//{
//    int n = strlen(s);
//    int cnt[26] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    char* st = (char*)malloc(sizeof(char) * (n + 1));
//    int idx = -1;
//    st[++idx] = s[0];
//    bool alpha[26] = { 0 };
//    alpha[s[0] - 'a'] = true;
//    for (int i = 1; i < n; i++)
//    {
//        if (!alpha[s[i] - 'a'])
//        {
//            while (idx >= 0 && cnt[st[idx] - 'a'] > 1 && st[idx] > s[i])
//            {
//                cnt[st[idx] - 'a']--;
//                alpha[st[idx] - 'a'] = false;
//                idx--;
//            }
//
//            st[++idx] = s[i];
//            alpha[s[i] - 'a'] = true;
//        }
//        else
//            cnt[s[i] - 'a']--;
//    }
//    st[idx + 1] = '\0';
//    return st;
//}
//
////1081. ��ͬ�ַ�����С������
//
//char* smallestSubsequence(char* s)
//{
//    int n = strlen(s);
//    int cnt[26] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    char* st = (char*)malloc(sizeof(char) * (n + 1));
//    bool alpha[26] = { 0 };
//    int idx = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (!alpha[s[i] - 'a'])
//        {
//            while (idx >= 0 && cnt[st[idx] - 'a'] > 1 && st[idx] > s[i])
//            {
//                alpha[st[idx] - 'a'] = false;
//                cnt[st[idx] - 'a']--;
//                idx--;
//            }
//
//            alpha[s[i] - 'a'] = true;
//            st[++idx] = s[i];
//        }
//        else
//            cnt[s[i] - 'a']--;
//    }
//    st[++idx] = '\0';
//    return st;
//}
//
////390. ������Ϸ
//
//int lastRemaining(int n)
//{
//    int head = 1, step = 1;
//    bool left = true;
//    while (n > 1)
//    {
//        //����߿�ʼ�Ƴ�����Ҫ��head�Ƶ���һ��λ��
//        //���ұ߿�ʼ�Ƴ�����Ϊ������������Ҫ��head�Ƶ���һ��λ��
//        if (left || n % 2)
//            head += step;
//
//        step <<= 1;
//        n >>= 1;
//        left ^= 1;
//    }
//    return head;
//}
//
