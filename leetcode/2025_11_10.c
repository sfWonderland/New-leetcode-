////3542. 将所有元素变为 0 的最少操作次数
//
//int minOperations(int* nums, int numsSize)
//{
//    int top = -1, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        while (top >= 0 && nums[top] > nums[i])
//        {
//            top--;
//            ans++;
//        }
//
//        if (top < 0 || nums[top] != nums[i])
//        {
//            nums[++top] = nums[i];
//        }
//    }
//    return ans + top + (nums[0] > 0);
//}
//
////LCP 40. 心算挑战
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int replace_sum(int* cards, int cardsSize, int cnt, int sum, int x)
//{
//    for (int i = cnt; i < cardsSize; i++)
//    {
//        if (cards[i] % 2 != x % 2)
//            return sum - x + cards[i];
//    }
//    return 0;
//}
//int maximumScore(int* cards, int cardsSize, int cnt)
//{
//    qsort(cards, cardsSize, sizeof(int), cmp);
//    int sum = 0;
//    for (int i = 0; i < cnt; i++)
//    {
//        sum += cards[i];
//    }
//    if (sum % 2 == 0)
//        return sum;
//
//    int x = cards[cnt - 1];
//    int ans = replace_sum(cards, cardsSize, cnt, sum, x);
//    for (int i = cnt - 2; i >= 0; i--)
//    {
//        if (cards[i] % 2 != x % 2)
//        {
//            ans = fmax(ans, replace_sum(cards, cardsSize, cnt, sum, cards[i]));
//            break;
//        }
//    }
//    return ans;
//}
//
////1262. 可被三整除的最大和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maxSumDivThree(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    if (sum % 3 == 0)
//        return sum;
//
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int x = sum % 3;
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (x == nums[i] % 3)
//        {
//            ans = sum - nums[i];
//            break;
//        }
//    }
//    int t = 2;
//    for (int i = 0; i < numsSize && t > 0; i++)
//    {
//        if (nums[i] % 3 == 3 - x)
//        {
//            sum -= nums[i];
//            t--;
//        }
//    }
//    return t ? ans : fmax(ans, sum);
//}
//
//// int dfs(int* nums, int i, int j)
//// {
////     if(i < 0)
////     return j ? INT_MIN : 0;
//
////     return fmax(dfs(nums, i - 1, j), dfs(nums, i - 1, (j + nums[i]) % 3) + nums[i]);
//// }
//int maxSumDivThree(int* nums, int numsSize)
//{
//    int f[numsSize + 1][3];
//    f[0][0] = 0; f[0][1] = f[0][2] = INT_MIN;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        for (int j = 0; j < 3; j++)
//        {
//            f[i + 1][j] = fmax(f[i][j], f[i][(j + x) % 3] + x);
//        }
//    }
//    return f[numsSize][0];
//}
//
//int maxSumDivThree(int* nums, int numsSize)
//{
//    int f[2][3];
//    f[0][0] = 0; f[0][1] = f[0][2] = INT_MIN;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        for (int j = 0; j < 3; j++)
//        {
//            f[(i + 1) % 2][j] = fmax(f[i % 2][j], f[i % 2][(j + x) % 3] + x);
//        }
//    }
//    return f[(numsSize) % 2][0];
//}
//
////826. 安排工作以达到最大收益
//
//int* arr;
//int cmp1(const void* e1, const void* e2)
//{
//    return arr[*(int*)e2] - arr[*(int*)e1];
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize)
//{
//    int n = difficultySize;
//    int* idx = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        idx[i] = i;
//    }
//    arr = profit;
//    qsort(idx, n, sizeof(int), cmp1);
//    qsort(worker, workerSize, sizeof(int), cmp2);
//    int j = 0, ans = 0;
//    for (int i = 0; i < workerSize; i++)
//    {
//        while (j < n && worker[i] < difficulty[idx[j]])
//            j++;
//
//        if (j >= n)
//            break;
//
//        ans += profit[idx[j]];
//    }
//    return ans;
//}
//
