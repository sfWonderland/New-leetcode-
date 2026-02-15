////969. 煎饼排序
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void reverse(int* arr, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = arr[left];
//        arr[left++] = arr[right];
//        arr[right--] = tmp;
//    }
//}
//int* pancakeSort(int* arr, int arrSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 10 * arrSize);
//    int ansSize = 0, max = arrSize;
//    while (max)
//    {
//        while (max > 0 && max == arr[max - 1])
//            max--;
//        for (int i = 0; i < max; i++)
//        {
//            if (arr[i] == max)
//            {
//                ans[ansSize++] = i + 1;
//                reverse(arr, 0, i);
//                // for(int j = 0; j < arrSize; j++)
//                // {
//                //     printf("%d ", arr[j]);
//                // }
//                // printf("\n");
//                ans[ansSize++] = max;
//                reverse(arr, 0, max - 1);
//                // for(int j = 0; j < arrSize; j++)
//                // {
//                //     printf("%d ", arr[j]);
//                // }
//                // printf("\n");
//                break;
//            }
//        }
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////794. 有效的井字游戏   
//
//bool validTicTacToe(char** board, int boardSize)
//{
//    int flag = 0;
//    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
//        flag = board[0][0] > 'O' ? 1 : -1;
//    if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
//    {
//        int tmp = board[1][1] > 'O' ? 1 : -1;
//        if (tmp * flag < 0)
//            return false;
//        flag = tmp;
//    }
//    for (int i = 0; i < 3; i++)
//    {
//        if (board[i][0] == ' ')
//            continue;
//
//        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
//        {
//            int tmp = board[i][1] > 'O' ? 1 : -1;
//            if (tmp* flag < 0)
//                return false;
//            flag = tmp;
//        }
//        if (board[0][i] == ' ')
//            continue;
//        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
//        {
//            int tmp = board[1][i] > 'O' ? 1 : -1;
//            if (tmp * flag < 0)
//                return false;
//            flag = tmp;
//        }
//    }
//    int numsX = 0, numsO = 0;
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            if (board[i][j] == ' ')
//                continue;
//
//            if (board[i][j] == 'X')
//                numsX++;
//            else
//                numsO++;
//        }
//    }
//    if (!flag)
//        return numsX - numsO <= 1 && numsX >= numsO;
//    else if (flag == -1)
//        return numsX == numsO;
//    else
//        return numsX == numsO + 1;
//}
//
////811. 子域名访问计数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    for (int i = 0; i < cpdomainsSize; i++)
//    {
//        int j = 0;
//        while (cpdomains[i][j] != ' ')
//            j++;
//        cpdomains[i][j++] = '\0';
//        int val = atoi(cpdomains[i]);
//        int left = j;
//        while (cpdomains[i][j])
//        {
//            while (cpdomains[i][j + 1] && cpdomains[i][j] != '.')
//                j++;
//            HASH_FIND_STR(cnt, cpdomains[i] + left, p1);
//            if (p1 == NULL)
//            {
//                p1 = (HashItem*)malloc(sizeof(HashItem));
//                p1->key = cpdomains[i] + left;
//                p1->val = 0;
//                HASH_ADD_STR(cnt, key, p1);
//            }
//            p1->val += val;
//            left = ++j;
//        }
//    }
//    char** ans = (char**)malloc(sizeof(char*) * 3 * cpdomainsSize);
//    *returnSize = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        int n = strlen(p1->key);
//        ans[*returnSize] = (char*)malloc(sizeof(char) * (n + 8));
//        sprintf(ans[*returnSize], "%d %s", p1->val, p1->key);
//        (*returnSize)++;
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//    return ans;
//}
//
////814. 二叉树剪枝
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* dfs(struct TreeNode* root)
//{
//    if (root == NULL)
//        return NULL;
//
//    root->left = dfs(root->left);
//    root->right = dfs(root->right);
//    if (root->left || root->right)
//        return root;
//
//    return root->val == 1 ? root : NULL;
//}
//struct TreeNode* pruneTree(struct TreeNode* root)
//{
//    return dfs(root);
//}
//
