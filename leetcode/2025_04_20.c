////781. ɭ���е�����
//
//int numRabbits(int* answers, int answersSize)
//{
//    int nums[1001] = { 0 };
//    int ans = 0;
//    for (int i = 0; i < answersSize; i++)
//    {
//        if (nums[answers[i]] % (answers[i] + 1) == 0)
//            ans += answers[i] + 1;
//
//        nums[answers[i]]++;
//    }
//    return ans;
//}
//
////2399. �����ͬ��ĸ��ľ���
//
//bool checkDistances(char* s, int* distance, int distanceSize)
//{
//    int alpha[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        int t = s[i] - 'a';
//        if (alpha[t] == 0)
//            alpha[t] = i + 1;
//        else if (i - alpha[t] != distance[t])
//            return false;
//    }
//    return true;
//}
//
////LCR 181. �ַ����еĵ��ʷ�ת
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
//char* reverseMessage(char* message)
//{
//    int len = strlen(message);
//    if (len == 0)
//        return "";
//    reverse(message, 0, len - 1);
//    bool blank = true;
//    int left = -1;
//    int right = -1;
//    char* ret = (char*)malloc(sizeof(char) * (len + 1));
//    int n = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (message[i] == ' ')
//        {
//            if (blank == false)
//            {
//                ret[n++] = message[i];
//                blank = true;
//                reverse(ret, left, right);
//                left = -1;
//                right = -1;
//            }
//        }
//        else
//        {
//            blank = false;
//            if (left == -1)
//                left = n;
//            right = n;
//            ret[n++] = message[i];
//        }
//    }
//    if (blank)
//    {
//        if (n)
//            ret[n - 1] = '\0';
//        else
//            return "";
//    }
//    else
//    {
//        reverse(ret, left, right);
//        ret[n] = '\0';
//    }
//    return ret;
//}
//
////2729. �ж�һ�����Ƿ�����
//
//void count(int n, int* t)
//{
//    t[0] |= 1 << (n / 100);
//    t[0] |= 1 << (n / 10 % 10);
//    t[0] |= 1 << (n % 10);
//}
//bool isFascinating(int n)
//{
//    int t = 0;
//    count(n, &t);
//    //printf("%x", t);
//    count(2 * n, &t);
//    //printf("%x", t);
//    count(3 * n, &t);
//    //printf("%x", t);
//    return !(t ^ 0x3fe);
//}
////192,219,273,327
//
