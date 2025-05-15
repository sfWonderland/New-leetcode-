////809. 情感丰富的文字
//
//bool expand(const char* s, const char* words)
//{
//    int i = 0, j = 0;
//    while (s[i] != '\0' && words[j] != '\0')
//    {
//        if (s[i] != words[j])
//            return false;
//
//        char ch = s[i];
//        int cnt1 = 0;
//        while (s[i] != '\0' && s[i] == ch)
//        {
//            cnt1++;
//            i++;
//        }
//        int cnt2 = 0;
//        while (words[j] != '\0' && words[j] == ch)
//        {
//            cnt2++;
//            j++;
//        }
//        if (cnt1 < cnt2)
//            return false;
//        if (cnt1 != cnt2 && cnt1 < 3)
//            return false;
//    }
//    return s[i] == '\0' && words[j] == '\0';
//}
//int expressiveWords(char* s, char** words, int wordsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        ans += expand(s, words[i]);
//    }
//    return ans;
//}
//
////面试题 16.06. 最小差
//
//int cmp(const void* e1, const void* e2)
//{
//    long a = *(int*)e1;
//    long b = *(int*)e2;
//    return a - b;
//}
//int smallestDifference(int* a, int aSize, int* b, int bSize)
//{
//    qsort(a, aSize, sizeof(int), cmp);
//    qsort(b, bSize, sizeof(int), cmp);
//
//    long min = INT_MAX;
//    for (int i = 0, j = 0; i < aSize && j < bSize; )
//    {
//        min = fmin(min, abs((long)a[i] - (long)b[j]));
//        if (a[i] < b[j])
//            i++;
//        else
//            j++;
//    }
//    return min;
//}
//
////524. 通过删除字母匹配到字典里最长单词
//
//bool canBeSearch(char* s, char* t)
//{
//    int i = 0, j = 0;
//    while (s[i] != '\0' && t[j] != '\0')
//    {
//        if (s[i] == t[j])
//            j++;
//        i++;
//    }
//    return t[j] == '\0';
//}
//int cmp(const void* e1, const void* e2)
//{
//    return strcmp(*(char**)e1, *(char**)e2);
//}
//char* findLongestWord(char* s, char** dictionary, int dictionarySize)
//{
//    qsort(dictionary, dictionarySize, sizeof(char*), cmp);
//    char* ans = "";
//    int n = -1, lens = strlen(s);
//    for (int i = 0; i < dictionarySize; i++)
//    {
//        int len = strlen(dictionary[i]);
//        if (len > lens)
//            continue;
//        if (canBeSearch(s, dictionary[i]))
//        {
//            if (len > n)
//            {
//                n = len;
//                ans = dictionary[i];
//            }
//        }
//    }
//    return ans;
//}
//
////2486. 追加字符以获得子序列
//
//int appendCharacters(char* s, char* t)
//{
//    int i = 0, j = 0;
//    while (s[i] != '\0' && t[j] != '\0')
//    {
//        if (s[i] == t[j])
//            j++;
//        i++;
//    }
//    return t[j] == '\0' ? 0 : strlen(t) - j;
//}
//
