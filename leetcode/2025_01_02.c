#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

////125. 验证回文串
//int is_alpha(char* c)
//{
//    int ret = 0;
//    if (*c >= 'A' && *c <= 'Z')
//    {
//        *c += 32;
//        ret = 1;
//    }
//    else if (*c >= 'a' && *c <= 'z')
//        ret = 1;
//    else if (*c >= '0' && *c <= '9')
//        ret = 1;
//    return ret;
//}
//
//bool isPalindrome(char* s) 
//{
//    int len = strlen(s);
//    int ret = -1;
//    int left = 0;
//    int right = len - 1;
//    while (left < right)
//    {
//        while (!is_alpha(&s[left]) && (left < right))
//        {
//            left++;
//        }
//        while (!is_alpha(&s[right]) && (left < right))
//        {
//            right--;
//        }
//        if ((s[left] != s[right]) && (left < right))
//        {
//            ret = 0;
//            break;
//        }
//        left++;
//        right--;
//    }
//    if (-1 == ret)
//        ret = 1;
//    return ret;
//}
//
//int main()
//{
//    char s[] = "0P";
//    if (isPalindrome(s))
//        printf("YES\n");
//    else
//        printf("NO\n");
//
//}