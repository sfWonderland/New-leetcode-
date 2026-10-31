//// 8. ×Ö·û´®×ª»»ÕûÊý (atoi)
//
//int myAtoi(char* s)
//{
//    bool read = false;
//    bool neg = false;
//    long long ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (!read && s[i] == ' ')
//            continue;
//        else if (s[i] == '-' || s[i] == '+')
//        {
//            if (read)
//                break;
//            neg = s[i] == '-';
//        }
//        else if (s[i] <= '9' && s[i] >= '0')
//        {
//            ans *= 10;
//            ans += s[i] - '0';
//            if (ans > INT_MAX)
//                break;
//        }
//        else
//            break;
//
//        read = true;
//    }
//
//    return neg ? fmax(-ans, INT_MIN) : fmin(ans, INT_MAX);
//}
//
