////1758. ���ɽ���������ַ��������ٲ�����
//
//int minOperations(char* s)
//{
//    int len = strlen(s);
//    int plan = 0;
//    for (int i = 0; i < len; i++)
//    {
//        int p = 48 + (i & 1);
//        if (s[i] != p)
//            plan++;
//    }
//    return fmin(plan, len - plan);
//}
//
////1773. ͳ��ƥ������������Ʒ����
//
//int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue)
//{
//    int col = 0;
//    if (ruleKey[0] == 'c')
//        col = 1;
//    else if (ruleKey[0] == 'n')
//        col = 2;
//
//    int n = 0;
//    for (int i = 0; i < itemsSize; i++)
//    {
//        if (0 == strcmp(items[i][col], ruleValue))
//            n++;
//    }
//    return n;
//}
//
////1784. ���������ַ����ֶ�
//
//// bool checkOnesSegment(char* s) 
//// {
////     char ch = '1';
////     int n = 0;
////     for(int i = 0; s[i]; i++)
////     {
////         if(s[i] != ch)
////         {
////             if(0 != n)
////             return false;
//
////             ch = s[i];
////             n++;
////         }
////     }
////     return true;
//// }
//
//bool checkOnesSegment(char* s)
//{
//    return strstr(s, "01") == NULL;
//}
//
////1791. �ҳ�����ͼ�����Ľڵ�
//
//int findCenter(int** edges, int edgesSize, int* edgesColSize)
//{
//    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
//}
//

////1758. ���ɽ���������ַ��������ٲ�����
//
//int minOperations(char* s)
//{
//    int len = strlen(s);
//    int plan = 0;
//    for (int i = 0; i < len; i++)
//    {
//        int p = 48 + (i & 1);
//        if (s[i] != p)
//            plan++;
//    }
//    return fmin(plan, len - plan);
//}
//
////1773. ͳ��ƥ������������Ʒ����
//
//int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue)
//{
//    int col = 0;
//    if (ruleKey[0] == 'c')
//        col = 1;
//    else if (ruleKey[0] == 'n')
//        col = 2;
//
//    int n = 0;
//    for (int i = 0; i < itemsSize; i++)
//    {
//        if (0 == strcmp(items[i][col], ruleValue))
//            n++;
//    }
//    return n;
//}
//
////1784. ���������ַ����ֶ�
//
//// bool checkOnesSegment(char* s) 
//// {
////     char ch = '1';
////     int n = 0;
////     for(int i = 0; s[i]; i++)
////     {
////         if(s[i] != ch)
////         {
////             if(0 != n)
////             return false;
//
////             ch = s[i];
////             n++;
////         }
////     }
////     return true;
//// }
//
//bool checkOnesSegment(char* s)
//{
//    return strstr(s, "01") == NULL;
//}
//
////1791. �ҳ�����ͼ�����Ľڵ�
//
//int findCenter(int** edges, int edgesSize, int* edgesColSize)
//{
//    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
//}
//
