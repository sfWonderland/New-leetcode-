////79. 单词搜索
//
//const int dx[4] = { -1, 0, 0, 1 };
//const int dy[4] = { 0, -1, 1, 0 };
//bool exist(char** board, int boardSize, int* boardColSize, char* word)
//{
//    int m = boardSize, n = boardColSize[0], len = strlen(word);
//    bool** vis = (bool**)malloc(sizeof(bool*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        vis[i] = (bool*)calloc(sizeof(bool), n);
//    }
//    bool dfs(int x, int y, int j)
//    {
//        if (board[x][y] != word[j])
//            return false;
//
//        if (j == len - 1)
//            return true;
//
//        vis[x][y] = true;
//        bool ret = false;
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dx[i];
//            int my = y + dy[i];
//            if (mx < 0 || mx >= m || my < 0 || my >= n || vis[mx][my])
//                continue;
//
//            if (dfs(mx, my, j + 1))
//            {
//                ret = true;
//                break;
//            }
//        }
//        vis[x][y] = false;
//        return ret;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (board[i][j] == word[0] && dfs(i, j, 0))
//                return true;
//        }
//    }
//    return false;
//}
//
////74. 搜索二维矩阵
//
//bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    for (int i = 0; i < m; i++)
//    {
//        if (matrix[i][n - 1] < target)
//            continue;
//
//        int l = 0, r = n - 1;
//        while (l <= r)
//        {
//            int mid = (l + r) / 2;
//            if (matrix[i][mid] >= target)
//                r = mid - 1;
//            else
//                l = mid + 1;
//        }
//        if (matrix[i][l] == target)
//            return true;
//    }
//    return false;
//}
//
////229. 多数元素 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* majorityElement(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = 1;
//    if (numsSize == 1)
//        return nums;
//
//    int cand1 = nums[0], cand2 = nums[0];
//    int cnt1 = 0, cnt2 = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == cand1)
//            cnt1++;
//        else if (nums[i] == cand2)
//            cnt2++;
//        else
//        {
//            if (cnt1 && cnt2)
//            {
//                cnt1--;
//                cnt2--;
//            }
//            else if (cnt1 == 0)
//            {
//                cand1 = nums[i];
//                cnt1 = 1;
//            }
//            else
//            {
//                cand2 = nums[i];
//                cnt2 = 1;
//            }
//        }
//    }
//    cnt1 = 0, cnt2 = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == cand1)
//            cnt1++;
//        else if (nums[i] == cand2)
//            cnt2++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    *returnSize = 0;
//    if (3 * cnt1 > numsSize)
//        ans[(*returnSize)++] = cand1;
//    if (3 * cnt2 > numsSize)
//        ans[(*returnSize)++] = cand2;
//    return ans;
//}
//
////227. 基本计算器 II
//
//int calculate(char* s)
//{
//    int len = strlen(s);
//    int digit[len];
//    memset(digit, 0, sizeof(int) * len);
//    int top = 0;
//    char preSign = '+';
//    for (int i = 0; i < len; i++)
//    {
//        int j = i;
//        while (j < len && s[j] != '+' && s[j] != '-' && s[j] != '*' && s[j] != '/')
//            j++;
//
//        char tmp = '+';
//        if (s[j])
//            tmp = s[j];
//        s[j] = '\0';
//        int num = atoi(s + i);
//        switch (preSign)
//        {
//        case '+': digit[top++] = num; break;
//        case '-': digit[top++] = -num; break;
//        case '*': digit[top - 1] *= num; break;
//        case '/': digit[top - 1] /= num; break;
//        }
//        preSign = tmp;
//        i = j;
//    }
//    int ans = 0;
//    for (int i = 0; i < top; i++)
//    {
//        ans += digit[i];
//    }
//    return ans;
//}
//
