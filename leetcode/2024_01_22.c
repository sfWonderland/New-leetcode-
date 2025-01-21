//#define _CRT_SECURE_NO_WARNINGS
//
////520.检测大写字母
//
//bool detectCapitalUse(char* word)
//{
//    int len = strlen(word);
//    if (1 != len)
//    {
//        //first letter
//        //1. the first letter is capital
//        if (word[0] >= 65 && word[0] <= 90)
//        {
//            //the second letter decides the type
//            if (word[1] >= 65 && word[1] <= 90)
//            {
//                for (int i = 2; i < len; i++)
//                {
//                    //is NOT capital return false
//                    if (word[i] > 90)
//                        return false;
//                }
//            }
//            else
//            {
//                for (int i = 2; i < len; i++)
//                {
//                    //is capital return false
//                    if (word[i] < 97)
//                        return false;
//                }
//            }
//        }
//        //2. the first letter is NOT capital
//        else
//        {
//            for (int i = 1; i < len; i++)
//            {
//                //is capital return false
//                if (word[i] < 97)
//                    return false;
//            }
//        }
//    }
//    return true;
//}
//
////507.完美数
//
//int PairFactor(int num, int i)
//{
//    return num % i ? 0 : i + num / i;
//}
//
//bool checkPerfectNumber(int num)
//{
//    if (1 == num)
//        return false;
//
//    int sum = 1;
//
//    for (int i = 2; i < sqrt(num); i++)
//    {
//        sum += PairFactor(num, i);
//        //printf("i = %d, sum = %d\n", i, sum);
//    }
//
//    return sum == num ? true : false;
//}
//
////504.七进制数
//
//int CountBase(int num)
//{
//    int count = 1;
//    while (abs(num) > 6)
//    {
//        num /= 7;
//        count++;
//    }
//    return count;
//}
//char* convertToBase7(int num)
//{
//    //printf("CountBase(%d) = %d\n", num, CountBase(num));
//    if (0 == num)
//    {
//        return "0";
//    }
//    else
//    {
//        int n = CountBase(num);
//        char s[n + 2];
//        if (num < 0)
//        {
//            n++;
//            s[0] = '-';
//            num = -num;
//        }
//        s[n] = '\0';
//
//        int i = 1;
//        while (num > 0)
//        {
//            s[n - i] = num % 7 + 48;
//            //printf("s[%d] = %c\n", n - i, s[n - i]);
//            num /= 7;
//            i++;
//        }
//        char* result = s;
//        return result;
//    }
//}