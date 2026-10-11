//// 684. 冗余连接
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int find(int* parent, int x)
//{
//    if (parent[x] != x)
//        parent[x] = find(parent, parent[x]);
//
//    return parent[x];
//}
//void Union(int* parent, int a, int b)
//{
//    parent[find(parent, a)] = parent[find(parent, b)];
//}
//int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
//{
//    *returnSize = 2;
//    int n = edgesSize;
//    int parent[n + 1];
//    for (int i = 1; i <= n; i++)
//    {
//        parent[i] = i;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int a = edges[i][0];
//        int b = edges[i][1];
//        if (find(parent, a) != find(parent, b))
//            Union(parent, a, b);
//        else
//            return edges[i];
//    }
//    return NULL;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int find(int* parent, int x)
//{
//    int root = x;
//    while (parent[root] > 0)
//    {
//        root = parent[root];
//    }
//    while (x != root)
//    {
//        int tmp = parent[x];
//        parent[x] = root;
//        x = tmp;
//    }
//
//    return root;
//}
//void Union(int* parent, int a, int b)
//{
//    int root1 = find(parent, a);
//    int root2 = find(parent, b);
//    if (parent[root1] < parent[root2])
//    {
//        parent[root1] += parent[root2];
//        parent[root2] = root1;
//    }
//    else
//    {
//        parent[root2] += parent[root1];
//        parent[root1] = root2;
//    }
//}
//int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
//{
//    *returnSize = 2;
//    int n = edgesSize;
//    int parent[n + 1];
//    for (int i = 1; i <= n; i++)
//    {
//        parent[i] = -1;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int a = edges[i][0];
//        int b = edges[i][1];
//        if (find(parent, a) != find(parent, b))
//            Union(parent, a, b);
//        else
//            return edges[i];
//    }
//    return NULL;
//}
//
//// 3493. 属性图    
//
//int intersect(int* arr1, int* arr2, int n)
//{
//    bool nums[101] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        nums[arr1[i]] = true;
//    }
//    int cnt = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cnt += nums[arr2[i]];
//        nums[arr2[i]] = false;
//    }
//    return cnt;
//}
//int find(int* parent, int a)
//{
//    int root = a;
//    while (parent[root] >= 0)
//        root = parent[root];
//    while (a != root)
//    {
//        int tmp = parent[a];
//        parent[a] = root;
//        a = tmp;
//    }
//    return root;
//}
//void Union(int* parent, int a, int b)
//{
//    int root1 = find(parent, a);
//    int root2 = find(parent, b);
//    if (root1 == root2) return;
//    if (parent[root1] < parent[root2])
//    {
//        parent[root1] += parent[root2];
//        parent[root2] = root1;
//    }
//    else
//    {
//        parent[root2] += parent[root1];
//        parent[root1] = root2;
//    }
//}
//int numberOfComponents(int** properties, int propertiesSize, int* propertiesColSize, int k)
//{
//    int n = propertiesSize, m = propertiesColSize[0];
//    int parent[n];
//    for (int i = 0; i < n; i++)
//    {
//        parent[i] = -1;
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (intersect(properties[i], properties[j], m) >= k)
//                Union(parent, i, j);
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans += (parent[i] < 0);
//    }
//    return ans;
//}
//
//// 990. 等式方程的可满足性
//
//int find(int* parent, int a)
//{
//    int root = a;
//    while (parent[root] >= 0)
//    {
//        root = parent[root];
//    }
//    while (a != root)
//    {
//        int tmp = parent[a];
//        parent[a] = root;
//        a = tmp;
//    }
//    return root;
//}
//void Union(int* parent, int a, int b)
//{
//    int root1 = find(parent, a);
//    int root2 = find(parent, b);
//    if (root1 == root2) return;
//    if (parent[root1] < parent[root2])
//    {
//        parent[root1] += parent[root2];
//        parent[root2] = root1;
//    }
//    else
//    {
//        parent[root2] += parent[root1];
//        parent[root1] = root2;
//    }
//}
//bool equationsPossible(char** equations, int equationsSize)
//{
//    int parent[26];
//    for (int i = 0; i < 26; i++)
//    {
//        parent[i] = -1;
//    }
//    int n = equationsSize;
//    for (int i = 0; i < n; i++)
//    {
//        if (equations[i][1] == '!') continue;
//        int a = equations[i][0] - 'a';
//        int b = equations[i][3] - 'a';
//        Union(parent, a, b);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (equations[i][1] == '=') continue;
//        int a = equations[i][0] - 'a';
//        int b = equations[i][3] - 'a';
//        if (find(parent, a) == find(parent, b))
//            return false;
//    }
//    return true;
//}
//
//// 3532. 针对图的路径存在性查询 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int find(int* parent, int a)
//{
//    int root = a;
//    while (parent[root] >= 0)
//        root = parent[root];
//    while (a != root)
//    {
//        int tmp = parent[a];
//        parent[a] = root;
//        a = tmp;
//    }
//    return root;
//}
//void Union(int* parent, int a, int b)
//{
//    int root1 = find(parent, a);
//    int root2 = find(parent, b);
//    if (root1 == root2) return;
//    if (parent[root1] < parent[root2])
//    {
//        parent[root1] += parent[root2];
//        parent[root2] = root1;
//    }
//    else
//    {
//        parent[root2] += parent[root1];
//        parent[root1] = root2;
//    }
//}
//
//bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int parent[n];
//    for (int i = 0; i < n; i++)
//    {
//        parent[i] = -1;
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (nums[j] - nums[i] <= maxDiff)
//                Union(parent, i, j);
//            else
//                break;
//        }
//    }
//    bool* ans = (bool*)calloc(sizeof(bool), queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int a = queries[i][0];
//        int b = queries[i][1];
//        if (find(parent, a) == find(parent, b))
//            ans[i] = true;
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    // 连通图编号
//    int id[n];
//    id[0] = 0;
//    for (int i = 1; i < n; i++)
//    {
//        id[i] = id[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
//    }
//    bool* ans = (bool*)calloc(queriesSize, sizeof(bool));
//    for (int i = 0; i < queriesSize; i++)
//    {
//        ans[i] = (id[queries[i][0]] == id[queries[i][1]]);
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
