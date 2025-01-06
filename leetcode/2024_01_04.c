#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


////67.二进制求和
//char* addBinary(char* a, char* b)
//{
//    int len1 = strlen(a);
//    int len2 = strlen(b);
//    char* p = NULL;
//    int len = 0;
//    if (len1 > len2)
//    {
//        len = len1 + 1;
//        p = a;
//    }
//    else
//    {
//        len = len2 + 1;
//        p = b;
//    }
//    char* c = (char*)malloc(sizeof(char) * (len + 1));
//    for (int i = 0; i < len + 1; i++)
//    {
//        c[i] = 0;
//    }
//    for (int i = 0; i < len1 + len2 - len + 1; i++)
//    {
//        if (98 == a[len1 - 1 - i] + b[len2 - 1 - i])
//        {
//            c[len - 1 - i - 1]++;
//        }
//        if (97 == a[len1 - 1 - i] + b[len2 - 1 - i])
//        {
//            if (0 != c[len - 1 - i])
//            {
//                c[len - 1 - i - 1]++;
//                c[len - 1 - i] = 0;
//            }
//            else
//                c[len - 1 - i]++;
//        }
//        c[len - 1 - i] += 48;
//        printf("c[%d] = %c\n", len - 1 - i, c[len - 1 - i]);
//    }
//    for (int i = len1 + len2 - len + 1; i < len - 1; i++)
//    {
//        if (0 == c[len - 1 - i])
//        {
//            c[len - 1 - i] = p[len - 1 - i - 1];
//            //printf("c[%d] = %c\n", len - 1 - i, c[len - 1 - i]);
//        }
//        else
//        {
//            if (48 == p[len - 1 - i - 1])
//            {
//                c[len - 1 - i] += p[len - 1 - i - 1];
//                printf("1.c[%d] = %c\n", len - 1 - i, c[len - 1 - i]);
//            }
//            else
//            {
//                c[len - 1 - i] = 48;
//                c[len - 1 - i - 1]++;
//                printf("2.c[%d] = %c\n", len - 1 - i, c[len - 1 - i]);
//            }
//        }
//        //printf("c[%d] = %c\n", len - 1 - i, c[len - 1 - i]);
//    }
//    if (0 == c[0])
//        return (c + 1);
//    else
//    {
//        c[0] += 48;
//        return c;
//    }
//}
//
//int main()
//{
//    char a[] = "11";
//    char b[] = "1";
//    char* c = addBinary(a, b);
//    printf("c = %s", c);
//}