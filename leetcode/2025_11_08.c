////3106. 满足距离约束且字典序最小的字符串
//
//char* getSmallestString(char* s, int k)
//{
//    for (int i = 0; s[i]; i++)
//    {
//        int discount = fmin(s[i] - 'a', 1 + 'z' - s[i]);
//        if (k >= discount)
//        {
//            k -= discount;
//            s[i] = 'a';
//        }
//        else
//        {
//            s[i] -= k;
//            break;
//        }
//    }
//    return s;
//}
//
////3723. 数位平方和的最大值
//
//char* maxSumOfSquares(int num, int sum)
//{
//    int d = sum / 9, m = sum % 9, len = num - d - (m > 0);
//    if (len < 0)
//        return "";
//
//    char* ans = (char*)malloc(sizeof(char) * (num + 1));
//    memset(ans, '9', d);
//    memset(ans + d, '0', num - d);
//    if (m)
//        ans[d] += m;
//    ans[num] = '\0';
//    return ans;
//}
//
////1053. 交换一次的先前排列
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* prevPermOpt1(int* arr, int arrSize, int* returnSize)
//{
//    int pos[10001] = { 0 };
//    for (int i = arrSize - 1; i > 0; i--)
//    {
//        pos[arr[i]] = i;
//        if (arr[i] < arr[i - 1])
//        {
//            int idx = i;
//            for (int j = arr[i - 1] - 1; j >= 0; j--)
//            {
//                if (pos[j])
//                {
//                    idx = pos[j];
//                    break;
//                }
//            }
//            int tmp = arr[i - 1];
//            arr[i - 1] = arr[idx];
//            arr[idx] = tmp;
//            break;
//        }
//    }
//    *returnSize = arrSize;
//    return arr;
//}
//
////3457. 吃披萨
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maxWeight(int* pizzas, int pizzasSize)
//{
//    qsort(pizzas, pizzasSize, sizeof(int), cmp);
//    int days = pizzasSize / 4;
//    int odd = (days + 1) / 2, even = days / 2;
//    long long ans = 0;
//    for (int i = 0; i < odd; i++)
//        ans += pizzas[i];
//    for (int i = odd + 1; i < even * 2 + odd; i += 2)
//    {
//        ans += pizzas[i];
//    }
//    return ans;
//}
//
