////3625. 统计梯形的数目 II
//
//class Solution {
//public:
//    int countTrapezoids(vector<vector<int>>& points)
//    {
//        unordered_map<double, vector<double>> groups;  // 斜率 -> [截距]  
//        unordered_map<int, vector<double>> groups2;    // 中点 -> [斜率]
//        int n = points.size();
//        for (int i = 0; i < n; i++)
//        {
//            int x = points[i][0], y = points[i][1];
//            for (int j = 0; j < i; j++)
//            {
//                int x2 = points[j][0], y2 = points[j][1];
//                int dx = x - x2;
//                int dy = y - y2;
//                double k = dx ? 1.0 * dy / dx : DBL_MAX;
//                double b = dx ? 1.0 * (y * dx - x * dy) / dx : x;
//                groups[k].push_back(b);
//                int mid = (x + x2 + 2000) << 16 | (y + y2 + 2000);
//                groups2[mid].push_back(k);
//            }
//        }
//        int ans = 0;
//        for (auto& [_, g] : groups)
//        {
//            if (g.size() == 1)
//                continue;
//
//            map<double, int> cnt;
//            for (double b : g)
//            {
//                cnt[b]++;
//            }
//
//            int s = 0;
//            for (auto& [_, c] : cnt)
//            {
//                ans += s * c;
//                s += c;
//            }
//        }
//
//        for (auto& [_, g] : groups2)
//        {
//            if (g.size() == 1)
//                continue;
//
//            map<double, int> cnt;
//            for (double k : g)
//            {
//                cnt[k]++;
//            }
//
//            int s = 0;
//            for (auto& [_, c] : cnt)
//            {
//                ans -= s * c;
//                s += c;
//            }
//        }
//        return ans;
//    }
//};
//
////1497. 检查数组对是否可以被 k 整除
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//bool canArrange(int* arr, int arrSize, int k)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < arrSize; i++)
//    {
//        int m = (arr[i] % k + k) % k;
//        HASH_FIND_INT(cnt, &m, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = m;
//            pEntry->val = 1;
//            HASH_ADD_INT(cnt, key, pEntry);
//        }
//        else
//            pEntry->val++;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        int t = (k - pEntry->key) % k;
//        if (t == 0)
//        {
//            if (pEntry->val % 2)
//                return false;
//
//            continue;
//        }
//        HashItem* pair = NULL;
//        HASH_FIND_INT(cnt, &t, pair);
//        if (pair == NULL || pair->val < pEntry->val)
//            return false;
//    }
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        free(pEntry);
//    }
//    return true;
//}
//
//bool canArrange(int* arr, int arrSize, int k)
//{
//    int cnt[k];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < arrSize; i++)
//    {
//        arr[i] = (arr[i] % k + k) % k;
//        cnt[arr[i]]++;
//    }
//    if (cnt[0] % 2)
//        return false;
//    for (int i = 1; i <= k / 2; i++)
//    {
//        if (i == k - i)
//        {
//            if (cnt[i] % 2)
//                return false;
//        }
//        else
//        {
//            if (cnt[i] != cnt[k - i])
//                return false;
//        }
//    }
//    return true;
//}
//
////240. 搜索二维矩阵 II
//
//bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    int i = 0, j = n - 1;
//    while (i < m && j >= 0)
//    {
//        if (matrix[i][j] == target)
//            return true;
//
//        if (matrix[i][j] > target)
//            j--;
//        else
//            i++;
//    }
//    return false;
//}
//
////207. 课程表
//
//bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
//{
//    int** lessons = (int**)malloc(sizeof(int*) * numCourses);
//    int* len = (int*)calloc(sizeof(int), numCourses);
//    int* capacity = (int*)malloc(sizeof(int) * numCourses);
//    for (int i = 0; i < numCourses; i++)
//    {
//        capacity[i] = 64;
//        lessons[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < prerequisitesSize; i++)
//    {
//        int x = prerequisites[i][0], y = prerequisites[i][1];
//        lessons[y][len[y]++] = x;
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            lessons[y] = (int*)realloc(lessons[y], sizeof(int) * capacity[y]);
//        }
//    }
//    int* vis = (int*)calloc(sizeof(int), numCourses);
//    bool dfs(int x)
//    {
//        vis[x] = 1;
//        for (int j = 0; j < len[x]; j++)
//        {
//            int y = lessons[x][j];
//            if (vis[y] == 1 || vis[y] == 0 && dfs(y))
//                return true;
//        }
//        vis[x] = 2;
//        return false;
//    }
//    for (int i = 0; i < numCourses; i++)
//    {
//        if (vis[i] == 0 && dfs(i))
//            return false;
//    }
//    return true;
//}
//
