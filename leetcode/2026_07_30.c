//// 2998. 使 X 和 Y 相等的最少操作次数
//
//int minimumOperationsToMakeEqual(int x, int y)
//{
//    if (x <= y) return y - x;
//
//    int ans = x - y;
//    bool vis[x + ans + 1]; // +1次数最多ans次，不可能比全-1得到y次数还多了
//    memset(vis, 0, sizeof(vis));
//    int capacity = 8;
//    int* queue = (int*)malloc(sizeof(int) * capacity);
//    int rear = 0, front = 0, step = 0;
//    void add(int v)
//    {
//        if (v < y)
//            ans = fmin(ans, step + y - v);
//        else if (!vis[v])
//        {
//            vis[v] = true;
//            queue[rear++] = v;
//            if (rear >= capacity)
//            {
//                capacity *= 2;
//                queue = (int*)realloc(queue, sizeof(int) * capacity);
//            }
//        }
//    }
//    add(x);
//    while (rear > front)
//    {
//        step++;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int v = queue[i];
//            if (v == y)
//            {
//                free(queue);
//                return fmin(ans, step - 1);
//            }
//            if (v % 11 == 0)
//                add(v / 11);
//            if (v % 5 == 0)
//                add(v / 5);
//
//            add(v - 1);
//            if (v < x + ans + 1)
//                add(v + 1);
//        }
//    }
//    return ans;
//}
//
//int minimumOperationsToMakeEqual(int x, int y)
//{
//    if (x <= y) return y - x;
//
//    int ans = x - y;
//    ans = fmin(ans, minimumOperationsToMakeEqual(x / 11, y) + x % 11 + 1);
//    ans = fmin(ans, minimumOperationsToMakeEqual(x / 11 + 1, y) + 11 - x % 11 + 1);
//    ans = fmin(ans, minimumOperationsToMakeEqual(x / 5, y) + x % 5 + 1);
//    ans = fmin(ans, minimumOperationsToMakeEqual(x / 5 + 1, y) + 5 - x % 5 + 1);
//    return ans;
//}
//
