//#define _CRT_SECURE_NO_WARNINGS
//
////1323. 6 和 9 组成的最大数字
//
//int maximum69Number(int num)
//{
//    int factor = 1000;
//    int tmp = num;
//    while (factor)
//    {
//        int divisor = tmp / factor;
//        if (6 == divisor)
//        {
//            num += 3 * factor;
//            break;
//        }
//        else
//        {
//            tmp -= divisor * factor;
//            factor /= 10;
//        }
//    }
//    return num;
//}
//
////1332. 删除回文子序列
//
//int removePalindromeSub(char* s)
//{
//    int left = 0;
//    int right = strlen(s) - 1;
//    while (left < right)
//    {
//        if (s[left] ^ s[right])
//        {
//            return 2;
//        }
//        left++;
//        right--;
//    }
//
//    return 1;
//}
//
////1342.将数字变成0的操作次数
//
//int numberOfSteps(int num)
//{
//    int step = 0;
//    while (num)
//    {
//        step += (num > 1 ? 1 : 0) + (num & 1);
//        num >>= 1;
//    }
//    return step;
//}
//
////2169.得到 0 的操作数
//
//int countOperations(int num1, int num2)
//{
//    int step = 0;
//    while (num1 && num2)
//    {
//        step += num1 / num2;
//        int tmp = num2;
//        num2 = num1 % num2;
//        num1 = tmp;
//    }
//    return step;
//}
//
////1360. 日期之间隔几天
//
//int daysCount(int date)
//{
//    //day
//    int day = date % 100;
//    int days = day;
//    //year, 1970.12.31 is the day 0
//    int year = date / 10000;
//    days += (year - 1971) * 365 + (year - 1969) / 4;
//    //month
//    int monthdays[11] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
//    int month = date % 10000 / 100;
//    for (int i = 0; i < month - 1; i++)
//        days += monthdays[i];
//    if (((0 == year % 400) || ((0 == year % 4) && (year % 100))) && (month > 2))
//        days++;
//
//    return days;
//}
//int daysBetweenDates(char* date1, char* date2)
//{
//    int day1 = 0;
//    int day2 = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (i != 4 && i != 7)
//        {
//            day1 *= 10;
//            day2 *= 10;
//            day1 += date1[i] - 48;
//            day2 += date2[i] - 48;
//        }
//    }
//
//    return abs(daysCount(day1) - daysCount(day2));
//}
//
////2409. 统计共同度过的日子数
//
//int daysCount(int date)
//{
//    //day
//    int day = date % 100;
//    int days = day;
//    //month
//    int monthdays[11] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
//    int month = date / 100;
//    for (int i = 0; i < month - 1; i++)
//        days += monthdays[i];
//
//    return days;
//}
//int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob)
//{
//    int Aday0 = 0;
//    int Aday1 = 0;
//    int Bday0 = 0;
//    int Bday1 = 0;
//    for (int i = 0; i < 5; i++)
//    {
//        if (i != 2)
//        {
//            Aday0 *= 10;
//            Aday1 *= 10;
//            Bday0 *= 10;
//            Bday1 *= 10;
//            Aday0 += arriveAlice[i] - 48;
//            Aday1 += leaveAlice[i] - 48;
//            Bday0 += arriveBob[i] - 48;
//            Bday1 += leaveBob[i] - 48;
//        }
//    }
//
//    int day0 = Aday0 > Bday0 ? Aday0 : Bday0;
//    int day1 = Aday1 < Bday1 ? Aday1 : Bday1;
//
//    return day1 - day0 + 1 < 0 ? 0 : daysCount(day1) - daysCount(day0) + 1;
//}
//
////2224. 转化时间需要的最少操作数
//
//int convertTime(char* current, char* correct)
//{
//    int clock = 0;
//    int exact = 0;
//    for (int i = 0; i < 5; i++)
//    {
//        if (i != 2)
//        {
//            clock *= 10;
//            exact *= 10;
//            clock += current[i] - 48;
//            exact += correct[i] - 48;
//        }
//    }
//
//    clock = clock / 100 * 60 + clock % 100;
//    exact = exact / 100 * 60 + exact % 100;
//    int diff = exact - clock;
//
//    return diff / 60 + (diff % 60) / 15 + (diff % 15) / 5 + diff % 5;
//}
//
////1374. 生成每种字符都是奇数个数
//
//char* generateTheString(int n)
//{
//    char* s = (char*)malloc(sizeof(char) * (n + 1));
//    memset(s, 'a', sizeof(char) * n);
//    s[n] = '\0';
//    if (0 == n % 2)
//        s[n - 1]++;
//
//    return s;
//}
//
////482.密钥格式化
//
//char* licenseKeyFormatting(char* s, int k)
//{
//    int len = strlen(s);
//    int t = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] != '-')
//            t++;
//    }
//    int time = t / k;
//    char* copy = (char*)malloc(sizeof(char) * (t + time + 1));
//    memset(copy, '-', sizeof(char) * (t + time));
//    copy[t + time] = '\0';
//
//    int j = 0;
//    int first = t % k;
//    if (!first)
//        first += k;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] != '-')
//            copy[j++] = toupper(s[i]);
//        if (0 == (j - first) % (k + 1))
//            j++;
//        //printf("i = %d, j = %d\n", i, j);
//    }
//    if (j > 0 && copy[j - 1] == '-')
//        copy[j - 1] = '\0';
//
//    return copy;
//}
//
////3136. 有效单词
//
//bool is_alpha(char ch)
//{
//    if (ch >= 65 && ch <= 90)
//        return true;
//    else if (ch >= 97 && ch <= 122)
//        return true;
//    else
//        return false;
//}
//bool is_vowel(char ch)
//{
//    if ('a' == ch || 'e' == ch || 'i' == ch || 'o' == ch || 'u' == ch)
//        return true;
//    else if ('A' == ch || 'E' == ch || 'I' == ch || 'O' == ch || 'U' == ch)
//        return true;
//    else
//        return false;
//}
//bool is_num(char ch)
//{
//    if (ch >= 48 && ch <= 57)
//        return true;
//    else
//        return false;
//}
//bool isValid(char* word)
//{
//    int len = strlen(word);
//    if (len < 3)
//        return false;
//
//    int flag1 = 0;
//    int flag2 = 0;
//
//    for (int i = 0; i < len; i++)
//    {
//        if (is_alpha(word[i]))
//        {
//            if (is_vowel(word[i]))
//                flag1++;
//            else
//                flag2++;
//        }
//        else
//        {
//            if (0 == is_num(word[i]))
//                return false;
//        }
//    }
//
//    return flag1 && flag2;
//}
//
////1370.上升下降字符串
//
//char* sortString(char* s)
//{
//    int len = strlen(s);
//    int h[26] = { 0 };
//    for (int i = 0; i < len; i++)
//    {
//        h[s[i] - 'a']++;
//    }
//
//    int n = 0;
//    while (n < len)
//    {
//        for (int i = 0; i < 26; i++)
//        {
//            if (h[i])
//            {
//                s[n++] = i + 'a';
//                h[i]--;
//            }
//        }
//
//        for (int i = 25; i >= 0; i--)
//        {
//            if (h[i])
//            {
//                s[n++] = i + 'a';
//                h[i]--;
//            }
//        }
//    }
//
//    return s;
//}
