//// 1306. ÌøÔ¾ÓÎÏ· III
//
//bool dfs(int* arr, int start, int n, bool* vis)
//{
//    vis[start] = true;
//    if (arr[start] == 0) return true;
//    int right = start + arr[start];
//    if (right < n && !vis[right] && dfs(arr, right, n, vis))
//        return true;
//    int left = start - arr[start];
//    if (left >= 0 && !vis[left] && dfs(arr, left, n, vis))
//        return true;
//    return false;
//}
//bool canReach(int* arr, int arrSize, int start)
//{
//    int n = arrSize;
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    bool ans = dfs(arr, start, n, vis);
//    free(vis);
//    return ans;
//}
//
