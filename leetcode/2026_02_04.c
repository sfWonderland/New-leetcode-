////113. 路径总和 II
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
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//int** ans;
//int ansSize;
//int* len;
//int* path;
//int pathSize;
//int capacity;
//int getDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return fmax(getDepth(root->left), getDepth(root->right)) + 1;
//}
//void dfs(struct TreeNode* root, int pre, int target)
//{
//    path[pathSize++] = root->val;
//    pre += root->val;
//    if (!root->left && !root->right && pre == target)
//    {
//        ans[ansSize] = (int*)malloc(sizeof(int) * pathSize);
//        memcpy(ans[ansSize], path, sizeof(int) * pathSize);
//        len[ansSize++] = pathSize;
//        if (ansSize >= capacity)
//        {
//            capacity *= 2;
//            ans = (int**)realloc(ans, sizeof(int*) * capacity);
//            len = (int*)realloc(len, sizeof(int) * capacity);
//        }
//    }
//    else
//    {
//        if (root->left)
//            dfs(root->left, pre, target);
//        if (root->right)
//            dfs(root->right, pre, target);
//    }
//    pathSize--;
//}
//int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes)
//{
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int depth = getDepth(root);
//    capacity = 64;
//    ans = (int**)malloc(sizeof(int*) * capacity);
//    ansSize = 0;
//    len = (int*)malloc(sizeof(int) * capacity);
//    path = (int*)malloc(sizeof(int) * depth);
//    pathSize = 0;
//    dfs(root, 0, targetSum);
//    *returnSize = ansSize;
//    *returnColumnSizes = len;
//    return ans;
//}
//
////3640. 三段式数组 II    
//
//long long maxSumTrionic(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long ans = LLONG_MIN;
//    int i = 0;
//    while (i < n)
//    {
//        int start = i++;
//        while (i < n && nums[i - 1] < nums[i])
//            i++;
//        if (i == start + 1)
//            continue;
//
//        int peak = i - 1;
//        long long res = nums[peak - 1] + nums[peak];
//        while (i < n && nums[i - 1] > nums[i])
//            res += nums[i++];
//        if (i == peak + 1 || i == n || nums[i] == nums[i - 1])
//            continue;
//
//        int bottom = i - 1;
//        res += nums[i++];
//        long long s = 0, max_s = 0;
//        while (i < n && nums[i - 1] < nums[i])
//        {
//            s += nums[i++];
//            max_s = fmax(max_s, s);
//        }
//        res += max_s;
//
//        s = max_s = 0;
//        for (int i = peak - 2; i >= start; i--)
//        {
//            s += nums[i];
//            max_s = fmax(max_s, s);
//        }
//        res += max_s;
//        ans = fmax(ans, res);
//
//        i = bottom;
//    }
//    return ans;
//}
//
//long long maxSumTrionic(int* nums, int numsSize)
//{
//    long long ans = LLONG_MIN, f1 = LLONG_MIN, f2 = LLONG_MIN, f3 = LLONG_MIN;
//    for (int i = 1; i < numsSize; i++)
//    {
//        f3 = nums[i] > nums[i - 1] ? fmax(f3, f2) + nums[i] : LLONG_MIN;
//        f2 = nums[i] < nums[i - 1] ? fmax(f2, f1) + nums[i] : LLONG_MIN;
//        f1 = nums[i] > nums[i - 1] ? fmax(f1, nums[i - 1]) + nums[i] : LLONG_MIN;
//        ans = fmax(ans, f3);
//    }
//    return ans;
//}
//
////LCR 143. 子结构判断
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* A, struct TreeNode* B, bool pair)
//{
//    if (B == NULL)
//        return true;
//
//    if (A == NULL)
//        return false;
//
//    struct TreeNode* left = A->left;
//    struct TreeNode* right = A->right;
//    bool res = !pair ? dfs(left, B, 0) || dfs(right, B, 0) : false;
//
//    if (A->val == B->val)
//        res |= dfs(left, B->left, 1) && dfs(right, B->right, 1);
//
//    return res;
//}
//bool isSubStructure(struct TreeNode* A, struct TreeNode* B)
//{
//    if (B == NULL)
//        return false;
//
//    return dfs(A, B, 0);
//}
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* A, struct TreeNode* B)
//{
//    if (B == NULL)
//        return true;
//
//    if (A == NULL || A->val != B->val)
//        return false;
//
//    return dfs(A->left, B->left) && dfs(A->right, B->right);
//}
//bool isSubStructure(struct TreeNode* A, struct TreeNode* B)
//{
//    if (B == NULL)
//        return false;
//
//    return (A && B) &&
//        (dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
//}
//
////LCR 138. 有效数字
//
//bool ScanUnsignedInteger(char* s, int* i, int n)
//{
//    int start = *i;
//    while (*i < n&& s[*i] >= '0' && s[*i] <= '9')
//        (*i)++;
//
//    return *i > start;
//}
//bool ScanInteger(char* s, int* i, int n)
//{
//    if (s[*i] == '+' || s[*i] == '-')
//        (*i)++;
//
//    return ScanUnsignedInteger(s, i, n);
//}
//bool validNumber(char* s)
//{
//    int n = strlen(s);
//    if (!n) return false;
//    int i = 0;
//    while (s[i] == ' ')
//        i++;
//    bool numeric = ScanInteger(s, &i, n);
//    if (s[i] == '.')
//    {
//        i++;
//        numeric = ScanUnsignedInteger(s, &i, n) || numeric;
//    }
//    if (s[i] == 'e' || s[i] == 'E')
//    {
//        i++;
//        numeric = numeric && ScanInteger(s, &i, n);
//    }
//    while (s[i] == ' ')
//        i++;
//    return numeric && i == n;
//}
//
