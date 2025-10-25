////3726. 移除十进制表示中的所有零
//
//long long removeZeros(long long n)
//{
//    long long m = 0;
//    while (n)
//    {
//        if (n % 10)
//        {
//            m *= 10;
//            m += n % 10;
//        }
//        n /= 10;
//    }
//    long long ans = 0;
//    while (m)
//    {
//        ans *= 10;
//        ans += m % 10;
//        m /= 10;
//    }
//    return ans;
//}
//
//long long removeZeros(long long n)
//{
//    long long ans = 0, pow10 = 1;
//    while (n)
//    {
//        long long d = n % 10;
//        if (n % 10)
//        {
//            ans += pow10 * d;
//            pow10 *= 10;
//        }
//        n /= 10;
//    }
//    return ans;
//}
//
////100855. 最大交替平方和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long maxAlternatingSum(int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        nums[i] = nums[i] * nums[i];
//    }
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int x = numsSize / 2;
//    long long ans = 0;
//    int step = 1;
//    if (numsSize & 1)
//        ans += nums[x];
//    else
//        ans += nums[x] - nums[0];
//    while (x + step < numsSize)
//    {
//        ans += nums[x + step] - nums[x - step];
//        step++;
//    }
//    return ans;
//}
//
////!3728. 边界与内部和相等的稳定子数组
//
//long long countStableSubarrays(int* capacity, int capacitySize)
//{
//    int n = capacitySize;
//    long long pre[n + 1];
//    pre[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre[i + 1] = pre[i] + capacity[i];
//    }
//    long long ans = 0;
//    for (int i = 0; i < n - 2; i++) // l
//    {
//        for (int j = i + 2; j < n; j++) // r
//        {
//            if (pre[j] - pre[i] == 2 * capacity[i] && capacity[j] == capacity[i])
//                ans++;
//        }
//    }
//    return ans;
//}
//
////2043. 简易银行系统
//
//typedef struct
//{
//    long long* nums;
//    int n;
//} Bank;
//
//
//Bank* bankCreate(long long* balance, int balanceSize)
//{
//    Bank* obj = (Bank*)malloc(sizeof(Bank));
//    obj->nums = balance;
//    obj->n = balanceSize;
//    return obj;
//}
//
//bool bankTransfer(Bank* obj, int account1, int account2, long long money)
//{
//    if (account1 <= obj->n && account2 <= obj->n && obj->nums[account1 - 1] >= money)
//    {
//        obj->nums[account1 - 1] -= money;
//        obj->nums[account2 - 1] += money;
//        return true;
//    }
//    return false;
//}
//
//bool bankDeposit(Bank* obj, int account, long long money)
//{
//    if (account <= obj->n)
//    {
//        obj->nums[account - 1] += money;
//        return true;
//    }
//    return false;
//}
//
//bool bankWithdraw(Bank* obj, int account, long long money)
//{
//    if (account <= obj->n && obj->nums[account - 1] >= money)
//    {
//        obj->nums[account - 1] -= money;
//        return true;
//    }
//    return false;
//}
//
//void bankFree(Bank* obj)
//{
//    free(obj);
//}
//
///**
// * Your Bank struct will be instantiated and called as such:
// * Bank* obj = bankCreate(balance, balanceSize);
// * bool param_1 = bankTransfer(obj, account1, account2, money);
//
// * bool param_2 = bankDeposit(obj, account, money);
//
// * bool param_3 = bankWithdraw(obj, account, money);
//
// * bankFree(obj);
//*/
//
////1402. 做菜顺序
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int maxSatisfaction(int* satisfaction, int satisfactionSize)
//{
//    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
//    if (satisfaction[0] <= 0)
//        return 0;
//    int ans = 0, sum = 0;
//    for (int i = 0; i < satisfactionSize; i++)
//    {
//        ans += sum;
//        sum += satisfaction[i];
//        if (sum <= 0)
//            break;
//    }
//    if (sum > 0)
//        ans += sum;
//    return ans;
//}
//
