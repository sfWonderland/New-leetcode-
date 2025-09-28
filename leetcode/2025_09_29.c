////3361. 两个字符串的切换距离
//
//long long shiftDistance(char* s, char* t, int* nextCost, int nextCostSize, int* previousCost, int previousCostSize)
//{
//    long long nxt[27] = { 0 };
//    nxt[0] = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        nxt[i + 1] = nxt[i] + nextCost[i];
//    }
//    long long pre[27] = { 0 };
//    pre[0] = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        pre[i + 1] = pre[i] + previousCost[i];
//    }
//    long long sum = 0;
//    long long next = 0, back = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] - t[i] > 0)
//        {
//            next = nxt[26] - nxt[s[i] - 'a'] + nxt[t[i] - 'a'];
//            back = pre[s[i] - 'a' + 1] - pre[t[i] - 'a' + 1];
//            sum += fmin(next, back);
//        }
//        else if (s[i] - t[i] < 0)
//        {
//            next = nxt[t[i] - 'a'] - nxt[s[i] - 'a'];
//            back = pre[26] - pre[t[i] - 'a' + 1] + pre[s[i] - 'a' + 1];
//            sum += fmin(next, back);
//        }
//    }
//    return sum;
//}
//
////1314. 矩阵区域和
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    int m = matSize, n = matColSize[0];
//    int** sum = (int**)malloc(sizeof(int*) * (m + 1));
//    sum[0] = (int*)calloc(sizeof(int), (n + 1));
//    for (int i = 0; i < m; i++)
//    {
//        sum[i + 1] = (int*)calloc(sizeof(int), (n + 1));
//        for (int j = 0; j < n; j++)
//        {
//            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
//        }
//    }
//
//    int** ans = (int**)malloc(sizeof(int*) * m);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * n);
//        (*returnColumnSizes)[i] = n;
//        for (int j = 0; j < n; j++)
//        {
//            int x1 = fmax(fmin(i - k, m), 0), x2 = fmax(fmin(i + k + 1, m), 0);
//            int y1 = fmax(fmin(j - k, n), 0), y2 = fmax(fmin(j + k + 1, n), 0);
//            ans[i][j] = sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
////3070. 元素和小于等于 k 的子矩阵的数目
//
//int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k)
//{
//    if (grid[0][0] > k)
//        return 0;
//    int m = gridSize, n = gridColSize[0];
//    int** sum = (int**)malloc(sizeof(int*) * m);
//    int ans = 0;
//    sum[0] = (int*)calloc(sizeof(int), n);
//    sum[0][0] = grid[0][0];
//    int dx = n;
//    for (int i = 1; i < n; i++)
//    {
//        sum[0][i] = sum[0][i - 1] + grid[0][i];
//        if (sum[0][i] > k)
//        {
//            dx = i;
//            break;
//        }
//    }
//    ans += dx;
//    dx = m - 1;
//    for (int i = 1; i < m; i++)
//    {
//        sum[i] = (int*)calloc(sizeof(int), n);
//        sum[i][0] = sum[i - 1][0] + grid[i][0];
//        if (sum[i][0] > k)
//        {
//            dx = i - 1;
//            break;
//        }
//        int dy = n - 1;
//        for (int j = 1; j < n; j++)
//        {
//            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i][j];
//            if (sum[i][j] > k)
//            {
//                dy = j - 1;
//                break;
//            }
//        }
//        ans += dy;
//    }
//    ans += dx;
//    return ans;
//}
//
////380. O(1) 时间插入、删除和获取随机元素
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//} HashItem;
//
//typedef struct
//{
//    int* nums;
//    int numsSize;
//    HashItem* indices;
//} RandomizedSet;
//
//
//RandomizedSet* randomizedSetCreate()
//{
//    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
//    obj->nums = (int*)malloc(sizeof(int) * 100001);
//    obj->numsSize = 0;
//    obj->indices = NULL;
//    return obj;
//}
//
//bool randomizedSetInsert(RandomizedSet* obj, int val)
//{
//    HashItem* tmp = NULL;
//    HASH_FIND_INT(obj->indices, &val, tmp);
//    if (tmp == NULL)
//    {
//        HashItem* tmp = (HashItem*)malloc(sizeof(HashItem));
//        tmp->key = val;
//        tmp->val = obj->numsSize;
//        HASH_ADD_INT(obj->indices, key, tmp);
//        obj->nums[obj->numsSize++] = val;
//        return true;
//    }
//    return false;
//}
//
//bool randomizedSetRemove(RandomizedSet* obj, int val)
//{
//    HashItem* tmp = NULL;
//    HASH_FIND_INT(obj->indices, &val, tmp);
//    if (tmp)
//    {
//        int index = tmp->val;
//        HASH_DEL(obj->indices, tmp);
//        free(tmp);
//        int x = obj->nums[obj->numsSize - 1];
//        HASH_FIND_INT(obj->indices, &x, tmp);
//        if (tmp)
//            tmp->val = index;
//        obj->nums[index] = obj->nums[obj->numsSize - 1];
//        obj->numsSize--;
//        return true;
//    }
//    return false;
//}
//
//int randomizedSetGetRandom(RandomizedSet* obj)
//{
//    int t = rand() % obj->numsSize;
//    return obj->nums[t];
//}
//
//void randomizedSetFree(RandomizedSet* obj)
//{
//    HashItem* tmp = NULL;
//    HashItem* s = NULL;
//    HASH_ITER(hh, obj -> indices, s, tmp)
//    {
//        HASH_DEL(obj->indices, s);
//        free(s);
//    }
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your RandomizedSet struct will be instantiated and called as such:
// * RandomizedSet* obj = randomizedSetCreate();
// * bool param_1 = randomizedSetInsert(obj, val);
//
// * bool param_2 = randomizedSetRemove(obj, val);
//
// * int param_3 = randomizedSetGetRandom(obj);
//
// * randomizedSetFree(obj);
//*/
//
