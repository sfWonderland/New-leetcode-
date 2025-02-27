////LCR 192. 把字符串转换成整数 (atoi)
//
//bool is_num(char s)
//{
//    return s >= '0' && s <= '9';
//}
//int myAtoi(char* str)
//{
//    int i = 0;
//    int len = strlen(str);
//    //丢弃无用的前导空格
//    while (i < len && ' ' == str[i])
//        i++;
//    if (i == len)
//        return 0;
//    //检查下一个字符（假设还未到字符末尾）为正还是负号
//    int t = 1;
//    if (('-' == str[i]) || ('+' == str[i]))
//    {
//        if (len - 1 == i)
//            return 0;
//        if ('-' == str[i])
//            t = -1;
//        i++;
//    }
//    //读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。
//    long n = 0;
//    while (i < len && is_num(str[i]))
//    {
//        n *= 10;
//        n += str[i] - '0';
//        i++;
//        if (n > INT_MAX)
//        {
//            if (t < 0)
//                return INT_MIN;
//
//            return INT_MAX;
//        }
//    }
//
//    return n * t;
//}
//
////2042.检查句子中的数字是否递增
//
//bool is_num(char s)
//{
//    return s >= '0' && s <= '9';
//}
//bool areNumbersAscending(char* s)
//{
//    int len = strlen(s);
//    int l = 0;
//    int r = 0;
//    for (int i = 0; i < len; i++)
//    {
//        //丢弃前导
//        if (0 == is_num(s[i]))
//            continue;
//        //读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。
//        while (i < len && is_num(s[i]))
//        {
//            r *= 10;
//            r += s[i] - '0';
//            i++;
//        }
//        if (r && r <= l)
//            return false;
//
//        l = r;
//        r = 0;
//    }
//    return true;
//}
//
////7. 整数反转
//
//int reverse(int x)
//{
//    int ret = 0;
//    int n = 0;
//    while (x)
//    {
//        if (n == 9 && abs(ret) > 0xccccccc)
//            return 0;
//        ret *= 10;
//        ret += x % 10;
//        x /= 10;
//        n++;
//    }
//    return ret;
//}
//
////LCR 179. 查找总价格为目标值的两个商品
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* twoSum(int* price, int priceSize, int target, int* returnSize)
//{
//    int left = 0;
//    int right = priceSize - 1;
//    while (left < right)
//    {
//        if (price[left] == target - price[right])
//            break;
//        else if (price[left] < target - price[right])
//            left++;
//        else
//            right--;
//    }
//
//    *returnSize = 2;
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = price[left];
//    ret[1] = price[right];
//    return ret;
//}
//
