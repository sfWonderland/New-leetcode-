//#define _CRT_SECURE_NO_WARNINGS
//
////292.Nim游戏
//
//bool canWinNim(int n)
//{
//    return n % 4;
//}
//
////344.反转字符串
//
//void reverseString(char* s, int sSize)
//{
//    int left = 0;
//    int right = sSize - 1;
//    while (left < right)
//    {
//        int tmp = s[left];
//        s[left] = s[right];
//        s[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
////345.反转字符串中的元音字母
//
//bool is_vowel(char ch)
//{
//    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//        return true;
//    else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
//        return true;
//    else
//        return false;
//}
//char* reverseVowels(char* s)
//{
//    int left = 0;
//    int right = strlen(s) - 1;
//    while (left < right)
//    {
//        while (left < right && !is_vowel(s[left]))
//            left++;
//        while (left < right && !(is_vowel(s[right])))
//            right--;
//        if (left < right)
//        {
//            int tmp = s[left];
//            s[left] = s[right];
//            s[right] = tmp;
//            left++;
//            right--;
//        }
//    }
//    return s;
//}
//
////367.有效的完全平方数
//
//int count_len(int num)
//{
//    int count = 1;
//    while (num /= 10)
//    {
//        count++;
//    }
//    return count;
//}
//int minsqrt(int num)
//{
//    int count = (count_len(num) + 1) / 2;
//    int ret = 1;
//    while (--count)
//        ret *= 10;
//    return ret;
//}
//bool isPerfectSquare(int num)
//{
//    int left = minsqrt(num);
//    int right = left * 10;
//    int mid = left + (right - left) / 2;
//    while (left < mid)
//    {
//        if ((num / mid) > mid)
//        {
//            left = mid;
//            mid = left + (right - left) / 2;
//            //printf("1:left = %d, mid = %d, right = %d\n", left, mid, right);
//        }
//        else if ((num / mid) < mid)
//        {
//            right = mid;
//            mid = left + (right - left) / 2;
//            //printf("2:left = %d, mid = %d, right = %d\n", left, mid, right);
//        }
//        else
//        {
//            //printf("3:left = %d, mid = %d, right = %d\n", left, mid, right);
//            break;
//        }
//    }
//    //printf("2:left = %d, mid = %d, right = %d\n", left, mid, right);
//    //printf("minsqrt(%d) = %d\n", num, minsqrt(num));
//    return (0 == num % mid && mid == num / mid) ? true : false;
//}