////2255. ͳ���Ǹ����ַ���ǰ׺���ַ�����Ŀ
//
//int countPrefixes(char** words, int wordsSize, char* s)
//{
//    int res = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (strncmp(words[i], s, strlen(words[i])) == 0)
//            res++;
//    }
//    return res;
//}
//
////1455. ��鵥���Ƿ�Ϊ�����������ʵ�ǰ׺
//
//int isPrefixOfWord(char* sentence, char* searchWord)
//{
//    int n = strlen(sentence);
//    int num = 1;
//    for (int i = 0; i < n; i++)
//    {
//        if (strncmp(sentence + i, searchWord, strlen(searchWord)) == 0)
//            return num;
//        while (i < n && sentence[i] != ' ')
//            i++;
//        num++;
//    }
//    return -1;
//}
//
////1961. ����ַ����Ƿ�Ϊ����ǰ׺
//
//bool isPrefixString(char* s, char** words, int wordsSize)
//{
//    char* p = s;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int n = strlen(words[i]);
//        if (strncmp(p, words[i], n) != 0)
//            break;
//        p = p + n;
//    }
//    return p[0] == '\0';
//}
//
////2185. ͳ�ư�������ǰ׺���ַ���
//
//int prefixCount(char** words, int wordsSize, char* pref)
//{
//    int res = 0;
//    int n = strlen(pref);
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (strncmp(words[i], pref, n) == 0)
//            res++;
//    }
//    return res;
//}
//
