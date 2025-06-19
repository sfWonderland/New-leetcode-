////3443. K 次修改后的最大曼哈顿距离
//
//int maxDistance(char* s, int k)
//{
//    int x = 0, y = 0, ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        switch (s[i])
//        {
//        case 'N': --y; break;
//        case 'S': ++y; break;
//        case 'W': --x; break;
//        case 'E': ++x; break;
//        }
//        ans = fmax(fmin(abs(x) + abs(y) + 2 * k, i + 1), ans);
//    }
//
//    return ans;
//}
//
////3151. 特殊数组 I
//
//bool isArraySpecial(int* nums, int numsSize)
//{
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (0 == ((nums[i] + nums[i - 1]) & 1))
//            return false;
//    }
//    return true;
//}
//
////3099. 哈沙德数
//
//int sumOfTheDigitsOfHarshadNumber(int x)
//{
//    int digit = 0, x0 = x;
//    while (x)
//    {
//        digit += x % 10;
//        x /= 10;
//    }
//    return x0 % digit == 0 ? digit : -1;
//}
//
////3270. 求出数字答案
//
//int generateKey(int num1, int num2, int num3)
//{
//    int thou = fmin(fmin(num1 / 1000, num2 / 1000), num3 / 1000);
//    int hun = fmin(fmin(num1 % 1000 / 100, num2 % 1000 / 100), num3 % 1000 / 100);
//    int ten = fmin(fmin(num1 % 100 / 10, num2 % 100 / 10), num3 % 100 / 10);
//    int digit = fmin(fmin(num1 % 10, num2 % 10), num3 % 10);
//    return thou * 1000 + hun * 100 + ten * 10 + digit;
//}
//
