////3407. 子字符串匹配模式
//
//bool hasMatch(char* s, char* p)
//{
//    char* left = p, * right = p;
//    for (int i = 0; ; i++)
//    {
//        if (p[i] == '*')
//        {
//            right = p + i + 1;
//            p[i] = '\0';
//            break;
//        }
//    }
//    int m = strlen(left), k = 0;
//    int n = strlen(s);
//    if (m > 0)
//    {
//        for (int i = 0; i <= n - m; i++)
//        {
//            if (strncmp(s + i, left, m) == 0)
//            {
//                k = i + m;
//                break;
//            }
//        }
//        if (k == 0)
//            return false;
//    }
//
//    char* sub2 = strstr(s + k, right);
//    if (sub2 == NULL)
//        return false;
//
//    return true;
//}
//
//// 3417. 跳过交替单元格的之字形遍历   
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* zigzagTraversal(int** grid, int gridSize, int* gridColSize, int* returnSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int sum = (m * n + 1) / 2;
//    int* ans = (int*)malloc(sizeof(int) * sum);
//    int ansSize = 0, right = n & 1 ? n - 2 : n - 1;
//    for (int i = 0; i < m; i++)
//    {
//        if (i & 1)
//        {
//            for (int j = right; j > 0; j -= 2)
//            {
//                ans[ansSize++] = grid[i][j];
//            }
//        }
//        else
//        {
//            for (int j = 0; j < n; j += 2)
//            {
//                ans[ansSize++] = grid[i][j];
//            }
//        }
//    }
//    *returnSize = sum;
//    return ans;
//}
//
////3438. 找到字符串中合法的相邻数字
//
//char* findValidPair(char* s)
//{
//    int cnt[10] = { 0 };
//    int n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - '0']++;
//    }
//    char* ans = (char*)malloc(sizeof(char) * 3);
//    ans[2] = '\0';
//    for (int i = 0; i < n - 1; i++)
//    {
//        int x = s[i] - '0', y = s[i + 1] - '0';
//        if (x != y && cnt[x] == x && cnt[y] == y)
//        {
//            ans[0] = s[i];
//            ans[1] = s[i + 1];
//            return ans;
//        }
//    }
//    ans[0] = '\0';
//    return ans;
//}
//
////3483. 不同三位偶数的数目
//
//int totalNumbers(int* digits, int digitsSize)
//{
//    int cnt[10] = { 0 }, types = 0;
//    for (int i = 0; i < digitsSize; i++)
//    {
//        types += (cnt[digits[i]] == 0);
//        cnt[digits[i]]++;
//    }
//    int ans = 0;
//    for (int f = 1; f < 10; f++)
//    {
//        if (cnt[f] == 0)
//            continue;
//
//        for (int l = 0; l < 10; l += 2)
//        {
//            if (f == l && cnt[l] >= 2)
//            {
//                if (cnt[l] == 2)
//                    ans += types - 1;
//                else
//                    ans += types;
//            }
//            else if (f != l && cnt[l])
//            {
//                if (cnt[f] == 1 && cnt[l] == 1)
//                    ans += types - 2;
//                else if (cnt[f] == 1 || cnt[l] == 1)
//                    ans += types - 1;
//                else
//                    ans += types;
//            }
//        }
//    }
//    return ans;
//}
//
