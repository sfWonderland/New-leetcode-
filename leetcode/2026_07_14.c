//// 2115. 从给定原材料中找到所有可以做出的菜
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}Ingre;
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}Reci;
//char** findAllRecipes(char** recipes, int recipesSize, char*** ingredients, int ingredientsSize, int* ingredientsColSize, char** supplies, int suppliesSize, int* returnSize)
//{
//    Ingre* resource = NULL;
//    for (int i = 0; i < suppliesSize; i++)
//    {
//        Ingre* p1 = (Ingre*)malloc(sizeof(Ingre));
//        p1->key = supplies[i];
//        HASH_ADD_STR(resource, key, p1);
//    }
//    int n = recipesSize;
//    Reci* dishes = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        Reci* p1 = (Reci*)malloc(sizeof(Reci));
//        p1->key = recipes[i];
//        p1->val = i;
//        HASH_ADD_STR(dishes, key, p1);
//    }
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//        for (int j = 0; j < ingredientsColSize[i]; j++)
//        {
//            Reci* p1 = NULL;
//            HASH_FIND_STR(dishes, ingredients[i][j], p1);
//            if (p1)
//            {
//                grid[i][len[i]++] = p1->val;
//                if (len[i] >= capacity[i])
//                {
//                    capacity[i] *= 2;
//                    grid[i] = (int*)realloc(grid[i], sizeof(int) * capacity[i]);
//                }
//            }
//        }
//    }
//    int vis[n];
//    bool dfs(int i)
//    {
//        vis[i] = 1;
//
//        for (int j = 0; j < len[i]; j++)
//        {
//            int y = grid[i][j];
//            if (vis[y] == 0)
//            {
//                if (!dfs(y))
//                    return false;
//            }
//            else if (vis[y] == 1)
//                return false;
//
//        }
//
//        for (int j = 0; j < ingredientsColSize[i]; j++)
//        {
//            Ingre* p1 = NULL;
//            HASH_FIND_STR(resource, ingredients[i][j], p1);
//            if (p1 == NULL)
//                return false;
//        }
//
//        Ingre* p1 = (Ingre*)malloc(sizeof(Ingre));
//        p1->key = recipes[i];
//        HASH_ADD_STR(resource, key, p1);
//        vis[i] = 2;
//        return true;
//    }
//    char** ans = (char**)malloc(sizeof(char*) * recipesSize);
//    int idx = 0;
//    for (int i = 0; i < recipesSize; i++)
//    {
//        memset(vis, 0, sizeof(vis));
//        if (dfs(i))
//            ans[idx++] = recipes[i];
//    }
//    Ingre* p3 = NULL, * tmp3 = NULL;
//    HASH_ITER(hh, resource, p3, tmp3)
//    {
//        HASH_DEL(resource, p3);
//        free(p3);
//    }
//    Reci* p4 = NULL, * tmp4 = NULL;
//    HASH_ITER(hh, dishes, p4, tmp4)
//    {
//        HASH_DEL(dishes, p4);
//        free(p4);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//    }
//    free(capacity);
//    free(len);
//    free(grid);
//    *returnSize = idx;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key; // 食材名称
//    int val; // 食材编号,大于菜肴编号的是食材编号
//    UT_hash_handle hh;
//}HashItem;
//char** findAllRecipes(char** recipes, int recipesSize, char*** ingredients, int ingredientsSize, int* ingredientsColSize, char** supplies, int suppliesSize, int* returnSize)
//{
//    int n = recipesSize, m = suppliesSize;
//    HashItem* resource = NULL;
//    int* queue = (int*)malloc(sizeof(int) * (n + m));
//    int rear = 0, front = 0;
//    for (int i = 0; i < m; i++)
//    {
//        HashItem* p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = supplies[i];
//        p1->val = i + n;
//        queue[rear++] = p1->val;
//        HASH_ADD_STR(resource, key, p1);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        HashItem* p1 = (HashItem*)malloc(sizeof(HashItem));
//        p1->key = recipes[i];
//        p1->val = i;
//        HASH_ADD_STR(resource, key, p1);
//    }
//    int** grid = (int**)malloc(sizeof(int*) * (n + m));
//    int* capacity = (int*)malloc(sizeof(int) * (n + m));
//    int* len = (int*)malloc(sizeof(int) * (n + m));
//    int* cnt = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n + m; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < ingredientsColSize[i]; j++)
//        {
//            HashItem* p1 = NULL;
//            HASH_FIND_STR(resource, ingredients[i][j], p1);
//            if (p1 == NULL)
//                continue;
//            int x = p1->val;
//            grid[x][len[x]++] = i;
//            if (len[x] >= capacity[x])
//            {
//                capacity[x] *= 2;
//                grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//            }
//        }
//        cnt[i] = ingredientsColSize[i];
//    }
//    char** ans = (char**)malloc(sizeof(char*) * recipesSize);
//    int idx = 0;
//    while (rear > front)
//    {
//        int x = queue[front++];
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            cnt[y]--;
//            if (cnt[y] == 0)
//            {
//                queue[rear++] = y;
//                ans[idx++] = recipes[y];
//            }
//        }
//    }
//    HashItem* p = NULL, * tmp = NULL;
//    HASH_ITER(hh, resource, p, tmp)
//    {
//        HASH_DEL(resource, p);
//        free(p);
//    }
//    for (int i = 0; i < n + m; i++)
//    {
//        free(grid[i]);
//    }
//    free(capacity);
//    free(len);
//    free(grid);
//    *returnSize = idx;
//    return ans;
//}
//
