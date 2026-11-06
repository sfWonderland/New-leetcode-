//// 547. 省份数量
//
//void dfs(int** isConnected, bool* vis, int i, int n)
//{
//    vis[i] = true;
//    for (int j = 0; j < n; j++)
//    {
//        if (isConnected[i][j] && !vis[j])
//            dfs(isConnected, vis, j, n);
//    }
//}
//int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
//{
//    int ans = 0, n = isConnectedSize;
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    for (int i = 0; i < n; i++)
//    {
//        if (vis[i]) continue;
//        ans++;
//        dfs(isConnected, vis, i, n);
//    }
//    free(vis);
//    return ans;
//}
//
