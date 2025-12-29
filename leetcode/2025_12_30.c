////840. 矩阵中的幻方
//
//int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize)
//{
//    if (gridSize < 3 || gridColSize[0] < 3)
//        return 0;
//
//    bool dfs(int i, int j)
//    {
//        bool digits[10] = { 0 };
//        for (int x = i; x < 3 + i; x++)
//        {
//            for (int y = j; y < 3 + j; y++)
//            {
//                if (grid[x][y] > 9 || grid[x][y] == 0 || digits[grid[x][y]])
//                    return false;
//
//                digits[grid[x][y]] = 1;
//            }
//        }
//        int row = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
//        int col = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
//        int diag = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
//        for (int x = i + 1; x < 3 + i; x++)
//        {
//            if (row != grid[x][j] + grid[x][j + 1] + grid[x][j + 2])
//                return false;
//        }
//        for (int y = j + 1; y < 3 + j; y++)
//        {
//            if (col != grid[i][y] + grid[i + 1][y] + grid[i + 2][y])
//                return false;
//        }
//        if (diag != grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2])
//            return false;
//
//        return true;
//    }
//    int m = gridSize, n = gridColSize[0], ans = 0;
//    for (int i = 0; i < m - 2; i++)
//    {
//        for (int j = 0; j < n - 2; j++)
//        {
//            ans += dfs(i, j);
//        }
//    }
//    return ans;
//}
//
////2719. 统计整数数目
//
//const int mod = 1e9 + 7;
//int count(char* num1, char* num2, int min_sum, int max_sum)
//{
//    if (min_sum >= 198)
//        return 0;
//    int countInt(char* num)
//    {
//        int n = strlen(num);
//        int** memo = (int**)malloc(sizeof(int*) * n);
//        for (int i = 0; i < n; i++)
//        {
//            int len = fmin(max_sum, 9 * n) + 1;
//            memo[i] = (int*)malloc(sizeof(int) * len);
//            for (int j = 0; j < len; j++)
//            {
//                memo[i][j] = -1;
//            }
//        }
//        int dfs(int i, int sum, bool limit)
//        {
//            if (sum > max_sum)
//                return 0;
//
//            if (i == n)
//                return sum >= min_sum;
//
//            if (!limit && memo[i][sum] != -1)
//                return memo[i][sum];
//
//            int tot = 0;
//            int up = limit ? num[i] - '0' : 9;
//            for (int j = 0; j <= up; j++)
//            {
//                tot = (tot + dfs(i + 1, sum + j, limit && j == up)) % mod;
//            }
//
//            if (!limit)
//                memo[i][sum] = tot;
//
//            return tot;
//        }
//        return dfs(0, 0, true);
//    }
//    int ans = (countInt(num2) - countInt(num1) + mod) % mod;
//    int sum = 0, n = strlen(num1);
//    for (int i = 0; i < n; i++)
//    {
//        sum += num1[i] - '0';
//    }
//    if (sum >= min_sum && sum <= max_sum)
//        ans = (ans + 1) % mod;
//
//    return ans;
//}
//
//const int mod = 1e9 + 7;
//int count(char* num1, char* num2, int min_sum, int max_sum)
//{
//    if (min_sum >= 198)
//        return 0;
//    int n1 = strlen(num1), n = strlen(num2);
//    if (n1 < n)
//    {
//        num1 = (char*)realloc(num1, sizeof(char) * (n + 1));
//        for (int i = n; i >= n - n1; i--)
//        {
//            num1[i] = num1[i - n + n1];
//        }
//        for (int i = 0; i < n - n1; i++)
//        {
//            num1[i] = '0';
//        }
//    }
//    int countInt(char* num1, char* num2)
//    {
//        int** memo = (int**)malloc(sizeof(int*) * n);
//        for (int i = 0; i < n; i++)
//        {
//            int len = fmin(max_sum, 9 * n) + 1;
//            memo[i] = (int*)malloc(sizeof(int) * len);
//            for (int j = 0; j < len; j++)
//            {
//                memo[i][j] = -1;
//            }
//        }
//        int dfs(int i, int sum, bool limit_high, bool limit_low)
//        {
//            if (sum > max_sum)
//                return 0;
//
//            if (i == n)
//                return sum >= min_sum;
//
//            if (!limit_high && !limit_low && memo[i][sum] != -1)
//                return memo[i][sum];
//
//            int low = limit_low ? num1[i] - '0' : 0;
//            int high = limit_high ? num2[i] - '0' : 9;
//            int tot = 0;
//            for (int j = low; j <= high; j++)
//            {
//                tot = (tot + dfs(i + 1, sum + j, limit_high && j == high, limit_low && j == low)) % mod;
//            }
//
//            if (!limit_high && !limit_low)
//                memo[i][sum] = tot;
//
//            return tot;
//        }
//        return dfs(0, 0, true, true);
//    }
//
//    return countInt(num1, num2);
//}
//
////788. 旋转数字
//
//int rotatedDigits(int n)
//{
//    char* s = (char*)malloc(sizeof(char) * 6);
//    sprintf(s, "%d", n);
//    int m = strlen(s);
//    int* memo = (int*)malloc(sizeof(int) * m);
//    memset(memo, -1, sizeof(int) * m);
//    int* digits = (int*)malloc(sizeof(int) * 10);
//    digits[0] = 1;
//    digits[1] = 1;
//    digits[2] = 2;
//    digits[3] = 0;
//    digits[4] = 0;
//    digits[5] = 2;
//    digits[6] = 2;
//    digits[7] = 0;
//    digits[8] = 1;
//    digits[9] = 2;
//    int dfs(int i, bool limit, bool changed)
//    {
//        if (i == m)
//            return changed;
//
//        if (!limit && changed && memo[i] != -1)
//            return memo[i];
//
//        int sum = 0;
//        int up = limit ? s[i] - '0' : 9;
//        for (int j = 0; j <= up; j++)
//        {
//            if (digits[j])
//                sum += dfs(i + 1, limit && j == up, changed || (digits[j] - 1));
//        }
//        if (!limit && changed)
//            memo[i] = sum;
//        return sum;
//    }
//    return dfs(0, true, false);
//}
//
////902. 最大为 N 的数字组合
//
//int atMostNGivenDigitSet(char** digits, int digitsSize, int n)
//{
//    char* s = (char*)malloc(sizeof(char) * 11);
//    sprintf(s, "%d", n);
//    int m = strlen(s);
//    int* memo = (int*)malloc(sizeof(int) * m);
//    memset(memo, -1, sizeof(int) * m);
//    int dfs(int i, bool limit, bool isNum)
//    {
//        if (i == m)
//            return isNum;
//
//        if (isNum && !limit && memo[i] != -1)
//            return memo[i];
//
//        int sum = 0;
//        if (!isNum)
//            sum = dfs(i + 1, false, false);
//
//        char up = limit ? s[i] : '9';
//        for (int j = 0; j < digitsSize; j++)
//        {
//            if (digits[j][0] > up)
//                break;
//
//            sum += dfs(i + 1, limit && digits[j][0] == up, true);
//        }
//        if (isNum && !limit)
//            memo[i] = sum;
//        return sum;
//    }
//    return dfs(0, true, false);
//}
//
