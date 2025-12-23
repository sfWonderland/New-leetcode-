////65. 有效数字
//
//bool check(char* s, int left, int right, bool mustInteger)
//{
//    // 如果e在开头或者末尾则一定为无效数字
//    if (left > right) return false;
//    // 开头可以是正负号
//    if (s[left] == '+' || s[left] == '-')
//        left++;
//    // 小数点只能出现一次，至少要有一个数字存在
//    bool hasDot = false, hasNum = false;
//    for (int i = left; i <= right; i++)
//    {
//        if (s[i] == '.')
//        {
//            // 如果要求数字必须为整数或者出现多个小数点，则该数字无效
//            if (mustInteger || hasDot) return false;
//            hasDot = true;
//        }
//        else if (s[i] >= '0' && s[i] <= '9')
//            // 数字存在
//            hasNum = true;
//        else
//            // 字母和其它符号出现，该数字无效
//            return false;
//    }
//    return hasNum;
//}
//bool isNumber(char* s)
//{
//    int n = strlen(s);
//    int idxE = -1; // 先找e的坐标
//    for (int i = 0; i < n; i++)
//    {
//        if ((s[i] & 31) == 5) // s[i] == 'E' || s[i] == 'e'
//        {
//            idxE = i;
//            break;
//        }
//    }
//    bool valid = true;
//    if (idxE == -1)
//        // 没有指数，则只需数字满足浮点数即可
//        valid &= check(s, 0, n - 1, false);
//    else
//    {
//        //有指数，则需e前满足浮点数，e后满足为整数
//        valid &= check(s, 0, idxE - 1, false);
//        valid &= check(s, idxE + 1, n - 1, true);
//    }
//    return valid;
//}
//
////52. N 皇后 II
//
//int totalNQueens(int n)
//{
//    bool* on_path = (bool*)calloc(sizeof(bool), n);
//    // 右上方向：行列之差一定，row - col有(2 * n - 1)种，值域[1 - n, n - 1]；
//    bool* diagR = (bool*)calloc(sizeof(bool), (2 * n - 1));
//    // 左上方向：行列之和一定，row + col有(2 * n - 1)种，值域[0, 2 * n - 2]；
//    bool* diagL = (bool*)calloc(sizeof(bool), (2 * n - 1));
//    int dfs(int row)
//    {
//        if (row == n)
//            return 1;
//
//        int ret = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (on_path[i] || diagL[row + i] || diagR[row - i + n - 1])
//                continue;
//
//            on_path[i] = diagL[row + i] = diagR[row - i + n - 1] = true;
//            ret += dfs(row + 1);
//            on_path[i] = diagL[row + i] = diagR[row - i + n - 1] = false;
//        }
//        return ret;
//    }
//    return dfs(0);
//}
//
////95. 不同的二叉搜索树 II
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//struct TreeNode** buildTrees(int start, int end, int* returnSize)
//{
//    if (start > end)
//    {
//        *returnSize = 1;
//        struct TreeNode** ret = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
//        ret[0] = NULL;
//        return ret;
//    }
//
//    *returnSize = 0;
//    struct TreeNode** allTrees = NULL;
//
//    for (int i = start; i <= end; i++)
//    {
//        int leftTreesSize = 0;
//        struct TreeNode** leftTrees = buildTrees(start, i - 1, &leftTreesSize);
//        int rightTreesSize = 0;
//        struct TreeNode** rightTrees = buildTrees(i + 1, end, &rightTreesSize);
//        for (int left = 0; left < leftTreesSize; left++)
//        {
//            for (int right = 0; right < rightTreesSize; right++)
//            {
//                struct TreeNode* curTree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//                curTree->val = i;
//                curTree->left = leftTrees[left];
//                curTree->right = rightTrees[right];
//
//                (*returnSize)++;
//                allTrees = (struct TreeNode**)realloc(allTrees, sizeof(struct TreeNode*) * (*returnSize));
//                allTrees[(*returnSize) - 1] = curTree;
//            }
//        }
//        free(leftTrees);
//        free(rightTrees);
//    }
//    return allTrees;
//}
//struct TreeNode** generateTrees(int n, int* returnSize)
//{
//    return buildTrees(1, n, returnSize);
//}
//
////1859. 将句子排序
//
//char* sortSentence(char* s)
//{
//    char** words = (char**)malloc(sizeof(char*) * 9);
//    int max = 0;
//    int m = strlen(s);
//    for (char* s1 = strtok(s, " "); s1; s1 = strtok(NULL, " "))
//    {
//        int n = strlen(s1);
//        int i = s1[n - 1] - '0';
//        s1[n - 1] = '\0';
//        words[i - 1] = (char*)malloc(sizeof(char) * (n + 1));
//        strcpy(words[i - 1], s1);
//        max = fmax(max, i);
//    }
//    char* ans = (char*)malloc(sizeof(char) * (m - max + 1));
//    int pos = 0;
//    for (int i = 0; i < max; i++)
//    {
//        int n = strlen(words[i]);
//        strcpy(ans + pos, words[i]);
//        pos += n;
//        ans[pos++] = ' ';
//    }
//    ans[--pos] = '\0';
//    return ans;
//}
//
