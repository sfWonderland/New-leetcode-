//// 773. ª¨∂Ø√’Ã‚
//
//int encode(int** board, int m, int n)
//{
//    int res = 0, x = -1, y = -1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            res <<= 3;
//            res |= board[i][j];
//            if (board[i][j] == 0)
//            {
//                x = i; y = j;
//            }
//        }
//    }
//    res <<= 2;
//    res |= x;
//    res <<= 2;
//    res |= y;
//    return res;
//}
//void decode(int x, int** board, int m, int n)
//{
//    x >>= 4;
//    for (int i = m - 1; i >= 0; i--)
//    {
//        for (int j = n - 1; j >= 0; j--)
//        {
//            board[i][j] = x & 7;
//            x >>= 3;
//        }
//    }
//}
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//int slidingPuzzle(int** board, int boardSize, int* boardColSize)
//{
//    int m = boardSize, n = boardColSize[0];
//    int start = encode(board, m, n);
//    if ((start >> 4) == 0xA728) return 0;
//    int capacity = 8;
//    int* queue = (int*)malloc(sizeof(int) * capacity);
//    int rear = 0, front = 0, step = 0;
//    queue[rear++] = start;
//    HashItem* vis = NULL;
//    HashItem* p0 = (HashItem*)malloc(sizeof(HashItem));
//    p0->key = start;
//    HASH_ADD_INT(vis, key, p0);
//    bool flag = false;
//    while (rear > front && !flag)
//    {
//        step++;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front && !flag; i++)
//        {
//            int code = queue[i];
//            decode(code, board, m, n);
//            int x = (code & 15) >> 2;
//            int y = code & 3;
//            for (int j = 0; j < 4; j++)
//            {
//                int mx = x + dir[j][0];
//                int my = y + dir[j][1];
//                if (mx >= 0 && mx < m && my >= 0 && my < n)
//                {
//                    swap(&board[x][y], &board[mx][my]);
//                    // for(int a = 0; a < m; a++)
//                    // {
//                    //     for(int b = 0; b < n; b++)
//                    //     {
//                    //         printf("%d ", board[a][b]);
//                    //     }
//                    //     printf("\n");
//                    // }
//                    int new_code = encode(board, m, n);
//                    // printf("%x\n", new_code >> 4);
//                    if ((new_code >> 4) == 0xa728)
//                    {
//                        flag = true;
//                        break;
//                    }
//                    HashItem* p1 = NULL;
//                    HASH_FIND_INT(vis, &new_code, p1);
//                    if (p1 == NULL)
//                    {
//                        p1 = (HashItem*)malloc(sizeof(HashItem));
//                        p1->key = new_code;
//                        HASH_ADD_INT(vis, key, p1);
//
//                        queue[rear++] = new_code;
//                        if (rear >= capacity)
//                        {
//                            capacity *= 2;
//                            queue = (int*)realloc(queue, sizeof(int) * capacity);
//                        }
//                    }
//                    swap(&board[x][y], &board[mx][my]);
//                }
//            }
//        }
//    }
//    free(queue);
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, vis, p0, tmp)
//    {
//        HASH_DEL(vis, p0);
//        free(p0);
//    }
//    // printf("%d ", step);
//    return flag ? step : -1;
//}
//
