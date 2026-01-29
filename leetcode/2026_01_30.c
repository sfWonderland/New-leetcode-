////3342. 到达最后一个房间的最少时间 II
//
//typedef struct
//{
//    int wt;
//    int x;
//    int y;
//}Node;
//// void print(Node heap[], int heapSize)
//// {
////     for(int i = 0; i < heapSize; i++)
////     {
////         int wt = heap[i].wt;
////         int x = heap[i].x;
////         int y = heap[i].y;
////         printf("%d %d %d\n", wt, x, y);
////     }
//// }
//void overWrite(Node* a, Node* b)
//{
//    (*a).wt = (*b).wt;
//    (*a).x = (*b).x;
//    (*a).y = (*b).y;
//}
//void up(Node heap[], int i)
//{
//    Node tmp = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j].wt <= tmp.wt)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//        if (j == 0)
//            break;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void down(Node heap[], int i, int n)
//{
//    Node tmp = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1].wt < heap[j].wt)
//            j++;
//        if (heap[j].wt >= tmp.wt)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void emplace(Node heap[], int* n, int wt, int x, int y)
//{
//    heap[*n].wt = wt;
//    heap[*n].x = x;
//    heap[*n].y = y;
//    up(heap, (*n)++);
//}
//void pop(Node heap[], int* n)
//{
//    heap[0].wt = heap[--(*n)].wt;
//    heap[0].x = heap[*n].x;
//    heap[0].y = heap[*n].y;
//    down(heap, 0, *n);
//}
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize)
//{
//    int n = moveTimeSize, m = moveTimeColSize[0];
//    int dis[n][m];
//    memset(dis, 0x3f, sizeof(dis));
//    dis[0][0] = 0;
//    Node heap[m * n * 2];
//    int heapSize = 0;
//    emplace(heap, &heapSize, 0, 0, 0);
//    //printf("%d %d %d %d", heap[0].wt, heap[0].x, heap[0].y, heapSize);
//    while (true)
//    {
//        // print(heap, heapSize);
//        int wt = heap[0].wt;
//        int x = heap[0].x;
//        int y = heap[0].y;
//        pop(heap, &heapSize);
//        if (x == n - 1 && y == m - 1)
//            return wt;
//
//        //printf("%d %d %d %d\n", wt, x, y, heapSize);
//        if (wt > dis[x][y])
//            continue;
//
//        int time = (x + y) % 2 + 1;
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dir[i][0];
//            int my = y + dir[i][1];
//            if (mx >= 0 && mx < n && my >= 0 && my < m)
//            {
//                int new_dis = fmax(wt, moveTime[mx][my]) + time;
//                if (new_dis < dis[mx][my])
//                {
//                    dis[mx][my] = new_dis;
//                    //printf("%d %d %d\n", new_dis, mx, my);
//                    emplace(heap, &heapSize, new_dis, mx, my);
//                }
//            }
//        }
//        //print(heap, heapSize);
//        //printf("\n");
//    }
//    return 0;
//}
//
////3341. 到达最后一个房间的最少时间 I    
//
//typedef struct
//{
//    int d;
//    int x;
//    int y;
//}Node;
//void overWrite(Node* a, Node* b)
//{
//    (*a).d = (*b).d;
//    (*a).x = (*b).x;
//    (*a).y = (*b).y;
//}
//void up(Node heap[], int i)
//{
//    Node tmp = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j].d <= tmp.d)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void down(Node heap[], int i, int n)
//{
//    Node tmp = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1].d < heap[j].d)
//            j++;
//        if (heap[j].d >= tmp.d)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void emplace(Node heap[], int* n, int d, int x, int y)
//{
//    heap[*n].d = d;
//    heap[*n].x = x;
//    heap[*n].y = y;
//    up(heap, (*n)++);
//}
//void pop(Node heap[], int* n)
//{
//    overWrite(&heap[0], &heap[--(*n)]);
//    down(heap, 0, *n);
//}
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize)
//{
//    int n = moveTimeSize, m = moveTimeColSize[0];
//    int dis[n][m];
//    memset(dis, 0x3f, sizeof(dis));
//    dis[0][0] = 0;
//
//    Node heap[m * n * 2];
//    int heapSize = 0;
//    emplace(heap, &heapSize, 0, 0, 0);
//    while (1)
//    {
//        int d = heap[0].d, x = heap[0].x, y = heap[0].y;
//        pop(heap, &heapSize);
//
//        if (x == n - 1 && y == m - 1)
//            return d;
//
//        if (d > dis[x][y])
//            continue;
//
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dir[i][0];
//            int my = y + dir[i][1];
//            if (mx >= 0 && mx < n && my >= 0 && my < m)
//            {
//                int new_dis = fmax(d, moveTime[mx][my]) + 1;
//                if (new_dis < dis[mx][my])
//                {
//                    dis[mx][my] = new_dis;
//                    emplace(heap, &heapSize, new_dis, mx, my);
//                }
//            }
//        }
//    }
//    return 0;
//}
//
////3112. 访问消失节点的最少时间
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct Node
//{
//    int wt;
//    int x;
//    struct Node* next;
//}Node;
//typedef struct
//{
//    int wt;
//    int x;
//}PriorQueue;
//void append(Node** gridX, int y, int wt)
//{
//    Node* new = (Node*)malloc(sizeof(Node));
//    new->wt = wt;
//    new->x = y;
//    new->next = *gridX;
//    *gridX = new;
//}
//void overWrite(PriorQueue* a, PriorQueue* b)
//{
//    (*a).wt = (*b).wt;
//    (*a).x = (*b).x;
//}
//void up(PriorQueue heap[], int i)
//{
//    PriorQueue tmp = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j].wt <= tmp.wt)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//        if (j == 0)
//            break;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void down(PriorQueue heap[], int i, int n)
//{
//    PriorQueue tmp = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1].wt < heap[j].wt)
//            j++;
//        if (heap[j].wt >= tmp.wt)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void emplace(PriorQueue heap[], int* n, int wt, int x)
//{
//    heap[*n].wt = wt;
//    heap[*n].x = x;
//    up(heap, (*n)++);
//}
//void pop(PriorQueue heap[], int* n)
//{
//    overWrite(&heap[0], &heap[--(*n)]);
//    down(heap, 0, *n);
//}
//int* minimumTime(int n, int** edges, int edgesSize, int* edgesColSize, int* disappear, int disappearSize, int* returnSize)
//{
//    *returnSize = n;
//    Node* grid[n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1], wt = edges[i][2];
//        append(&grid[x], y, wt);
//        append(&grid[y], x, wt);
//    }
//    int* dis = (int*)malloc(sizeof(int) * n);
//    memset(dis, -1, sizeof(int) * n);
//    dis[0] = 0;
//    PriorQueue heap[n * 3];
//    int heapSize = 0;
//    emplace(heap, &heapSize, 0, 0);
//    while (heapSize > 0)
//    {
//        int x = heap[0].x, wt = heap[0].wt;
//        pop(heap, &heapSize);
//        if (wt > dis[x])
//            continue;
//
//        for (Node* cur = grid[x]; cur != NULL; cur = cur->next)
//        {
//            int y = cur->x;
//            int new_dis = wt + cur->wt;
//            if (new_dis < disappear[y] && (dis[y] < 0 || new_dis < dis[y]))
//            {
//                dis[y] = new_dis;
//                emplace(heap, &heapSize, new_dis, y);
//            }
//        }
//    }
//    return dis;
//}
//
////3604. 有向图中到达终点的最少时间
//
//struct Node
//{
//    int x;
//    int start;
//    int end;
//    struct Node* next;
//};
//typedef struct
//{
//    int x;
//    int t;
//}PriorQueue;
//void append(struct Node** gridX, int y, int start, int end)
//{
//    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
//    cur->x = y;
//    cur->start = start;
//    cur->end = end;
//    cur->next = *gridX;
//    *gridX = cur;
//}
//void overWrite(PriorQueue* a, PriorQueue* b)
//{
//    (*a).x = (*b).x;
//    (*a).t = (*b).t;
//}
//void up(PriorQueue heap[], int i)
//{
//    PriorQueue tmp = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j].t <= tmp.t)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//        if (j == 0)
//            break;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void down(PriorQueue heap[], int i, int n)
//{
//    PriorQueue tmp = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1].t < heap[j].t)
//            j++;
//        if (heap[j].t >= tmp.t)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void emplace(PriorQueue heap[], int* n, int x, int t)
//{
//    heap[*n].x = x;
//    heap[*n].t = t;
//    up(heap, (*n)++);
//}
//void pop(PriorQueue heap[], int* n)
//{
//    overWrite(&heap[0], &heap[--(*n)]);
//    down(heap, 0, *n);
//}
//int minTime(int n, int** edges, int edgesSize, int* edgesColSize)
//{
//    struct Node* grid[n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        int start = edges[i][2], end = edges[i][3];
//        append(&grid[x], y, start, end);
//    }
//
//    const int INF = 0x3f3f3f3f;
//    int dis[n];
//    memset(dis, 0x3f, sizeof(dis));
//    dis[0] = 0;
//    PriorQueue heap[n * 3];
//    int heapSize = 0;
//    emplace(heap, &heapSize, 0, 0);
//    while (heapSize)
//    {
//        int x = heap[0].x, t = heap[0].t;
//        pop(heap, &heapSize);
//        if (t > dis[x])
//            continue;
//
//        for (struct Node* cur = grid[x]; cur != NULL; cur = cur->next)
//        {
//            int y = cur->x;
//            int new_dis = fmax(cur->start, t) + 1;
//            if (new_dis <= cur->end + 1 && new_dis < dis[y])
//            {
//                dis[y] = new_dis;
//                emplace(heap, &heapSize, y, new_dis);
//            }
//        }
//    }
//    return dis[n - 1] == INF ? -1 : dis[n - 1];
//}
//
