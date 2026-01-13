////3753. 范围内总波动值 II
//
//long long totalWaviness(long long num1, long long num2)
//{
//    char* high = (char*)malloc(sizeof(char) * 17);
//    char* low = (char*)malloc(sizeof(char) * 17);
//    sprintf(high, "%lld", num2);
//    sprintf(low, "%lld", num1);
//    int n = strlen(high);
//    int diff = n - strlen(low);
//    long long**** memo = (long long****)malloc(sizeof(long long***) * n);
//    for (int i = 0; i < n; i++)
//    {
//        memo[i] = (long long***)malloc(sizeof(long long**) * n);
//        for (int j = 0; j < n; j++)
//        {
//            memo[i][j] = (long long**)malloc(sizeof(long long*) * 3);
//            for (int k = 0; k < 3; k++)
//            {
//                memo[i][j][k] = (long long*)malloc(sizeof(long long) * 10);
//                memset(memo[i][j][k], -1, sizeof(long long) * 10);
//            }
//        }
//    }
//    // 
//    long long dfs(int i, int waviness, int lastCmp, int lastDigit, bool limitHigh, bool limitLow)
//    {
//        if (i == n)
//            return waviness;
//
//        //printf("%d %d %d %d\n", i, waviness, lastCmp, lastDigit);
//        long long ref = memo[i][waviness][lastCmp + 1][lastDigit];
//        if (!limitHigh && !limitLow && ref != -1)
//            return ref;
//
//        int hi = limitHigh ? high[i] - '0' : 9;
//        int lo = limitLow && i >= diff ? low[i - diff] - '0' : 0;
//
//        long long res = 0;
//        bool isNum = !limitLow || i > diff;
//        for (int d = lo; d <= hi; d++)
//        {
//            int cmp = isNum ? (d > lastDigit) - (d < lastDigit) : 0;
//            int new_waviness = waviness + (cmp * lastCmp < 0);
//            res += dfs(i + 1, new_waviness, cmp, d, limitHigh && d == hi, limitLow && d == lo);
//        }
//        if (!limitHigh && !limitLow)
//            memo[i][waviness][lastCmp + 1][lastDigit] = res;
//        return res;
//    }
//    long long result = dfs(0, 0, 0, 0, true, true);
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            for (int k = 0; k < 3; k++) {
//                free(memo[i][j][k]);
//            }
//            free(memo[i][j]);
//        }
//        free(memo[i]);
//    }
//    free(memo);
//    free(high);
//    free(low);
//
//    return result;
//}
//
//
////2326. 螺旋矩阵 IV    
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * m);
//    *returnSize = m;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * n);
//        memset(ans[i], -1, sizeof(int) * n);
//        (*returnColumnSizes)[i] = n;
//    }
//    struct ListNode* cur = head;
//    int left = 0, right = n - 1, up = 0, down = m - 1;
//    while (cur)
//    {
//        for (int i = left; i <= right; i++)
//        {
//            if (!cur)
//                break;
//
//            ans[up][i] = cur->val;
//            cur = cur->next;
//        }
//        if (!cur)
//            break;
//        up++;
//        for (int i = up; i <= down; i++)
//        {
//            if (!cur)
//                break;
//
//            ans[i][right] = cur->val;
//            cur = cur->next;
//        }
//        if (!cur)
//            break;
//        right--;
//        for (int i = right; i >= left; i--)
//        {
//            if (!cur)
//                break;
//
//            ans[down][i] = cur->val;
//            cur = cur->next;
//        }
//        if (!cur)
//            break;
//        down--;
//        for (int i = down; i >= up; i--)
//        {
//            if (!cur)
//                break;
//
//            ans[i][left] = cur->val;
//            cur = cur->next;
//        }
//        if (!cur)
//            break;
//        left++;
//    }
//    return ans;
//}
//
////2938. 区分黑球与白球
//
//long long minimumSteps(char* s)
//{
//    int left = 0, right = strlen(s) - 1;
//    long long ans = 0;
//    while (left < right)
//    {
//        while (left < right && s[left] < '1')
//            left++;
//        while (left < right && s[right] > '0')
//            right--;
//
//        if (left < right)
//        {
//            ans += right - left;
//            right--;
//            left++;
//        }
//    }
//    return ans;
//}
//
////3751. 范围内总波动值 I
//
//int totalWaviness(int num1, int num2)
//{
//    char* high = (char*)malloc(sizeof(char) * 7);
//    char* low = (char*)malloc(sizeof(char) * 7);
//    sprintf(high, "%d", num2);
//    sprintf(low, "%d", num1);
//    int n = strlen(high);
//    int diff = n - strlen(low);
//    int**** memo = (int****)malloc(sizeof(int***) * n);
//    for (int i = 0; i < n; i++)
//    {
//        memo[i] = (int***)malloc(sizeof(int**) * n);
//        for (int j = 0; j < n; j++)
//        {
//            memo[i][j] = (int**)malloc(sizeof(int*) * 3);
//            for (int k = 0; k < 3; k++)
//            {
//                memo[i][j][k] = (int*)malloc(sizeof(int) * 10);
//                memset(memo[i][j][k], -1, sizeof(int) * 10);
//            }
//        }
//    }
//
//    int dfs(int i, int waviness, int lastCmp, int lastDigit, bool limitHigh, bool limitLow)
//    {
//        if (i == n)
//            return waviness;
//
//        int ref = memo[i][waviness][lastCmp + 1][lastDigit];
//        if (!limitHigh && !limitLow && ref != -1)
//            return ref;
//
//        int hi = limitHigh ? high[i] - '0' : 9;
//        int lo = limitLow && i >= diff ? low[i - diff] - '0' : 0;
//
//        int res = 0;
//        bool isNum = !limitLow || i > diff;
//        for (int d = lo; d <= hi; d++)
//        {
//            int cmp = isNum ? (d > lastDigit) - (d < lastDigit) : 0;
//            int new_waviness = waviness + (cmp * lastCmp < 0);
//            res += dfs(i + 1, new_waviness, cmp, d, limitHigh && d == hi, limitLow && d == lo);
//        }
//        if (!limitHigh && !limitLow)
//            memo[i][waviness][lastCmp + 1][lastDigit] = res;
//        return res;
//    }
//    int result = dfs(0, 0, 0, 0, true, true);
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            for (int k = 0; k < 3; k++)
//            {
//                free(memo[i][j][k]);
//            }
//            free(memo[i][j]);
//        }
//        free(memo[i]);
//    }
//    free(memo);
//    free(high);
//    free(low);
//
//    return result;
//}
//
