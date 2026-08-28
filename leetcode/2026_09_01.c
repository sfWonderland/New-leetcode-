//// 3568. 清理教室的最少移动
//
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//typedef struct
//{
//    int x, y, e, mask;
//}Node;
//
//int minMoves(char** classroom, int classroomSize, int energy)
//{
//    int m = classroomSize, n = strlen(classroom[0]);
//    int idx[m][n];
//    memset(idx, 0, sizeof(idx));
//    int sx = 0, sy = 0, cnt_l = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (classroom[i][j] == 'S')
//            {
//                sx = i;
//                sy = j;
//            }
//            else if (classroom[i][j] == 'L')
//                idx[i][j] = 1 << cnt_l++;
//        }
//    }
//
//    int u = 1 << cnt_l;
//    bool vis[m][n][energy + 1][u];
//    memset(vis, 0, sizeof(vis));
//    vis[sx][sy][energy][0] = true;
//    int capacity = 16;
//    Node* q = (Node*)malloc(sizeof(Node) * capacity);
//    int rear = 0, front = 0;
//    q[rear].x = sx;
//    q[rear].y = sy;
//    q[rear].e = energy;
//    q[rear++].mask = 0;
//    int ans = 0;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int x = q[i].x, y = q[i].y;
//            int e = q[i].e, mask = q[i].mask;
//            if (mask == u - 1)
//                return ans;
//            if (e == 0)
//                continue;
//
//            for (int k = 0; k < 4; k++)
//            {
//                int mx = x + dir[k][0];
//                int my = y + dir[k][1];
//                if (mx >= 0 && mx < m && my >= 0 && my < n && classroom[mx][my] != 'X')
//                {
//                    int new_e = classroom[mx][my] == 'R' ? energy : e - 1;
//                    int new_mask = mask | idx[mx][my];
//                    if (!vis[mx][my][new_e][new_mask])
//                    {
//                        vis[mx][my][new_e][new_mask] = true;
//                        q[rear].x = mx;
//                        q[rear].y = my;
//                        q[rear].e = new_e;
//                        q[rear++].mask = new_mask;
//                        if (rear == capacity)
//                        {
//                            capacity *= 2;
//                            q = (Node*)realloc(q, sizeof(Node) * capacity);
//                        }
//                    }
//                }
//            }
//        }
//        ans++;
//    }
//    return -1;
//}
//
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//typedef struct
//{
//    int x, y, e, mask;
//}Node;
//
//int minMoves(char** classroom, int classroomSize, int energy)
//{
//    int m = classroomSize, n = strlen(classroom[0]);
//    int idx[m][n];
//    memset(idx, 0, sizeof(idx));
//    int sx = 0, sy = 0, cnt_l = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (classroom[i][j] == 'S')
//            {
//                sx = i;
//                sy = j;
//            }
//            else if (classroom[i][j] == 'L')
//                idx[i][j] = 1 << cnt_l++;
//        }
//    }
//
//    int u = 1 << cnt_l;
//    int maxEnergy[m][n][u];
//    memset(maxEnergy, 0xff, sizeof(maxEnergy));
//    maxEnergy[sx][sy][0] = energy;
//    int capacity = 16;
//    Node* q = (Node*)malloc(sizeof(Node) * capacity);
//    int rear = 0, front = 0;
//    q[rear].x = sx;
//    q[rear].y = sy;
//    q[rear].e = energy;
//    q[rear++].mask = 0;
//    int ans = 0;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int x = q[i].x, y = q[i].y;
//            int e = q[i].e, mask = q[i].mask;
//            if (mask == u - 1)
//                return ans;
//            if (e == 0)
//                continue;
//
//            for (int k = 0; k < 4; k++)
//            {
//                int mx = x + dir[k][0];
//                int my = y + dir[k][1];
//                if (mx >= 0 && mx < m && my >= 0 && my < n && classroom[mx][my] != 'X')
//                {
//                    int new_e = classroom[mx][my] == 'R' ? energy : e - 1;
//                    int new_mask = mask | idx[mx][my];
//                    if (new_e > maxEnergy[mx][my][new_mask])
//                    {
//                        maxEnergy[mx][my][new_mask] = new_e;
//                        q[rear].x = mx;
//                        q[rear].y = my;
//                        q[rear].e = new_e;
//                        q[rear++].mask = new_mask;
//                        if (rear == capacity)
//                        {
//                            capacity *= 2;
//                            q = (Node*)realloc(q, sizeof(Node) * capacity);
//                        }
//                    }
//                }
//            }
//        }
//        ans++;
//    }
//    return -1;
//}
//
