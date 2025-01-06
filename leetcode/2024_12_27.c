#define _CRT_SECURE_NO_WARNINGS


#include <string.h>

//13. 罗马数字转整数
//int romanToInt(char* s) {
//    int len = strlen(s);
//    int i = 0;
//    int sum = 0;
//    int num1 = 0;
//    int num2 = 0;
//    for (i = 0; i <= len; i++)
//    {
//
//        switch (s[i])
//        {
//        case 'I':num2 = 1; break;
//        case 'V':num2 = 5; break;
//        case 'X':num2 = 10; break;
//        case 'L':num2 = 50; break;
//        case 'C':num2 = 100; break;
//        case 'D':num2 = 500; break;
//        case 'M':num2 = 1000; break;
//        default:num2 = 0; break;
//        }
//        if (num1 < num2)
//        {
//            num1 = -num1;
//        }
//        sum += num1;
//        num1 = num2;
//    }
//    return sum;
//}

//