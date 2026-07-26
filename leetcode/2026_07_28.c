//// 1284. 转化为全零矩阵的最少反转次数
//
//int dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
//int encode(int** mat, int m, int n)
//{
//    int res = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            res <<= 1;
//            res |= mat[i][j];
//        }
//    }
//    return res;
//}
//void decode(int x, int** mat, int m, int n)
//{
//    for (int i = m - 1; i >= 0; i--)
//    {
//        for (int j = n - 1; j >= 0; j--)
//        {
//            mat[i][j] = x & 1;
//            x >>= 1;
//        }
//    }
//}
//void convert(int** mat, int m, int n, int x0, int y0)
//{
//    for (int i = 0; i < 5; i++)
//    {
//        int x = x0 + dir[i][0];
//        int y = y0 + dir[i][1];
//        if (x >= 0 && x < m && y >= 0 && y < n)
//        {
//            mat[x][y] ^= 1;
//        }
//    }
//}
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int minFlips(int** mat, int matSize, int* matColSize)
//{
//    int m = matSize, n = matColSize[0];
//    int start = encode(mat, m, n);
//    if (start == 0) return 0;
//    int** mat_copy = (int**)malloc(sizeof(int*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        mat_copy[i] = (int*)malloc(sizeof(int) * n);
//    }
//    HashItem* vis = NULL;
//    HashItem* p0 = (HashItem*)malloc(sizeof(HashItem));
//    p0->key = start;
//    HASH_ADD_INT(vis, key, p0);
//    int capacity = 8;
//    int* queue = (int*)malloc(sizeof(int) * capacity);
//    int rear = 0, front = 0, step = 0;
//    queue[rear++] = start;
//    bool flag = false;
//    while (rear > front && !flag)
//    {
//        step++;
//        int start = front;
//        front = rear;
//        for (int k = start; k < front; k++)
//        {
//            int x = queue[k];
//            decode(x, mat_copy, m, n);
//            for (int i = 0; i < m; i++)
//            {
//                for (int j = 0; j < n; j++)
//                {
//                    convert(mat_copy, m, n, i, j);
//                    int y = encode(mat_copy, m, n);
//                    if (y == 0)
//                    {
//                        flag = true;
//                        break;
//                    }
//                    HashItem* p = NULL;
//                    HASH_FIND_INT(vis, &y, p);
//                    if (p == NULL)
//                    {
//                        p = (HashItem*)malloc(sizeof(HashItem));
//                        p->key = y;
//                        HASH_ADD_INT(vis, key, p);
//                        queue[rear++] = y;
//                        if (rear >= capacity)
//                        {
//                            capacity *= 2;
//                            queue = (int*)realloc(queue, sizeof(int) * capacity);
//                        }
//                    }
//                    convert(mat_copy, m, n, i, j);
//                }
//            }
//        }
//    }
//    for (int i = 0; i < m; i++)
//    {
//        free(mat_copy[i]);
//    }
//    free(mat_copy);
//    HashItem* p1 = NULL, * tmp = NULL;
//    HASH_ITER(hh, vis, p1, tmp)
//    {
//        HASH_DEL(vis, p1);
//        free(p1);
//    }
//    free(queue);
//    return flag ? step : -1;
//}
//
