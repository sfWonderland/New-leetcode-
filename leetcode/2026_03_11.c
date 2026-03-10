////967. 连续差相同的数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* numsSameConsecDiff(int n, int k, int* returnSize)
//{
//    int capacity = 8;
//    int* ans = (int*)malloc(sizeof(int) * capacity);
//    int ansSize = 0;
//    char* cur = (char*)malloc(sizeof(char) * (n + 1));
//    int idx = 0;
//    cur[n] = '\0';
//    void dfs(int i)
//    {
//        if (idx == n)
//        {
//            //printf("%s\n", cur);
//            ans[ansSize++] = atoi(cur);
//            if (ansSize >= capacity)
//            {
//                capacity *= 2;
//                ans = (int*)realloc(ans, sizeof(int) * capacity);
//            }
//            return;
//        }
//
//        if (i + k < 10)
//        {
//            cur[idx++] = i + k + '0';
//            dfs(i + k);
//            idx--;
//        }
//
//        if (k && i - k >= 0)
//        {
//            cur[idx++] = i - k + '0';
//            dfs(i - k);
//            idx--;
//        }
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        if (n > 1 && i == 0)
//            continue;
//        cur[idx++] = i + '0';
//        dfs(i);
//        idx--;
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////978. 最长湍流子数组   
//
//int maxTurbulenceSize(int* arr, int arrSize)
//{
//    int n = arrSize;
//    int up[n], down[n];
//    for (int i = 0; i < n; i++)
//    {
//        up[i] = 1;
//        down[i] = 1;
//    }
//    int ans = 1;
//    for (int i = 1; i < n; i++)
//    {
//        if (arr[i - 1] < arr[i])
//            up[i] = down[i - 1] + 1;
//        else if (arr[i - 1] > arr[i])
//            down[i] = up[i - 1] + 1;
//
//        ans = fmax(ans, fmax(up[i], down[i]));
//    }
//    return ans;
//}
//
////1090. 受标签影响的最大值
//
//int* arr;
//int cmp(const void* e1, const void* e2)
//{
//    return arr[*(int*)e2] - arr[*(int*)e1];
//}
//int largestValsFromLabels(int* values, int valuesSize, int* labels, int labelsSize, int numWanted, int useLimit)
//{
//    int n = valuesSize;
//    int idx[n];
//    for (int i = 0; i < n; i++)
//    {
//        idx[i] = i;
//    }
//    arr = values;
//    qsort(idx, n, sizeof(int), cmp);
//    int ans = 0;
//    int cnt[20001];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < n && numWanted; i++)
//    {
//        int j = idx[i];
//        if (cnt[labels[j]] < useLimit)
//        {
//            cnt[labels[j]]++;
//            numWanted--;
//            ans += values[j];
//        }
//    }
//    return ans;
//}
//
////1110. 删点成林
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize)
//{
//    bool del[1001] = { 0 };
//    for (int i = 0; i < to_deleteSize; i++)
//    {
//        del[to_delete[i]] = true;
//    }
//    int capacity = 8;
//    struct TreeNode** ans = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
//    int ansSize = 0;
//    struct TreeNode* dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return NULL;
//        node->left = dfs(node->left);
//        node->right = dfs(node->right);
//        if (!del[node->val]) return node;
//        if (node->left) ans[ansSize++] = node->left;
//        if (ansSize >= capacity)
//        {
//            capacity *= 2;
//            ans = (struct TreeNode**)realloc(ans, sizeof(struct TreeNode*) * capacity);
//        }
//        if (node->right) ans[ansSize++] = node->right;
//        if (ansSize >= capacity)
//        {
//            capacity *= 2;
//            ans = (struct TreeNode**)realloc(ans, sizeof(struct TreeNode*) * capacity);
//        }
//        return NULL;
//    }
//    if (dfs(root))
//        ans[ansSize++] = root;
//    *returnSize = ansSize;
//    return ans;
//}
//
