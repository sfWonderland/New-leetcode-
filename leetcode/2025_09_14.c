////547. 省份数量
//
//void dfs(int** arr, int i, int n, bool* vis)
//{
//    vis[i] = true;
//    for (int j = 0; j < n; j++)
//    {
//        if (!vis[j] && arr[i][j])
//            dfs(arr, j, n, vis);
//    }
//}
//int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
//{
//    int n = isConnectedSize;
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (!vis[i])
//        {
//            dfs(isConnected, i, n, vis);
//            ans++;
//        }
//    }
//    return ans;
//}
//
////797. 所有可能的路径
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** ans;
//int ansSize;
//int* tmp;
//int top;
//int n;
//int* len;
//int lenSize;
//void dfs(int** graph, int i, int* graphColSize)
//{
//    tmp[top++] = i;
//    if (i == n - 1)
//    {
//        ans[ansSize] = (int*)malloc(sizeof(int) * top);
//        memcpy(ans[ansSize], tmp, sizeof(int) * top);
//        ansSize++;
//        len[lenSize++] = top;
//    }
//    else
//    {
//        for (int j = 0; j < graphColSize[i]; j++)
//        {
//            dfs(graph, graph[i][j], graphColSize);
//            top--;
//        }
//    }
//}
//int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes)
//{
//    n = graphSize;
//    ans = (int**)malloc(sizeof(int*) * 8000);
//    len = (int*)malloc(sizeof(int) * 8000);
//    ansSize = 0;
//    lenSize = 0;
//    top = 0;
//    tmp = (int*)malloc(sizeof(int) * n);
//    dfs(graph, 0, graphColSize);
//    *returnSize = ansSize;
//    *returnColumnSizes = len;
//    return ans;
//}
//
////841. 钥匙和房间
//
//int n;
//void dfs(int** rooms, int i, int* roomsColSize, bool* vis)
//{
//    vis[i] = true;
//    for (int j = 0; j < roomsColSize[i]; j++)
//    {
//        int x = rooms[i][j];
//        if (!vis[x])
//            dfs(rooms, x, roomsColSize, vis);
//    }
//}
//bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
//{
//    n = roomsSize;
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    dfs(rooms, 0, roomsColSize, vis);
//    for (int i = 0; i < n; i++)
//    {
//        if (!vis[i])
//            return false;
//    }
//    return true;
//}
//
////257. 二叉树的所有路径
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
//char** ans;
//int ansSize;
//char* tmp;
//int idx;
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//void dfs(struct TreeNode* node)
//{
//    int x = node->val;
//    if (x < 0)
//    {
//        tmp[idx++] = '-';
//        x = -x;
//    }
//    int left = idx;
//    while (x)
//    {
//        tmp[idx++] = x % 10 + '0';
//        x /= 10;
//    }
//    reverse(tmp, left, idx - 1);
//    int pre = idx;
//    if (node->left || node->right)
//    {
//        if (node->left)
//        {
//            tmp[idx++] = '-';
//            tmp[idx++] = '>';
//            dfs(node->left);
//            idx = pre;
//        }
//        if (node->right)
//        {
//            tmp[idx++] = '-';
//            tmp[idx++] = '>';
//            dfs(node->right);
//            idx = pre;
//        }
//    }
//    else
//    {
//        ans[ansSize] = (char*)malloc(sizeof(char) * (idx + 1));
//        memcpy(ans[ansSize], tmp, sizeof(char) * idx);
//        ans[ansSize++][idx] = '\0';
//    }
//}
//char** binaryTreePaths(struct TreeNode* root, int* returnSize)
//{
//    ans = (char**)malloc(sizeof(char) * 1000);
//    ansSize = 0;
//    tmp = (char*)malloc(sizeof(char) * 101);
//    idx = 0;
//    dfs(root);
//    *returnSize = ansSize;
//    return ans;
//}
//
