////80.删除有序数组重复项II
//
//int removeDuplicates(int* nums, int numsSize)
//{
//    if (numsSize < 3)
//        return numsSize;
//    int num = 2;
//    for (int i = 2; i < numsSize; i++)
//    {
//        if (nums[num - 2] ^ nums[i])
//            nums[num++] = nums[i];
//    }
//    return num;
//}
//
////46.删除有序数组重复项(re)
//
//int removeDuplicates(int* nums, int numsSize)
//{
//    int num = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[num - 1] != nums[i])
//            nums[num++] = nums[i];
//    }
//    return num;
//}
//
////189.轮换数组(re)
//
//// 3.环状替换
//int gcd(int a, int b)
//{
//    return b ? gcd(b, a % b) : a;
//}
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    k = k % numsSize;
//    int count = gcd(numsSize, k);
//
//    for (int start = 0; start < count; start++)
//    {
//        int current = start;
//        int left = nums[start];
//        do
//        {
//            int next = (current + k) % numsSize;
//            swap(&left, &nums[next]);
//            current = next;
//        } while (current != start);
//    }
//}
//
////122.买卖股票的最佳时机 II
//
//int maxProfit(int* prices, int pricesSize)
//{
//    int profit = 0;
//    int stack = pricesSize - 1;
//    int best = -prices[stack];
//    for (int i = pricesSize - 2; i >= 0; i--)
//    {
//        if (best + prices[i] < 0)
//            best = -prices[i];
//        else
//        {
//            profit += prices[stack] + best;
//            stack = i;
//            best = -prices[stack];
//        }
//    }
//    if (stack != 0)
//        profit += prices[stack] + best;
//    return profit;
//}
//
////50.Pow(x,n)
//
//double myPow(double x, int n)
//{
//    if (n < 0)
//    {
//        x = 1 / x;
//        if (n != INT_MIN)
//            n = -n;
//        else
//        {
//            x = x * x;
//            n = abs(INT_MIN / 2);
//        }
//    }
//    double ret = 1;
//    while (n > 0)
//    {
//        if (n & 1)
//            ret *= x;
//
//        x = x * x;
//        n >>= 1;
//    }
//    return ret;
//}
