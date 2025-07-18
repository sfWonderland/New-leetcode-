////983. 最低票价
//
//int mincostTickets(int* days, int daysSize, int* costs, int costsSize)
//{
//    int f[daysSize + 1];
//    memset(f, 0, sizeof(f));
//    int j = 0, k = 0;
//    for (int i = 0; i < daysSize; i++)
//    {
//        int x = days[i];
//        while (days[j] <= x - 7)
//            j++;
//        while (days[k] <= x - 30)
//            k++;
//
//        f[i + 1] = fmin(
//            fmin(
//                f[i] + costs[0],
//                f[j] + costs[1]
//            ),
//            f[k] + costs[2]
//        );
//    }
//    return f[daysSize];
//}
//
////3195. 包含所有 1 的最小矩形面积 I
//
//int minimumArea(int** grid, int gridSize, int* gridColSize)
//{
//    int f[4] = { gridSize, 0, gridColSize[0], 0 };
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridColSize[0]; j++)
//        {
//            if (grid[i][j])
//            {
//                f[0] = fmin(f[0], j);
//                f[1] = fmax(f[1], j);
//                f[2] = fmin(f[2], i);
//                f[3] = i;
//            }
//        }
//    }
//    return (f[1] - f[0] + 1) * (f[3] - f[2] + 1);
//}
//
////2108. 找出数组中的第一个回文字符串
//
//bool isPalindromic(char* s)
//{
//    int left = 0, right = strlen(s) - 1;
//    while (left < right)
//    {
//        if (s[left] != s[right])
//            return false;
//        left++;
//        right--;
//    }
//    return true;
//}
//char* firstPalindrome(char** words, int wordsSize)
//{
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (isPalindromic(words[i]))
//            return words[i];
//    }
//    return "";
//}
//
////3079. 求出加密整数的和
//
//int decode(int n)
//{
//    int x = 0, i = -1;
//    while (n)
//    {
//        x = fmax(n % 10, x);
//        i++;
//        n /= 10;
//    }
//    int ret = x;
//    while (i)
//    {
//        ret *= 10;
//        ret += x;
//        i--;
//    }
//    return ret;
//}
//int sumOfEncryptedInt(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans += decode(nums[i]);
//    }
//    return ans;
//}
//
