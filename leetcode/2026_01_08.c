////1886. 判断矩阵经轮转后是否一致
//
//// n为矩阵行列数，(i, j)为矩阵元素坐标（从0开始）
//// 顺时针翻转90度：先左右镜像翻转，再转置 （坐标值等于mat[n - 1 - j][i]）| 轮转1次
//// 翻转180度：先左右翻转，再上下翻转（坐标值等于mat[n - 1 - i][n - 1 - j]） | 轮转2次
//// 逆时针翻转90度：先上下镜像翻转，再转置（坐标值等于mat[j][n - 1 - i]） | 轮转3次
//// 后面都是重复
//bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize)
//{
//    int n = matSize - 1;
//    int flag = 15; // 1111
//    for (int i = 0; i < n + 1; i++)
//    {
//        for (int j = 0; j < n + 1; j++)
//        {
//            flag &= (((mat[i][j] == target[i][j]) << 3) | 7);
//            flag &= (((mat[n - j][i] == target[i][j]) << 2) | 11);
//            flag &= (((mat[n - i][n - j] == target[i][j]) << 1) | 13);
//            flag &= ((mat[j][n - i] == target[i][j]) | 14);
//        }
//        if (!flag)
//            return false;
//    }
//    return true;
//}
//
////1325. 删除给定值的叶子节点   
//
//// /**
////  * Definition for a binary tree node.
////  * struct TreeNode {
////  *     int val;
////  *     struct TreeNode *left;
////  *     struct TreeNode *right;
////  * };
////  */
//// struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) 
//// {
////     bool dfs(struct TreeNode* root)
////     {
////         if(root == NULL)
////         return true;
//
////         if(dfs(root -> left))
////         {
////             if(root -> left && root -> left -> val == target)
////             root -> left = NULL;
////         }
//
////         if(dfs(root -> right))
////         {
////             if(root -> right && root -> right -> val == target)
////             root -> right = NULL;
////         }
//
////         return !root -> left && !root -> right;
////     }    
////     dfs(root);
////     if(root -> left || root -> right)
////     return root;
////     else
////     return root -> val == target ? NULL : root;
//// }
//struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
//{
//    struct TreeNode* dfs(struct TreeNode* root)
//    {
//        if (root == NULL)
//            return NULL;
//
//        root->left = dfs(root->left);
//        root->right = dfs(root->right);
//
//        if (!root->left && !root->right)
//            return root->val == target ? NULL : root;
//
//        return root;
//    }
//    return dfs(root);
//}
//
////2451. 差值数组不同的字符串
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//char* oddString(char** words, int wordsSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    int n = strlen(words[0]);
//    char* diff = (char*)malloc(sizeof(char) * n);
//    diff[n - 1] = '\0';
//    for (int i = 0; i < wordsSize; i++)
//    {
//        for (int j = 0; j < n - 1; j++)
//        {
//            diff[j] = words[i][j + 1] - words[i][j] + 27;
//        }
//        HASH_FIND_STR(cnt, diff, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * n);
//            strcpy(pEntry->key, diff);
//            pEntry->val = 100 * i;
//            HASH_ADD_STR(cnt, key, pEntry);
//        }
//        pEntry->val++;
//    }
//    HashItem* tmp = NULL;
//    char* ans = NULL;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        if (pEntry->val % 100 == 1)
//            ans = words[pEntry->val / 100];
//
//        free(pEntry);
//    }
//    return ans;
//}
//
////1508. 子数组和排序后的区间和
//
//const int MOD = 1e9 + 7;
//int rangeSum(int* nums, int numsSize, int n, int left, int right)
//{
//    int* preSum = (int*)malloc(sizeof(int) * (n + 1));
//    preSum[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        preSum[i + 1] = preSum[i] + nums[i];
//    }
//    int* prePreSum = (int*)malloc(sizeof(int) * (n + 1));
//    prePreSum[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        prePreSum[i + 1] = prePreSum[i] + preSum[i + 1];
//    }
//
//    int getCount(int x)
//    {
//        int cnt = 0, j = 1;
//        for (int i = 0; i < n; i++)
//        {
//            while (j <= n && preSum[j] - preSum[i] <= x)
//            {
//                j++;
//            }
//            j--;
//            cnt += j - i;
//        }
//        return cnt;
//    }
//
//    int getKth(int k)
//    {
//        int l = 0, r = prePreSum[n];
//        while (l <= r)
//        {
//            int mid = (l + r) / 2;
//            if (getCount(mid) >= k)
//                r = mid - 1;
//            else
//                l = mid + 1;
//        }
//        return l;
//    }
//
//    long long getSum(int k)
//    {
//        int num = getKth(k);
//        long long tot = 0;
//        int cnt = 0, j = 1;
//        for (int i = 0; i < n; i++)
//        {
//            while (j <= n && preSum[j] - preSum[i] < num)
//            {
//                j++;
//            }
//            j--;
//
//            tot += prePreSum[j] - prePreSum[i] - preSum[i] * (j - i);
//            cnt += j - i;
//        }
//        tot += (k - cnt) * num;
//        return tot;
//    }
//    return (getSum(right) - getSum(left - 1)) % MOD;
//}
//
