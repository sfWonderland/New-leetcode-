#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//58. 最后一个单词的长度

//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

//short is_alpha(char ch)
//{
//    if (ch >= 'A' && ch <= 'Z')
//        return 1;
//    else if (ch >= 'a' && ch <= 'z')
//        return 1;
//    return 0;
//}
//int lengthOfLastWord(char* s) 
//{
//    int len = strlen(s);
//    int right = len - 1;
//    //去掉尾部非字母的空间计算
//    while (right > 0)
//    {
//        if (is_alpha(s[right]))
//            break;
//        else
//            right--;
//        len--;
//    }
//    //计算最后一个单词首字母前一个空格的坐标
//    while (right > 0)
//    {
//        if (s[right] == ' ')
//            break;
//        else
//            right--;
//    }
//    //right==0时是否为空格
//    if (s[right] != ' ')
//        return len;
//    else
//        return len - right - 1;
//}
//
//int main()
//{
//    char s[] = "   fly me   to   the moon  ";
//    printf("the length of the last word is %d\n",lengthOfLastWord(s));
//}

//69. X的平方根

//int mySqrt(int x) 
//{
//    int left = 0;
//    int right = 46340;
//    int mid = (right - left) / 2 + left;
//    int ret = -1;
//    if (x <= 1)
//        ret = x;
//    if (x >= right * right)
//        ret = right;
//    while (ret == -1)
//    {
//        if (x > mid * mid)
//        {
//            if (left != mid)
//            {
//                left = mid;
//                mid = (right - left) / 2 + left;
//            }
//            else
//                ret = mid;
//        }
//        else if (x < mid * mid)
//        {
//            right = mid;
//            mid = (right - left) / 2 + left;
//        }
//        else
//            ret = mid;
//    }
//    return ret;
//}
//
//int main()
//{
//    int a = 2147395600;
//    int b = 2147483647;
//    srand((unsigned int)time(NULL));
//    int c = rand();
//    printf("a = %d, sqrt(a) = %d\n", a, mySqrt(a));
//    printf("b = %d, sqrt(b) = %d\n", b, mySqrt(b));
//    printf("c = %d, sqrt(c) = %d\n", c, mySqrt(c));
//    return 0;
//}