////LCR 192. ���ַ���ת�������� (atoi)
//
//bool is_num(char s)
//{
//    return s >= '0' && s <= '9';
//}
//int myAtoi(char* str)
//{
//    int i = 0;
//    int len = strlen(str);
//    //�������õ�ǰ���ո�
//    while (i < len && ' ' == str[i])
//        i++;
//    if (i == len)
//        return 0;
//    //�����һ���ַ������軹δ���ַ�ĩβ��Ϊ�����Ǹ���
//    int t = 1;
//    if (('-' == str[i]) || ('+' == str[i]))
//    {
//        if (len - 1 == i)
//            return 0;
//        if ('-' == str[i])
//            t = -1;
//        i++;
//    }
//    //������һ���ַ���ֱ��������һ���������ַ��򵽴�����Ľ�β��
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
////2042.�������е������Ƿ����
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
//        //����ǰ��
//        if (0 == is_num(s[i]))
//            continue;
//        //������һ���ַ���ֱ��������һ���������ַ��򵽴�����Ľ�β��
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
////7. ������ת
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
////LCR 179. �����ܼ۸�ΪĿ��ֵ��������Ʒ
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
