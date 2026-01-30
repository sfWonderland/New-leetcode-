////1514. 概率最大的路径
//
//struct Node
//{
//    int x;
//    double val;
//    struct Node* next;
//};
//typedef struct
//{
//    int x;
//    double val;
//}PriorQueue;
//void overWrite(PriorQueue* a, PriorQueue* b)
//{
//    a->x = b->x;
//    a->val = b->val;
//}
//void up(PriorQueue heap[], int i)
//{
//    PriorQueue tmp = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j].val >= tmp.val)
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
//        if (j < n - 1 && heap[j + 1].val > heap[j].val)
//            j++;
//        if (heap[j].val <= tmp.val)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void emplace(PriorQueue heap[], int* n, int x, double val)
//{
//    heap[*n].x = x;
//    heap[*n].val = val;
//    up(heap, (*n)++);
//}
//void pop(PriorQueue heap[], int* n)
//{
//    overWrite(&heap[0], &heap[--(*n)]);
//    down(heap, 0, *n);
//}
//void append(struct Node** gridX, int y, double val)
//{
//    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
//    new->x = y;
//    new->val = val;
//    new->next = *gridX;
//    *gridX = new;
//}
//double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start_node, int end_node)
//{
//    struct Node* grid[n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        double val = succProb[i];
//        append(&grid[x], y, val);
//        append(&grid[y], x, val);
//    }
//
//    double suc[n];
//    memset(suc, 0, sizeof(suc));
//    PriorQueue heap[n * 3];
//    int heapSize = 0;
//    emplace(heap, &heapSize, start_node, 1);
//    while (heapSize)
//    {
//        int x = heap[0].x;
//        double val = heap[0].val;
//        pop(heap, &heapSize);
//        if (val < suc[x])
//            continue;
//
//        for (struct Node* cur = grid[x]; cur != NULL; cur = cur->next)
//        {
//            int y = cur->x;
//            double new_val = cur->val * val;
//            if (new_val > suc[y])
//            {
//                suc[y] = new_val;
//                emplace(heap, &heapSize, y, new_val);
//            }
//        }
//    }
//    return suc[end_node];
//}
//
////3650. 边反转的最小路径总成本    
//
//struct Node
//{
//    int x;
//    int val;
//    struct Node* next;
//};
//typedef struct
//{
//    int x;
//    int val;
//}PriorQueue;
//void overWrite(PriorQueue* a, PriorQueue* b)
//{
//    a->x = b->x;
//    a->val = b->val;
//}
//void up(PriorQueue heap[], int i)
//{
//    PriorQueue tmp = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j].val <= tmp.val)
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
//        if (j < n - 1 && heap[j + 1].val < heap[j].val)
//            j++;
//        if (heap[j].val >= tmp.val)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void emplace(PriorQueue heap[], int* n, int x, int val)
//{
//    heap[*n].x = x;
//    heap[*n].val = val;
//    up(heap, (*n)++);
//}
//void pop(PriorQueue heap[], int* n)
//{
//    overWrite(&heap[0], &heap[--(*n)]);
//    down(heap, 0, *n);
//}
//void append(struct Node** gridX, int y, int val)
//{
//    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
//    new->x = y;
//    new->val = val;
//    new->next = *gridX;
//    *gridX = new;
//}
//int minCost(int n, int** edges, int edgesSize, int* edgesColSize)
//{
//    struct Node* grid[n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1], val = edges[i][2];
//        append(&grid[x], y, val);
//        append(&grid[y], x, 2 * val);
//    }
//
//    const int INF = 0x3f3f3f3f;
//    int dis[n];
//    memset(dis, 0x3f, sizeof(dis));
//    PriorQueue heap[n * 3];
//    int heapSize = 0;
//    emplace(heap, &heapSize, 0, 0);
//    while (heapSize)
//    {
//        int x = heap[0].x;
//        int val = heap[0].val;
//        pop(heap, &heapSize);
//        if (val > dis[x])
//            continue;
//
//        for (struct Node* cur = grid[x]; cur != NULL; cur = cur->next)
//        {
//            int y = cur->x;
//            int new_val = cur->val + val;
//            if (new_val < dis[y])
//            {
//                dis[y] = new_val;
//                emplace(heap, &heapSize, y, new_val);
//            }
//        }
//    }
//    return dis[n - 1] < INF ? dis[n - 1] : -1;
//}
//
////1631. 最小体力消耗路径
//
//typedef struct
//{
//    int x;
//    int y;
//    int val;
//}PriorQueue;
//void overWrite(PriorQueue* a, PriorQueue* b)
//{
//    a->x = b->x;
//    a->y = b->y;
//    a->val = b->val;
//}
//void up(PriorQueue heap[], int i)
//{
//    PriorQueue tmp = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j].val <= tmp.val)
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
//        if (j < n - 1 && heap[j + 1].val < heap[j].val)
//            j++;
//        if (heap[j].val >= tmp.val)
//            break;
//
//        overWrite(&heap[i], &heap[j]);
//        i = j;
//    }
//    overWrite(&heap[i], &tmp);
//}
//void emplace(PriorQueue heap[], int* n, int x, int y, int val)
//{
//    heap[*n].x = x;
//    heap[*n].y = y;
//    heap[*n].val = val;
//    up(heap, (*n)++);
//}
//void pop(PriorQueue heap[], int* n)
//{
//    overWrite(&heap[0], &heap[--(*n)]);
//    down(heap, 0, *n);
//}
//const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize)
//{
//    int n = heightsSize, m = heightsColSize[0];
//    const int INF = 0x3f3f3f3f;
//    int dis[n][m];
//    memset(dis, 0x3f, sizeof(dis));
//    dis[0][0] = 0;
//    PriorQueue heap[n * m * 3];
//    int heapSize = 0;
//    emplace(heap, &heapSize, 0, 0, 0);
//    while (heapSize)
//    {
//        int x = heap[0].x;
//        int y = heap[0].y;
//        int val = heap[0].val;
//        pop(heap, &heapSize);
//        if (val > dis[x][y])
//            continue;
//
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dir[i][0];
//            int my = y + dir[i][1];
//            if (mx >= 0 && mx < n && my >= 0 && my < m)
//            {
//                int new_val = fmax(abs(heights[mx][my] - heights[x][y]), val);
//                if (new_val < dis[mx][my])
//                {
//                    dis[mx][my] = new_val;
//                    emplace(heap, &heapSize, mx, my, new_val);
//                }
//            }
//        }
//    }
//    return dis[n - 1][m - 1];
//}
//
////1129. 颜色交替的最短路径
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void append(struct ListNode** gridX, int y)
//{
//    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
//    new->val = y;
//    new->next = *gridX;
//    *gridX = new;
//}
//int* shortestAlternatingPaths(int n, int** redEdges, int redEdgesSize, int* redEdgesColSize, int** blueEdges, int blueEdgesSize, int* blueEdgesColSize, int* returnSize)
//{
//    struct ListNode* grid[2][n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < redEdgesSize; i++)
//    {
//        int x = redEdges[i][0], y = redEdges[i][1];
//        append(&grid[0][x], y);
//    }
//    for (int i = 0; i < blueEdgesSize; i++)
//    {
//        int x = blueEdges[i][0], y = blueEdges[i][1];
//        append(&grid[1][x], y);
//    }
//
//    int queue[n * 10][2];
//    int front = 0, rear = 0;
//
//    queue[rear][0] = 0;
//    queue[rear++][1] = 0;
//
//    queue[rear][0] = 0;
//    queue[rear++][1] = 1;
//
//    bool vis[n][2];
//    memset(vis, 0, sizeof(vis));
//
//    int* ans = (int*)malloc(sizeof(int) * n);
//    memset(ans, -1, sizeof(int) * n);
//
//    int depth = 0;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int x = queue[i][0], c = queue[i][1];
//            if (ans[x] == -1)
//                ans[x] = depth;
//
//            vis[x][c] = true;
//            c ^= 1;
//            for (struct ListNode* cur = grid[c][x]; cur != NULL; cur = cur->next)
//            {
//                int y = cur->val;
//                if (!vis[y][c])
//                {
//                    queue[rear][0] = y;
//                    queue[rear++][1] = c;
//                }
//            }
//        }
//        ++depth;
//    }
//    *returnSize = n;
//    return ans;
//}
//
